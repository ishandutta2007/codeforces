#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int



#if 0
const int MOD = (int) ;

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
}

inline int inv(int x) {
    return lgput(x, MOD - 2);
}
#endif

#if 0
int fact[], invfact[];

inline void prec(int n) {
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    invfact[n] = lgput(fact[n], MOD - 2);
    for(int i = n - 1; i >= 0; i--) {
        invfact[i] = (1LL * invfact[i + 1] * (i + 1)) % MOD;
    }
}

inline int comb(int n, int k) {
    if(n < k) return 0;
    return (1LL * fact[n] * (1LL * invfact[k] * invfact[n - k] % MOD)) % MOD;
}
#endif

using namespace std;




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string str;
    cin >> n >> k >> str;

    bool ok = 1;
    for(i = 0; i + k < n; i++) {
        if(str[i] != str[i + k]) {
            ok = 0;
        }
    }

    if(ok) {
        cout << str.size() << "\n" << str;
        return 0;
    }

    ok = 1;
    for(i = 0; i < n; i += k) {
        if(str.substr(0, k) > str.substr(i, min(n - i, k))) {
            break;
        }
        if(str.substr(0, k) < str.substr(i, min(n - i, k))) {
            ok = 0;
        }
    }

    if(ok) {
        cout << str.size() << "\n";
        for(i = 0; i < n; i++) {
            cout << str[i % k];
        }
        return 0;
    }

    vector <int> arr(k);
    for(i = 0; i < k; i++) {
        arr[i] = str[i] - '0';
    }
    reverse(arr.begin(), arr.end());

    i = 0;
    while(i < arr.size() && arr[i] == 9) {
        arr[i++] = 0;
    }

    int sz = n;
    if(i == arr.size()) {
        arr.push_back(1);
        sz++;
    }
    else {
        arr[i]++;
    }

    reverse(arr.begin(), arr.end());

    cout << sz << "\n";
    for(i = 0; i < sz; i++) {
        cout << arr[i % k];
    }

    return 0;
}