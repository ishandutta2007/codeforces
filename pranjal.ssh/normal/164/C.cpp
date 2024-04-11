#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define tr(x,it) for(auto it = (x).begin();it!=(x).end();++it)
#define ntr(x,it) for(auto it = (x).rbegin();it!=(x).rend();++it)
#define ufy(v) sort(all((v)));(v).erase(unique(all((v))),(v).end())
#define sz(a) int((a).size()) 
#define pb push_back 
#define PB pop_back
#define pf push_front
#define PF pop_front
#define MP make_pair
#define clr clear
#define rz resize
#define C(a,b) memset(a,b,sizeof(a))
#define ia(a,n) FOR(i,0,n-1)cin>>a[i]
#define ia1(a,n) FOR(i,1,n)cin>>a[i]
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector

#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,n) FOR(i,0,n-1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
inline int neg(int x,int m=INF){x=-x;return norm(x);}
inline int norm(int x,int m=INF){if(x>=m)x%=m;if(x<0)x+=m;return x;}

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef int F;
typedef ll C;
#define F_INF (1<<29)
#define C_INF (1ll<<60)
#define MAXV 3000
#define MAXE 10000 // E*2!

    int V,E;
    F cap[MAXE],flow[MAXE];
    C cost[MAXE],dist[MAXV],pot[MAXV];
    int to[MAXE],prv[MAXE],last[MAXV],path[MAXV];
    bool used[MAXV];
    priority_queue <pair <C, int> > q;

class MinCostFlow{
    public:

    MinCostFlow(int n){
        V = n; E = 0;
        int i; REP(i,V) last[i] = -1;
    }

    void add_edge(int x, int y, F w, C c){
        cap[E] = w; flow[E] = 0; cost[E] = c; to[E] = y; prv[E] = last[x]; last[x] = E; E++;
        cap[E] = 0; flow[E] = 0; cost[E] = -c; to[E] = x; prv[E] = last[y]; last[y] = E; E++;
    }

    pair <F, C> search(int s, int t){
        F ansf=0; C ansc=0;
        int i;

        REP(i,V) used[i] = false;
        REP(i,V) dist[i] = C_INF;
    
        dist[s] = 0; path[s] = -1; q.push(make_pair(0,s));
        while(!q.empty()){
            int x = q.top().second; q.pop();
            if(used[x]) continue; used[x] = true;
            for(int e=last[x];e>=0;e=prv[e]) if(cap[e] > 0){
                C tmp = dist[x] + cost[e] + pot[x] - pot[to[e]];
                if(tmp < dist[to[e]] && !used[to[e]]){
                    dist[to[e]] = tmp;
                    path[to[e]] = e;
                    q.push(make_pair(-dist[to[e]],to[e]));
                }
            }
        }

        REP(i,V) pot[i] += dist[i];

        if(used[t]){
            ansf = F_INF;
            for(int e=path[t];e>=0;e=path[to[e^1]]) ansf = min(ansf,cap[e]);
            for(int e=path[t];e>=0;e=path[to[e^1]]) {ansc += cost[e] * ansf; cap[e] -= ansf; cap[e^1] += ansf;}
        }

        return make_pair(ansf,ansc);
    }

    pair <F, C> mincostflow(int s, int t){
        F ansf=0; C ansc=0;
        int i;
        REP(i,V) pot[i] = 0;
        while(1){
            pair <F, C> p = search(s,t);
            if(!used[t]) break;
            ansf += p.first; ansc += p.second;
        }
        return make_pair(ansf,ansc);
    }
};
int s[1001],t[1001],c[1001];
vi v;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    FOR(i,0,n-1)
    {
        cin>>s[i]>>t[i]>>c[i];
        t[i]+=s[i];
        v.pb(s[i]);
        v.pb(t[i]);
    }
    v.pb(0);
    v.pb(INF);
    ufy(v);
    MinCostFlow rng(sz(v));
    
    ll X=1000010;
    FOR(i,0,n-1)
    {
        int uu=lower_bound(all(v),s[i])-v.begin();
        int vv=lower_bound(all(v),t[i])-v.begin();
        rng.add_edge(uu,vv,1,(vv-uu)*X-c[i]);
    }
    FOR(i,1,sz(v)-1)
    rng.add_edge(i-1,i,k,X);
    pair<F,C> x= rng.mincostflow(0,sz(v)-1);
    
    //cout<<x.first<<" "<<x.S<<"\n";
    
    FOR(i,0,n-1)
    {
        int ans=0;
            if(cap[2*i]==0)
            ans=1;
        cout<<ans<<" ";
    }
    return 0;
}