#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int N=3001;
vector<vector<int> > graf(N);
vector<vector<int> > dist(N,vector<int>(N,INT_MAX)),par(N,vector<int>(N,INT_MAX)),siz(N,vector<int>(N));
ll dp[N][N];
int n;
ll calc(int u,int v){
    if(dp[u][v]!=-1)
        return dp[u][v];
    dp[u][v]=0;
    int d=dist[u][v];
    int pu=par[v][u],pv=par[u][v];
    for(auto p:graf[u])
        if(p!=pu)
            dp[u][v]=max(dp[u][v],calc(p,v)+(ll)siz[u][p]*siz[u][v]);
    for(auto p:graf[v])
        if(p!=pv)
            dp[u][v]=max(dp[u][v],calc(u,p)+(ll)siz[v][p]*siz[v][u]);
    return dp[u][v];
}
void initSiz(int tr,int par,int i){
    siz[i][tr]=1;
    for(auto p:graf[tr])
        if(p!=par)
            initSiz(p,tr,i),siz[i][tr]+=siz[i][p];
}
int main()
{
    memset(dp,-1,sizeof(dp));
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%i",&n);
	for(int i=1;i<n;i++){
        int a,b;
        scanf("%i %i",&a,&b);
        a--;b--;
        graf[a].pb(b);
        graf[b].pb(a);
	}
	for(int i=0;i<n;i++){
        queue<int> q;
        q.push(i);
        dist[i][i]=0;
        while(q.size()){
            int tr=q.front();
            q.pop();
            for(auto p:graf[tr])
                if(dist[i][p]==INT_MAX)
                    dist[i][p]=dist[i][tr]+1,par[i][p]=tr,q.push(p);
        }
        initSiz(i,i,i);
	}
    ll sol=0;
    for(int i=0;i<n;i++){
        for(auto p:graf[i]){
            sol=max(sol,calc(i,p)+(ll)siz[i][p]*siz[p][i]);
        }
    }
    printf("%lld\n",sol);
    return 0;
}