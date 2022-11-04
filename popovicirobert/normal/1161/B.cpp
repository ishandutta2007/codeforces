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

const int B = 41;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    vector < vector <int> > arr(n + 1);

    for(i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        if(l > r) {
            swap(l, r);
        }
        arr[min(r - l, n - (r - l))].push_back(l);
        arr[min(r - l, n - (r - l))].push_back(r);

    }

    vector <ull> pw(n + 1, 1);
    for(i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * B;
    }

    vector <int> fr(n + 1);
    int cnt = 0;

    bool ans = 0;
    for(int len = 0; len <= n; len++) {
        if(arr[len].size() == 0) {
            continue;
        }

        cnt++;
        sort(arr[len].begin(), arr[len].end());

        vector <int> aux(1);
        for(i = 1; i < arr[len].size(); i++) {
            aux.push_back(arr[len][i] - arr[len][i - 1]);
        }
        aux.push_back(n - arr[len].back() + arr[len][0]);

        int sz = (int) aux.size() - 1;
        vector <ull> pref(sz + 1, 0), suff(sz + 2, 0);

        for(i = 1; i <= sz; i++) {
            pref[i] = pref[i - 1] * B + aux[i];
        }
        for(i = sz; i >= 1; i--) {
            suff[i] = suff[i + 1] + aux[i] * pw[sz - i];
        }

        bool ok = 0;
        int sum = 0;
        for(i = 2; i <= sz; i++) {
            sum += aux[i - 1];
            ull cur = suff[i] * pw[i - 1] + pref[i - 1];
            if(pref[sz] == cur) {
                fr[sum]++;
            }
        }
    }

    for(i = 1; i < n; i++) {
        if(fr[i] == cnt) {
            ans = 1;
        }
    }

    cout << (ans ? "Yes" : "No");

    return 0;
}