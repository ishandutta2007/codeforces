#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--) 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define make_unique(x) { sort(all(x)); x.resize(unique(all(x))-x.begin()); }
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
mt19937 mrand(time(0));
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int inf=1<<30;
// head
const double eps=1e-12;
const int N=2e5+5; 
const int mod=1e9+7;

ll powmod(ll x,ll k) {
	ll res=1;
	for (;k;k>>=1,x=x*x%mod) if (k&1) res=res*x%mod;
	return res;
}       
ll gcd(ll a,ll b) { return !b?a:gcd(b,a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b%mod; } 

namespace Dinic {
    static const int M=1e6+5;//M
    int head[M],cur[M],tot;
    struct edge {int nxt,to,cap,flow;}w[M];
    
    void init() {tot=0; memset(head,-1,sizeof head);}//
    void add_edge(int x,int y,int cap) {
        w[tot]=(edge) {head[x],y,cap,0};
        head[x]=tot++;
        w[tot]=(edge) {head[y],x,0,0};
        head[y]=tot++;
    }
    int Q[N],dep[N];
    bool bfs(int S,int T) {
        memset(dep,0,sizeof dep);
        int l=0,r=0;
        dep[Q[r++]=S]=1;
        while (l<r) {
            int u=Q[l++];
            cur[u]=head[u];
            for (int i=head[u];~i;i=w[i].nxt) {
                edge e=w[i];
                if (e.cap>e.flow&&!dep[e.to]) {
                    dep[Q[r++]=e.to]=dep[u]+1;
                }
            }
        }
        return dep[T]>0;
    }
    int dfs(int u,int a,int T) {
        if (u==T||!a) return a;
        int flow=a;
        for (int &i=cur[u];~i;i=w[i].nxt) {
            edge e=w[i];
            if (dep[e.to]==dep[u]+1) {
                int f=dfs(e.to,min(flow,w[i].cap-w[i].flow),T);
                w[i].flow+=f,w[i^1].flow-=f;
                flow-=f;
                if (!flow) return a;
            }
        }
        return a-flow;
    }
    int solve(int S,int T) {//int
        int ans=0;
        while (bfs(S,T)) {
            ans+=dfs(S,inf,T);
        }
        return ans;
    }
}

int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Dinic::init();

    int n,m;
    int source,sink,mid;
    cin>>n>>m;

    vector<int> s(n),a(n,0),b(n);
    vector<pair<int,int>> ed(m);

    rep(i,0,n) cin>>s[i];
    rep(i,0,n) cin>>b[i];

    rep(i,0,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        a[u]--,a[v]++;

        ed[i]={u,v};
        Dinic::add_edge(u,v,1);
    }

    source=n,sink=n+1,mid=n+2;


    bool ok=true;
    int pos=0,neg=0;

    rep(i,0,n) if (s[i]) {
        if ((a[i]-b[i])&1) ok=false;
        int c=b[i]-a[i]; c/=2;

        // bug(i),(c);

        if (c>0) Dinic::add_edge(source,i,c),pos+=c;
        else Dinic::add_edge(i,sink,-c),neg-=c;
    }

    if (!ok) { cout << "NO" << endl; return 0; }
    // puts("!!!");


    rep(i,0,n) if (!s[i]) {
        Dinic::add_edge(i,mid,inf);
        Dinic::add_edge(mid,i,inf);
    }

    if (pos>neg) {
        Dinic::add_edge(mid,sink,pos-neg);
    }
    if (pos<neg) {
        Dinic::add_edge(source,mid,neg-pos);
    }

    Dinic::solve(source,sink);


    #define u first
    #define v second

    rep(i,0,m) {
        if (Dinic::w[i*2].flow==Dinic::w[i*2].cap) {
            a[ed[i].u]+=2,a[ed[i].v]-=2;
            swap(ed[i].u,ed[i].v);
        }
    }

    // i out a[i]


    // rep(i,0,n) cout << a[i] << ' ';
    // cout << endl;

    rep(i,0,n) if (s[i] && a[i]!=b[i]) ok=false;
    if (!ok) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        rep(i,0,m) {
            cout << ed[i].u+1 << ' ' << ed[i].v+1 << endl;
        }
    }


	return 0;
}