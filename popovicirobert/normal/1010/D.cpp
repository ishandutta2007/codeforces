#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e6;

int son[MAXN + 1][2];
string str[MAXN + 1];

bool val[MAXN + 1];

void dfs(int nod) {
    int x = son[nod][0], y = son[nod][1];
    if(x > 0) {
        dfs(x);
    }
    if(y > 0) {
        dfs(y);
    }
    if(str[nod] == "AND") {
        val[nod] = (val[x] & val[y]);
    }
    else if(str[nod] == "OR") {
        val[nod] = (val[x] | val[y]);
    }
    else if(str[nod] == "XOR") {
        val[nod] = (val[x] ^ val[y]);
    }
    else if(str[nod] == "NOT") {
        val[nod] = (!val[x]);
    }
}

bool dp[MAXN + 1];

void dfs1(int nod, int par) {
    int x = son[par][0], y = son[par][1];
    if(x != nod) {
        swap(x, y);
    }
    if(str[par] == "AND") {
        if(val[par] != ((1 - val[x]) & val[y]))
            dp[nod] = dp[par];
    }
    else if(str[par] == "OR") {
        if(val[par] != ((1 - val[x]) | val[y]))
            dp[nod] = dp[par];
    }
    else if(str[par] == "XOR") {
        if(val[par] != ((1 - val[x]) ^ val[y]))
            dp[nod] = dp[par];
    }
    else if(str[par] == "NOT") {
        if(val[par] != val[x])
            dp[nod] = dp[par];
    }
    x = son[nod][0], y = son[nod][1];
    if(x > 0)
        dfs1(x, nod);
    if(y > 0)
        dfs1(y, nod);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> str[i];
        if(str[i] != "IN") {
            if(str[i] != "NOT") {
                cin >> son[i][0] >> son[i][1];
            }
            else {
                cin >> son[i][0];
            }
        }
        else {
            cin >> val[i];
        }
    }
    dfs(1);
    dp[1] = 1;
    if(son[1][0] > 0)
        dfs1(son[1][0], 1);
    if(son[1][1] > 0)
        dfs1(son[1][1], 1);
    for(i = 1; i <= n; i++) {
        if(son[i][0] + son[i][1] == 0)
            cout << (val[1] + dp[i]) % 2;
    }
    //cin.close();
    //cout.close();
    return 0;
}