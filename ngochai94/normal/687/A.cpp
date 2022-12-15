#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int n,m,col[100005],u,v;
vector<int> adj[100005],a,b;
queue<int> q;

int main() {
    cin >> n >> m;
    while(m--) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    reset(col,-1);
    For(i,1,n+1) if(col[i]==-1) {
        q.push(i);
        col[i]=0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            if(col[cur]) a.pb(cur);
            else b.pb(cur);
            for(int nex:adj[cur]) {
                if(col[nex] == col[cur]) {
                    cout << -1;
                    return 0;
                } else if(col[nex] == -1) {
                    col[nex] = 1-col[cur];
                    q.push(nex);
                }
            }
        }
    }
    cout << a.size() << endl;
    for(int i:a) cout << i << ' ';
    cout << endl << b.size() << endl;
    for(int i:b) cout << i << ' ';
}