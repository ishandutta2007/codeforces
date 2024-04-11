#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=2e5+30,mod = 1e9+7,inf=1e9;
int p[N],vis[N];
vector <int> adj[N];
bool visited[N];
vector <pair<int,bool> > head;
bool comp(int v,int t,int par){
    vis[v] = t;
    bool f = 0;
    for (int u : adj[v]){
        if (!vis[u]){
            if (comp(u,t,v)) f = 1;
        }
        else if (u != par) f = 1;
    }
    return f;
}
pll dfs(int v,int par){
    visited[v] = 1;
    for (int u : adj[v]){
        if (!visited[u]){
            pll pa = dfs(u,v);
            if (pa.X != 0) return pa;
        }
        else if (u != par){
            return {u,v};
        }
    }
    return {0,0};

}
void merge(int i,int j){
    memset(visited,0,sizeof visited);
    pll pa;
    if (head[i].Y){
        pa = dfs(head[i].X,-1);
        if (pa.X == p[pa.Y]){
            p[pa.Y] = head[j].X;
            adj[pa.Y].pb(head[j].X);
            adj[head[j].X].pb(pa.Y);
        }
        else{
            p[pa.X] = head[j].X;
            adj[pa.X].pb(head[j].X);
            adj[head[j].X].pb(pa.X);
        }
        int si = adj[pa.X].size(),sj = adj[pa.Y].size(),ind=-1;
        rep(i,0,si){
            if (adj[pa.X][i] == pa.Y){
                ind = i;
                break;
            }
        }
        adj[pa.X].erase(adj[pa.X].begin()+ind);
        ind = -1;
        rep(i,0,sj){
            if (adj[pa.Y][i] == pa.X){
                ind = i;
                break;
            }
        }
        head[i].Y = 0;
        adj[pa.Y].erase(adj[pa.Y].begin()+ind);
    }
    else if (head[j].Y) {
        pa = dfs(head[j].X,-1);
        head[j].Y = 0;
        if (pa.X == p[pa.Y]){
            p[pa.Y] = head[i].X;
            adj[pa.Y].pb(head[i].X);
            adj[head[i].X].pb(pa.Y);
        }
        else{
            p[pa.X] = head[i].X;
            adj[pa.X].pb(head[i].X);
            adj[head[i].X].pb(pa.X);
        }
        int si = adj[pa.X].size(),sj = adj[pa.Y].size(),ind=-1;
        rep(i,0,si){
            if (adj[pa.X][i] == pa.Y){
                ind = i;
                break;
            }
        }
        adj[pa.X].erase(adj[pa.X].begin()+ind);
        ind = -1;
        rep(i,0,sj){
            if (adj[pa.Y][i] == pa.X){
                ind = i;
                break;
            }
        }
    //    debug(pa.X);debug(pa.Y);
        head[j].Y = 0;
        adj[pa.Y].erase(adj[pa.Y].begin()+ind);

    }
    else {
        p[head[j].X] = head[i].X;
        adj[head[i].X].pb(head[j].X);
        adj[head[j].X].pb(head[i].X);
    }

}
int main(){
    int n;
    cin >> n;
    rep (i,1,n+1){
        cin >> p[i];
        if (i != p[i]){
            adj[i].pb(p[i]);
            adj[p[i]].pb(i);
        }
    }
    int t = 0;
    int cnt=0;
    rep(i,1,n+1){
        if (!vis[i]){
            t++;
            bool cyc = comp(i,t,-1);
            head.pb({i,cyc});
        }
        if (p[i] == i){
            head[vis[i]-1].X = i;
            cnt++;
        }
    }
    if (n == 1234){
      // cout << cnt << ' '<< t;
       // return 0;
    }
    rep(i,1,t){
        merge(i-1,i);
    }
    bool f = 0;
    rep(i,1,n+1){
        if (i == p[i]) f = 1;
    }
  /*  if (n == 1234){
        t = 0;
        memset(vis,0,sizeof(vis));
        rep(i,1,n+1){
            if (!vis[i]){
                t++;
                bool cyc = comp(i,t,-1);
                head.pb({i,cyc});
            }   
            if (p[i] == i){
                head[vis[i]-1].X = i;
            }
        }
        cout << t;
        return 0;
    }*/
    memset(visited,0,sizeof visited);
    pll pa = dfs(1,-1);
    if (pa.X == 0){
        debug(t);
        cout << t-1 << endl;
        rep(i,1,n+1) cout << p[i] << ' ';
        return 0;
    }
    if (pa.X == p[pa.Y]) p[pa.Y] = pa.Y;
    else p[pa.X] = pa.X;
    cout << t << endl;
    rep(i,1,n+1) cout << p[i] << ' ';
}