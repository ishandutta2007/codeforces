#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int MOD = 998244353;

int add(int a, int b){
    return a + b > MOD ? a + b - MOD : a + b;
}

int sub(int a, int b){
    return a - b < 0 ? a - b + MOD : a - b;
}

int mul(int a, int b){
    return (a * b % MOD);
}

int binpow(int a, int n){
    if (n == 0) return 1;
    if (n % 2 == 0){
        int g = binpow(a, n / 2);
        return mul(g, g);
    }
    else{
        return mul(binpow(a, n - 1), a);
    }
}

int inv(int b){
    return binpow(b, MOD - 2);
}

int divide(int a, int b){
    return mul(a, inv(b));
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    vector<pair<int, pair<int,int>>> u;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
            u.pb({a[i][j], {i, j}});
        }
    }
    int r, c, ans = 0, cnt = 0, sum = 0, sum_ii = 0, sum_jj = 0, sum_i = 0, sum_j = 0;
    cin >> r >> c;
    r--, c--;
    sort(u.begin(), u.end());
    vector<pair<int, pair<int,int>>> small;
    for (auto to : u){
        int s = to.second.first, f = to.second.second;
        while(cnt < small.size() && small[cnt].first < to.first){
            int i = small[cnt].second.first, j = small[cnt].second.second;
            sum = add(sum, b[i][j]);
            sum_i = add(sum_i, i);
            sum_j = add(sum_j, j);
            sum_ii = add(sum_ii, mul(i, i));
            sum_jj = add(sum_jj, mul(j, j));
            cnt++;
        }
        if (cnt > 0) {
            b[s][f] = add(b[s][f], divide(sum, cnt));
            b[s][f] = add(b[s][f], add(mul(f, f), mul(s, s)));
            b[s][f] = add(b[s][f], divide(add(sum_ii, sum_jj), cnt));
            b[s][f] = sub(b[s][f], divide(mul(2, mul(s, sum_i)), cnt));
            b[s][f] = sub(b[s][f], divide(mul(2, mul(f, sum_j)), cnt));
        }
        small.pb({to.first, {s, f}});
    }
    cout << b[r][c] << endl;
    return 0;
}