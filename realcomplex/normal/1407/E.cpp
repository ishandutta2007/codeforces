#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 10;
set<pii> in[N];
set<int> al[N];
vector<int> T[N][2];
int col[N];
queue<pii> qq;

void setid(int x, int cc){
    if(col[x] != -1) return;
    col[x] = cc;
    for(auto p : T[x][cc]){
        al[p].insert(x);
    }
}

bool inq[N];

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    int u, v, c;
    for(int i = 1; i <= n; i ++ )
        col[i]=-1;
    for(int i = 0 ; i < m ; i ++ ){
        cin >> u >> v >> c;
        T[u][c].push_back(v);
        in[v].insert(mp(u, c));
    }

    qq.push(mp(0, n));
    inq[n] = true;
    int node;
    int dep;
    int sol = -1;
    while(!qq.empty()){
        node = qq.front().se;
        dep = qq.front().fi;
        qq.pop();
        if(node == 1){
            sol = dep;
            break;
        }
        for(auto y : in[node]){
            setid(y.fi, (y.se^1));
        }
        for(auto y : al[node]){
            if(inq[y]) continue;
            inq[y]=true;
            qq.push(mp(dep + 1, y));
        }
    }
    cout << sol << "\n";
    for(int i = 1; i <= n; i ++ ){
        if(col[i] == -1) col[i] = 0;
        cout << col[i];
    }
    cout << "\n";
    return 0;
}