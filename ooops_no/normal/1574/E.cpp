#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int MOD = 998244353, N = 1e6 + 10;
vector<vector<int>> row(N, vector<int>(2)), col(N, vector<int>(2));
int bad_row, bad_col, good_col, good_row;

int add(int a, int b){
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int sub(int a, int b){
    a -= b;
    if (a < 0) a += MOD;
    return a;
}

int mul(int a, int b){
    return (a * b % MOD);
}

void func(int x, int y, int add){
    if (!row[x][0] && !row[x][1]){
        good_row += add;
    }
    if (row[x][0] && row[x][1]){
        bad_row += add;
    }
    if (!col[y][0] && !col[y][1]){
        good_col += add;
    }
    if (col[y][0] && col[y][1]){
        bad_col += add;
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> po(N, 1), kek(2);
    for (int i = 1; i < N; i++){
        po[i] = mul(po[i - 1], 2);
    }
    bad_row = 0, bad_col = 0, good_row = n, good_col = m;
    set<pair<int,int>> st;
    map<pair<int,int>, int> val;
    for (int i = 0; i < k; i++){
        int x, y, t;
        cin >> x >> y >> t;
        x--, y--;
        if (st.find({x, y}) != st.end()){
            st.erase({x, y});
            func(x, y, -1);
            row[x][(y + val[{x, y}]) & 1]++;
            col[y][(x + val[{x, y}]) & 1]++;
            func(x, y, 1);
            kek[(x + y + val[{x, y}]) & 1]++;
        }
        if (t != -1){
            st.insert({x, y});
            val[{x, y}] = t;
            func(x, y, -1);
            row[x][(y + val[{x, y}]) & 1]--;
            col[y][(x + val[{x, y}]) & 1]--;
            func(x, y, 1);
            kek[(x + y + val[{x, y}]) & 1]--;
        }
        int ans = 0;
        if (!bad_row){
            ans = add(ans, po[good_row]);
        }
        if (!bad_col){
            ans = add(ans, po[good_col]);
        }
        ans = sub(ans, (kek[0] == 0) + (kek[1] == 0));
        cout << ans << endl;
    }
    return 0;
}