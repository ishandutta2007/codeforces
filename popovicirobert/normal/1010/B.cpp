#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 30;

int arr[MAXN + 1];

inline int ask(int x) {
    fflush(stdout);
    cout << x << "\n";
    int ans;
    cin >> ans;
    if(ans == 0) {
        exit(0);
    }
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int m, n, i;
    ios::sync_with_stdio(false);
    cin >> m >> n;
    for(i = 1; i <= n; i++) {
        arr[i] = ask(m);
    }
    int res = 0;
    int cur = 1;
    for(int step = 1 << 29; step; step >>= 1) {
        if(res + step <= m) {
            int ans = ask(res + step);
            if(arr[cur] == 1)
                ans *= -1;
            if(ans >= 0) {
                res += step;
            }
            cur++;
            if(cur == n + 1)
                cur = 1;
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}