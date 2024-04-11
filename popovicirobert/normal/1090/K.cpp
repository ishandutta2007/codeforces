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
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <string> s(n);
    vector <int> t(n), pos(n);

    for(i = 0; i < n; i++) {
        string str;
        cin >> s[i] >> str;
        for(auto it : str) {
            t[i] |= (1 << (it - 'a'));
        }
        int p = (int)s[i].size() - 1;
        while(p >= 0 && (t[i] & (1 << (s[i][p] - 'a'))) > 0) {
            p--;
        }
        s[i].resize(p + 1);
    }

    vector <int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](const int &x, const int &y) {
                if(t[x] == t[y]) return s[x] < s[y];
                return t[x] < t[y];
         });

    vector < vector <int> > sol;

    i = 0;
    while(i < n) {
        sol.push_back(vector <int>());

        int j = i;
        while(j < n && t[ord[i]] == t[ord[j]] && s[ord[i]] == s[ord[j]]) {
            sol.back().push_back(ord[j]);
            j++;
        }

        i = j;
    }

    cout << sol.size() << "\n";
    for(i = 0; i < sol.size(); i++) {
        cout << sol[i].size() << " ";
        for(auto it : sol[i]) {
            cout << it + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}