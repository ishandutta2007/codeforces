#include <bits/stdc++.h>

using namespace std;

const long long LINF = (long long) 2e18 + 123;

int sgn(int x) {
    if (x == 0) {
        return 0;
    }
    return x < 0 ? -1 : 1;
}

struct Vect {
    long long x, y;

    Vect() : x(0), y(0) {}

    Vect(long long _x, long long _y) : x(_x), y(_y) {}

    Vect(const Vect &a, const Vect &b) : x(b.x - a.x), y(b.y - a.y) {}

    long long operator*(const Vect &b) const {
        return x * b.y - b.x * y;
    }
};

int get_half(const Vect &v) {
    if (v.x < 0 || (v.x == 0 && v.y >= 0)) {
        return 0;
    }
    return 1;
}

long long get_area(const Vect &a, const Vect &b, const Vect &c) {
    return Vect(a, b) * Vect(a, c);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    long long need;
    cin >> need;
    need *= 2;
    vector<Vect> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    sort(p.begin(), p.end(), [&] (const Vect &a, const Vect &b) {
        return make_pair(a.x, -a.y) < make_pair(b.x, -b.y);
    });

    vector<int> what(n), pos(n);
    for (int i = 0; i < n; i++) {
        what[i] = i;
        pos[i] = i;
    }

    vector<pair<int, int>> evs;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            evs.emplace_back(i, j);
        }
    }

    sort(evs.begin(), evs.end(), [&] (const pair<int, int> &a, const pair<int, int> &b) {
        Vect u(p[a.first], p[a.second]);
        Vect v(p[b.first], p[b.second]);
        if (get_half(u) != get_half(v)) {
            return get_half(u) < get_half(v);
        }
        return u * v > 0;
    });

    for (auto &ev : evs) {
        int a = ev.first;
        int b = ev.second;
        assert(abs(pos[a] - pos[b]) == 1);
        swap(what[pos[a]], what[pos[b]]);
        swap(pos[a], pos[b]);

        int left = -1;
        int right = n;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (get_area(p[a], p[b], p[what[mid]]) >= need) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (left != -1 && get_area(p[a], p[b], p[what[left]]) == need) {
            cout << "Yes\n";
            cout << p[a].x << " " << p[a].y << "\n";
            cout << p[b].x << " " << p[b].y << "\n";
            cout << p[what[left]].x << " " << p[what[left]].y << "\n";
            return 0;
        }
    }

    cout << "No\n";

    return 0;
}