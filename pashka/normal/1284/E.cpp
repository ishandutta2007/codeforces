#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

struct point {
    long x, y;

    point operator - (point b) {
        return {x - b.x, y - b.y};
    }

    long operator * (point b) {
        return x * b.y - y * b.x;
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<point> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;


    long res = 0;
    for (int i = 0; i < n; i++) {
//        cout << i << endl;
        vector<point> q;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            q.push_back(p[j] - p[i]);
        }
        sort(q.begin(), q.end(), [&](auto a, auto b) {
            int s1 = a.y > 0 || a.y == 0 && a.x > 0;
            int s2 = b.y > 0 || b.y == 0 && b.x > 0;
            if (s1 != s2) {
                return s1 < s2;
            }
            return a * b > 0;
        });

        res += (long) (n - 1) * (n - 2) * (n - 3) * (n - 4);

//        for (auto pp : q) {
//            cout << pp.x << "," << pp.y << " ";
//        }
//        cout << endl;

        int r = 0;
        for (int l = 0; l < n - 1; l++) {
            r = max(r, l + 1);
            point &ll = q[l];
            while (true) {
                point &rr = q[r % q.size()];
                if (ll * rr > 0) {
                    r++;
                } else {
                    break;
                }
            }
//            cout << l << " " << r << "\n";
            int k = r - l;
            if (k >= 4) {
                res -= (long) (k - 1) * (k - 2) * (k - 3) * 4;
            }
        }
//        cout << res << "\n";
    }
    cout << res / 24 << "\n";


    return 0;
}