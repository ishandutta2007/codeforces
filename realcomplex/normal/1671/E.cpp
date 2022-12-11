#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (1 << 18);
const int MOD = 998244353;

int go[N];
int ways[N];
vector<char> low[N];
char s[N];
int m;

void dfs(int u){
    ways[u] = 1;
    go[u] = -1;
    low[u].push_back(s[u]);
    if(u * 2 <= m){
        dfs(u * 2);
        dfs(u * 2 + 1);
        ways[u] = (ways[u * 2] * 1ll * ways[u * 2 + 1]) % MOD;
        vector<char> qa = low[u * 2];
        vector<char> qb = low[u * 2 + 1];
        if(qa != qb){
            ways[u] = (ways[u] * 2ll) % MOD;
            if(qa > qb){
                swap(qa, qb);
            }
        }
        for(auto x : qa)
            low[u].push_back(x);
        for(auto x : qb)
            low[u].push_back(x);
    }
}


int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    m = (1 << n) - 1;
    for(int i = 1; i <= m ; i ++ ){
        cin >> s[i];
    }
    dfs(1);
    cout << ways[1] << "\n";
    return 0;
}