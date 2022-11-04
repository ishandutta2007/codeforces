#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXT = (int) 1e6;

int fr[MAXT + 1], arr[MAXT + 1];
int fr1[MAXT + 1], b;

inline bool check(int x, int y, int n, int m) {
    memset(fr1, 0, sizeof(fr1));
    int i, j;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            fr1[abs(i - x) + abs(j - y)]++;
        }
    }
    for(i = 0; i <= b; i++) {
        if(fr1[i] != fr[i])
            return 0;
    }
    return 1;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, t;
    ios::sync_with_stdio(false);
    cin >> t;
    b = 0;
    for(i = 1; i <= t; i++) {
        cin >> arr[i];
        b = max(b, arr[i]);
        fr[arr[i]]++;
    }
    int x = 1;
    for(i = 1; i <= b; i++) {
        if(fr[i] < 4 * i) {
            x = i;
            break;
        }
    }
    int d = 1;
    while(d * d <= t) {
        if(t % d == 0) {
            int n = d;
            int m = t / d;
            int y = n + m - b - x;
            for(i = 0; i < 2; i++) {
                if(n >= x && m >= y) {
                    if(check(x, y, n, m)) {
                        cout << n << " " << m << "\n";
                        cout << x << " " << y;
                        return 0;
                    }
                }
                swap(n, m);
            }
        }
        d++;
    }
    cout << -1;
    //cin.close();
    //cout.close();
    return 0;
}