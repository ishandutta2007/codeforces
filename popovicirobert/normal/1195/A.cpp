#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = (int) 1e9 + 7;

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void sub(int &x, int y) {
    x += MOD - y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}*/

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;

    vector <int> fr(k + 1);
    for(i = 1; i <= n; i++) {
        int x;
        cin >> x;
        fr[x]++;
    }

    int ans = 0, cnt = (n + 1) / 2;
    for(i = 1; i <= k; i++) {
        int mn = min(cnt, fr[i] / 2);
        ans += 2 * mn;
        cnt -= mn;
        fr[i] %= 2;
    }

    for(i = 1; i <= k; i++) {
        if(fr[i] == 1 && cnt > 0) {
            ans++;
            cnt--;
        }
    }

    cout << ans;

    return 0;
}