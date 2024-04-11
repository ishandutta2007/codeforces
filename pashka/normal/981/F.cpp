#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L
#define PI 3.141592653589793238462643383279502884L

#define long long long int

using std::vector;
using std::map;
using std::set;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::cerr;

// @author: pashka

int main() {
    std::ios::sync_with_stdio(false);

    int n, L;
    cin >> n >> L;

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    vector<int> bb;
    for (int i = 0; i < n; i++) {
        bb.push_back(b[i] - L);
    }
    for (int i = 0; i < n; i++) {
        bb.push_back(b[i]);
    }
    for (int i = 0; i < n; i++) {
        bb.push_back(b[i] + L);
    }


    int l = -1;
    int r = L / 2;
    while (r > l + 1) {
        int d = (r + l) / 2;
        bool ok = true;
        vector<int> p(n + 1);
        for (int i = 0; i < n; i++) {
            int L, R;
            for (int q = 0; q < 2; q++) {
                int x = a[i];
                if (q == 0) x -= d; else x += d + 1;
                int ll = 0;
                int rr = bb.size();
                while (rr > ll + 1) {
                    int mm = (ll + rr) / 2;
                    if (bb[mm] < x) {
                        ll = mm;
                    } else {
                        rr = mm;
                    }
                }
                if (q == 0) {
                    L = rr;
                } else {
                    R = ll;
                }
            }
//            cout << d << " " << i << " " << L << " " << R << "\n";
            R++;
            if (R <= L) {
                ok = false;
                break;
            }
            if (R - L >= n) {
                p[n]++;
            } else {
                for (int j = -1; j < 4; j++) {
                    int LL = j * n + i;
                    int RR = (j + 1) * n + i;
                    LL = std::max(LL, L);
                    RR = std::min(RR, R);
                    LL -= j * n + i;
                    RR -= j * n + i;
                    if (RR > LL) {
//                        cout << "! " << LL << " " << RR << "\n";
                        p[RR]++;
                        p[LL]--;
                    }
                }
            }
        }
        if (!ok) {
            l = d;
            continue;
        }
        ok = false;
//        for (int i = 0; i <= n; i++) {
//            cout << p[i] << " ";
//        }
//        cout << "\n";
        for (int i = n; i > 0; i--) {
            if (p[i] == n) {
                ok = true;
                break;
            }
            p[i - 1] += p[i];
        }
        if (ok) {
            r = d;
        } else {
            l = d;
        }
    }

    cout << r << "\n";

    return 0;
}