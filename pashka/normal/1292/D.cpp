#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

const int MAX = 5005;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(MAX);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a[k]++;
    }

    vector<int> p(MAX);

    for (int i = 2; i < MAX; i++) {
        if (p[i] == 0) {
            p[i] = i;
            for (int j = i + i; j < MAX; j += i) {
                if (p[j] == 0) p[j] = i;
            }
        }
    }

    vector<vector<int>> s(MAX, vector<int>(MAX));
    for (int i = 2; i < MAX; i++) {
        int x = i;
        while (x > 1) {
            s[i][p[x]]++;
            x /= p[x];
        }
        for (int j = 0; j < MAX; j++) {
            s[i][j] += s[i - 1][j];
        }
    }

    long res = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            res += (long)a[i] * s[i][j];
        }
    }

//    cerr << res << "\n";
    vector<int> c(MAX);
    int l = 0;
    int r = MAX;
    for (int j = MAX - 1; j >= 2; j--) {
        int xx = 0;
        int maxx = 0;
        int maxv = -1;
        for (int i = l; i < r; i++) {
            if (i == l || s[i][j] == s[i - 1][j]) {
                xx += a[i];
            } else {
                xx = a[i];
            }
            if (xx > maxx) {
                maxx = xx;
                maxv = s[i][j];
            }
        }
        if (maxx * 2 > n) {
            int cnt = 0;
            for (int q = l; q < r; q++) {
                cnt += a[q];
                if (s[q][j] < maxv) {
                    res += (long)(maxv - 2 * s[q][j]) * a[q];
                } else {
                    res -= (long)maxv * a[q];
                }
            }
            res += (long)(n - cnt) * maxv;
            while (s[l][j] != maxv) {
                l++;
            }
            while (s[r - 1][j] != maxv) {
                r--;
            }
//            cout << j << " " << maxx << " " << maxv << " " << l << " " << r << " " << res <<"\n";
        } else {
            xx = 0;
            for (int i = r - 1; i >= l; i--) {
                xx += a[i];
                if (xx * 2 >= n) {
                    int v = s[i][j];
                    int cnt = 0;
                    for (int q = l; q < r; q++) {
                        cnt += a[q];
                        if (s[q][j] < v) {
                            res += (long)(v - 2 * s[q][j]) * a[q];
                        } else {
                            res -= (long)v * a[q];
                        }
                    }
                    res += (long)(n - cnt) * v;
                    break;
                }
            }
            break;
        }
    }
    cout << res << "\n";

    return 0;
}