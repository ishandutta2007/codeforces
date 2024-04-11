#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L
#define PI 3.141592653589793238462643383279502884L

#define long long long int

using namespace std;

// @author: pashka

struct point {
    double x, y;

    double len() {
        return sqrt(x * x + y * y);
    };

    bool operator<(const point &right) const {
        if (x != right.x)
            return x < right.x;
        return y < right.y;
    }

    bool operator==(const point &right) const {
        return (x == right.x && y == right.y);
    }
};

bool can(vector<point> &p, double d, int m) {
    int n = p.size();
    vector<pair<double, double>> s(2 * n);
    for (int i = 0; i < n; i++) {
        if (p[i].len() < d)
            return false;
        double a = atan2(p[i].y, p[i].x);
        double da = acos(d / p[i].len());
        s[i] = {a - da, a + da};
    }
    for (int i = 0; i < n; i++) {
        while (s[i].second > 2 * PI) {
            s[i].first -= 2 * PI;
            s[i].second -= 2 * PI;
        }
        while (s[i].second < 0) {
            s[i].first += 2 * PI;
            s[i].second += 2 * PI;
        }
//        cout << s[i].first << " " << s[i].second << "\n";
    }
    for (int i = 0; i < n; i++) {
        s[n + i] = s[i];
        s[n + i].first += 2 * PI;
        s[n + i].second += 2 * PI;
    }
    vector<pair<double, pair<int, int>>> ss(2 * s.size());
    for (int i = 0; i < s.size(); i++) {
        ss[2 * i] = {s[i].first, {i, 0}};
        ss[2 * i + 1] = {s[i].second, {i, 1}};
    }
    sort(ss.begin(), ss.end());
    vector<int> nn(s.size());
    int next = -1;
    for (int i = ss.size() - 1; i >= 0; i--) {
//        cout << ss[i].first << ": " << ss[i].second.first << " " << ss[i].second.second << "\n";
        if (ss[i].second.second == 0) {
            if (next == -1 || s[next].second > s[ss[i].second.first].second) {
                next = ss[i].second.first;
            }
        } else {
            nn[ss[i].second.first] = next;
        }
    }
//    for (int i = 0; i < 2 * n; i++) {
//        cout << nn[i] << " ";
//    }
//    cout << "\n";
    vector<int> c(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        c[i] = i;
    }
    while (m > 0) {
        if (m % 2 == 1) {
            for (int i = 0; i < 2 * n; i++) {
                if (c[i] != -1) {
                    c[i] = nn[c[i]];
                }
            }
        }
        vector<int> nn2(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            if (nn[i] != -1) {
                nn2[i] = nn[nn[i]];
            } else {
                nn2[i] = -1;
            }
        }
        nn = nn2;
        m /= 2;
    }
    for (int i = 0; i < n; i++) {
//        cout << i << " " << c[i] << " " << s[i].second << " " << s[i].second  + 2 * PI << " " << s[c[i]].second << "\n";
        if (c[i] == -1 || c[i] == i + n || s[c[i]].second >= s[i].second + 2 * PI) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

//    cout << can(p, 3.6, m);
    double l = 0;
    double r = 1e9;
    for (int _ = 0; _ < 50; _++) {
//        cout << l << " " << r << "\n";
        double d = (l + r) / 2;
        bool z = can(p, d, m);
//        cout << setprecision(20) << d << " " << z << "\n";
        if (z) {
            l = d;
        } else {
            r = d;
        }
    }
    cout << setprecision(20) << l << "\n";

    return 0;
}