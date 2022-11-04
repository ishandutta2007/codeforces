#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int



#if 0
const int MOD = ;

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

    vector < pair <ll, ll> > fr;
    vector <ll> arr(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        ll pw = 2;
        while(arr[i] % pw == 0) {
            pw *= 2;
        }
        pw /= 2;
        fr.push_back({pw, arr[i]});
    }
    sort(fr.begin(), fr.end());

    vector <ll> cur;
    int mx = 0;
    i = 0;
    while(i < n) {
        int j = i;
        while(j < n && fr[j].first == fr[i].first) {
            j++;
        }
        if(mx < j - i) {
            cur.clear();
            mx = j - i;
            while(i < j) {
                cur.push_back(fr[i].second);
                i++;
            }
        }
        else {
            i = j;
        }
    }

    map <ll, bool> mp;
    cout << n - mx << "\n";
    for(auto it : cur) {
        mp[it] = 1;
    }
    for(i = 1; i <= n; i++) {
        if(mp[arr[i]] == 0) {
            cout << arr[i] << " ";
        }
    }

    return 0;
}