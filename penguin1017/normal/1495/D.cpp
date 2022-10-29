#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for (int i=1;i<=n;i++)
#define REP(i,a,b) for (int i=a;i<=b;i++)
  
#define pb push_back
#define fi first
#define se second
#define pi pair<int,int>
#define mp make_pair
  
typedef long long ll;
typedef complex<double> comp;
  
const int inf=0x3f3f3f3f;
const ll linf=1e18;
const int N=700;
const double eps=1e-10;
const ll mo=998244353;
 
int n,m;
vector<int> g[N];
int e[N][2];
int d[N][N];
int f[N];
queue<int> q;
ll ans[N][N];
int main() {
  
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>n>>m;
    FOR(i,m) {
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
        e[i][0]=x,e[i][1]=y;
    }
    memset(d,0x3f,sizeof(d));
    FOR(i,n) {
        while (!q.empty()) q.pop();
        q.push(i);
        d[i][i]=0;
        while (!q.empty()) {
            int t=q.front();
            q.pop();
            for (auto &u:g[t]) {
                if (d[i][u]>d[i][t]+1) {
                    d[i][u]=d[i][t]+1;
                    q.push(u);
                }
            }
        }
    }
    FOR(i,n) FOR(j,n) {
        FOR(k,n) f[k]=0;
        int cnt=0;
        FOR(k,n) if (d[k][i]+d[k][j]==d[i][j]) cnt++;
        if (cnt>d[i][j]+1) continue;
        FOR(l,m) {
            int a=e[l][0],b=e[l][1];
            if (d[a][i]==d[b][i]+1&&d[a][j]==d[b][j]+1) ++f[a];
            swap(a,b);
            if (d[a][i]==d[b][i]+1&&d[a][j]==d[b][j]+1) ++f[a];
        }
        ll res=1;
        FOR(k,n) if (d[k][i]+d[k][j]!=d[i][j]) res=(res*f[k])%mo;
        ans[i][j]=res;
    }
    FOR(i,n) {
        FOR(j,n) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}