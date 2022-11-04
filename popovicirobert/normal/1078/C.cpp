#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MOD = 998244353;
const int MAXN = (int) 3e5;

vector <int> g[MAXN + 1];
int dp[MAXN + 1][3];
// [0] nodul nu e cuplat si nu trebuie neaparat cuplat
// [2] nodul nu e cuplat si trebuie cuplat
// [1] nodul e deja cuplat

void dfs(int nod, int par) {
    vector <int> nodes;
    for(auto it : g[nod]) {
        if(it != par) {
            dfs(it, nod);
            nodes.push_back(it);
        }
    }
    if(nodes.size() == 0) {
        dp[nod][0] = 1;
        return ;
    }
    vector <int> aux(3);
    aux[0] = 1;
    for(auto it : nodes) {
        vector <int> new_aux(3);
        new_aux[0] = (1LL * aux[0] * (dp[it][0] + dp[it][1])) % MOD;
        new_aux[1] = (1LL * aux[0] * (dp[it][0] + dp[it][2]) + 1LL * aux[2] * (dp[it][0] + dp[it][2]) + 2LL * aux[1] * dp[it][1] + 1LL * aux[1] * dp[it][0]) % MOD;
        new_aux[2] = (1LL * aux[0] * dp[it][1] + 2LL * aux[2] * dp[it][1] + 1LL * aux[2] * dp[it][0]) % MOD;
        //cerr << new_aux[0] << " " << new_aux[1] << " " << new_aux[2] << "\n";
        swap(aux, new_aux);
    }
    for(int i = 0; i < 3; i++) {
        dp[nod][i] = aux[i];
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    cout << (1LL * dp[1][0] + 1LL * dp[1][1]) % MOD;
    //cin.close();
    //cout.close();
    return 0;
}