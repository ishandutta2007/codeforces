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

const int BUCK = 300;

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string str;
    cin >> str;
    n = str.size(), str = " " + str;

    ll ans = 0;
    for(int r = 1; r < BUCK; r++) {
        static vector <int> arr(n + 1);
        int sum = 0;

        arr[0] = 0;
        for(i = 1; i <= n; i++) {
            sum += (str[i] == '1' ? r : 0) - 1;
            arr[i] = sum;
        }
        sort(arr.begin(), arr.end());

        i = 0;
        while(i <= n) {
            int j = i;
            while(j <= n && arr[i] == arr[j]) {
                j++;
            }
            ans += 1LL * (j - i - 1) * (j - i) / 2;
            i = j;
        }
    }

    // len / one < BUCK


    vector <int> nxt(n + 2, n + 1), ones(n + 1);
    for(i = 1; i <= n; i++) {
        ones[i] = ones[i - 1] + (str[i] == '1');
    }
    for(i = n; i >= 1; i--) {
        nxt[i] = (str[i] == '0' ? nxt[i + 1] : i);
    }

    for(int o = 1; o <= n / BUCK + 1; o++) {
        int j = 1;
        for(i = 0; i < n; i++) {
            while(j <= n && ones[j] - ones[i] < o) {
                j++;
            }
            if(j == n + 1) { break; }

            // len / one >= BUCK

            int pos = nxt[j + 1] - 1;
            ans += max(0, (pos - i) / o - (max(i + BUCK * o, j) - i - 1) / o);
        }
        //cerr << o << " " << ans << "\n";
    }

    cout << ans;

    return 0;
}