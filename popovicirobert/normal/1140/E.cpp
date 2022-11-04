#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MOD = 998244353;

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

vector < vector <ll> > dp;
// 0 a != b
// 1 a == b

inline int solve(vector <int> &arr, int k) {

    int n = arr.size();
    int ans = 1, i = 0;

    while(i < n && arr[i] == -1) {
        i++;
    }

    if(i == n) {
        return (1LL * lgput(k - 1, n - 1) * k) % MOD;
    }

    ans = lgput(k - 1, i);

    while(n > 0 && arr[n - 1] == -1) {
        ans = (1LL * ans * (k - 1)) % MOD;
        n--;
    }

    while(i < n) {
        int j = i + 1;

        while(j < n && arr[j] == -1) {
            j++;
        }

        ans = (1LL * ans * dp[j - i - 1][arr[i] == arr[j]]) % MOD;

        i = j;
    }

    return ans;

}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;

    vector <int> arr(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector < vector <ll> > aux(n + 1, vector <ll>(3));
    dp.resize(n + 1, vector <ll>(2));

    dp[0][0] = 1;

    ////////////////////////////////////////////////////////////////

    aux[1][1] = 1;
    aux[1][2] = k - 2;

    for(i = 2; i <= n; i++) {
        aux[i][0] = (aux[i - 1][1] + aux[i - 1][2]) % MOD;
        aux[i][1] = (aux[i - 1][0] + aux[i - 1][2]) % MOD;
        aux[i][2] = (1LL * (aux[i - 1][0] + aux[i - 1][1]) * (k - 2)) % MOD;
        if(k > 2) {
            aux[i][2] = (aux[i][2] + 1LL * (k - 3) * aux[i - 1][2]) % MOD;
        }
    }

    for(i = 1; i <= n; i++) {
        dp[i][0] = (aux[i][2] + aux[i][0]) % MOD;
    }

    /////////////////////////////////////////////////////////////////

    aux[1][2] = k - 1;

    for(i = 2; i <= n; i++) {
        aux[i][0] = aux[i - 1][2];
        aux[i][2] = (1LL * (k - 2) * aux[i - 1][2] + 1LL * (k - 1) * aux[i - 1][0]) % MOD;
    }

    for(i = 1; i <= n; i++) {
        dp[i][1] = aux[i][2];
    }

    int ans = 1;
    for(int r = 0; r < 2; r++) {
        vector <int> cur;
        for(i = 2 - r; i <= n; i += 2) {
            cur.push_back(arr[i]);
        }
        ans = (1LL * ans * solve(cur, k)) % MOD;
    }

    cout << ans;

    //cin.close();
    //cout.close();
    return 0;
}