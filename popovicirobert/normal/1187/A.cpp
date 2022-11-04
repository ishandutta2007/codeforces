#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = ;

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
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> T;

    while(T--) {
        int n, s, t;
        cin >> n >> s >> t;
        cout << max(s, t) - (s + t - n) + 1 << "\n";
    }

    //cin.close();
    //cout.close();
    return 0;
}