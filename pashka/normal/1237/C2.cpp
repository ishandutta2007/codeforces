#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

struct point {
    int x, y, z, id;
};

void solve2(vector<point> &p) {
    map<int, point> byz;
    for (auto &i : p) {
        byz[i.z] = i;
    }

    int c = 0;
    point last;

    for (auto &pp : byz) {
        if (c == 0) {
            last = pp.second;
        } else {
            cout << last.id << " " << pp.second.id << "\n";
        }
        c ^= 1;
    }
    p.clear();
    if (c == 1) {
        p.push_back(last);
    }
}


void solve1(vector<point> &p) {
    map<int, vector<point>> byy;
    for (auto &i : p) {
        byy[i.y].push_back(i);
    }

    int c = 0;
    point last;

    for (auto &pp : byy) {
        solve2(pp.second);
        if (!pp.second.empty()) {
            if (c == 0) {
                last = pp.second[0];
            } else {
                cout << last.id << " " << pp.second[0].id << "\n";
            }
            c ^= 1;
        }
    }
    p.clear();
    if (c == 1) {
        p.push_back(last);
    }
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y >> p[i].z;
        p[i].id = i + 1;
    }

    map<int, vector<point>> byx;
    for (int i = 0; i < n; i++) {
        byx[p[i].x].push_back(p[i]);
    }

    int c = 0;
    point last;

    for (auto &pp : byx) {
        solve1(pp.second);
        if (!pp.second.empty()) {
            if (c == 0) {
                last = pp.second[0];
            } else {
                cout << last.id << " " << pp.second[0].id << "\n";
            }
            c ^= 1;
        }
    }

    return 0;
}