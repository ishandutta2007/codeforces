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
    int i, n, p;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> p;

    vector < pair <int, int> > t(n);
    vector <int> T(n);

    for(i = 0; i < n; i++) {
        cin >> t[i].first;
        t[i].second = i;

        T[i] = t[i].first;
    }

    sort(t.begin(), t.end());

    vector <ll> sol(n);

    set <int> inQ, waiting;
    queue <int> Q;

    ll last = 0;
    int cnt = 0;

    i = 0;
    while(cnt < n) {
        if(Q.size() == 0 && waiting.size()) {
            Q.push(*waiting.begin());
            inQ.insert(*waiting.begin());
            waiting.erase(waiting.begin());
        }
        else {
            if(Q.size()) {
                last = max(last, 1LL * T[Q.front()]) + p;

                int j = i;
                while(j < n && last >= t[j].first) {
                    int pos = j;
                    while(pos < n && t[j].first == t[pos].first) {
                        waiting.insert(t[pos].second);
                        pos++;
                    }

                    if(inQ.empty() || *inQ.begin() > *waiting.begin()) {
                        Q.push(*waiting.begin());
                        inQ.insert(*waiting.begin());
                        waiting.erase(waiting.begin());
                    }

                    j = pos;
                }

                sol[Q.front()] = last;
                inQ.erase(Q.front());
                Q.pop(), cnt++;

                i = j;
            }
            else {
                int j = i;
                while(j < n && t[j].first == t[i].first) {
                    waiting.insert(t[j].second);
                    j++;
                }
                i = j;
            }
        }
    }

    for(i = 0; i < n; i++) {
        cout << sol[i] << " ";
    }

    return 0;
}