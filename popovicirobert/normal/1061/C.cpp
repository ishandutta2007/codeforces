#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 1e6;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

int sum[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, a;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    sum[0] = 1;
    for(i = 1; i <= n; i++) {
        cin >> a;
        int d = 1;
        while(d * d <= a) {
            if(a % d == 0) {
                sum[a / d] += sum[a / d - 1];
                mod(sum[a / d]);
            }
            d++;
        }
        while(d >= 1) {
            if(a % d == 0 && d * d < a) {
                sum[d] += sum[d - 1];
                mod(sum[d]);
            }
            d--;
        }
    }
    int ans = 0;
    for(i = 1; i <= n; i++) {
        ans += sum[i];
        mod(ans);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}