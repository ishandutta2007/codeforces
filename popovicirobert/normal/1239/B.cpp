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

    string str;
    cin >> n >> str;

    str = " " + str;

    vector <int> sp(n + 1);
    int mn = n + 1, pos;

    for(int i = 1; i <= n; i++) {
        sp[i] = sp[i - 1] + (str[i] == '(') - (str[i] == ')');
        if(mn > sp[i]) {
            pos = i;
            mn = sp[i];
        }
    }

    if(sp[n] != 0) {
        cout << "0\n1 1";
        return 0;
    }

    stack <int> stk;

    auto get = [&](int x) {
        if(x % n == 0) return n;
        return x % n;
    };

    vector < vector <int> > g(n + 1);
    vector <int> l(n + 1), r(n + 1);
    vector <int> lvl(n + 1, 0);

    pair <int, int> sol;
    int cnt = 0;

    for(i = pos + 1; i <= pos + n; i++) {
        if(str[get(i)] == '(') {
            if(stk.size()) {
                g[stk.top()].push_back(get(i));
                lvl[get(i)] = lvl[stk.top()] + 1;
            }
            else {
                cnt++;
            }
            stk.push(get(i));
        }
        else {
            l[stk.top()] = get(i);
            r[get(i)] = stk.top();
            stk.pop();
        }
    }

    int ans = cnt;
    sol = {1, 1};

    for(i = 1; i <= n; i++) {
        if(lvl[i] == 0 && str[i] == '(') {
            int cur = g[i].size() + 1;
            if(ans < cur) {
                ans = cur;
                sol = {l[i], r[l[i]]};
            }
        }
        if(lvl[i] == 1 && str[i] == '(') {
            int cur = cnt + g[i].size() + 1;
            if(ans < cur) {
                ans = cur;
                sol = {l[i], r[l[i]]};
            }

        }
    }

    cout << ans << "\n" << sol.first << " " << sol.second;

    return 0;
}