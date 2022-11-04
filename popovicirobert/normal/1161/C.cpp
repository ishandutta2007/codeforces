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
    int n, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <int> a(n);
    for(i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int cnt = 1;

    while(a[n / 2] > 0) {
        cnt++;
        for(i = n / 2; i < n; i++) {
            if(a[i] > a[0]) {
                a[i] = a[0];
            }
            else {
                a[i] = a[0] - 1;
            }
        }
        sort(a.begin(), a.end());
    }

    cout << (cnt % 2 ? "Bob" : "Alice");

    return 0;
}