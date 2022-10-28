#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000363

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
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
#define ufy(v) sort(all(v));(v).erase(unique(all((v))),(v).end())
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
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
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,n) FOR(i,0,n-1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
inline int norm(int x,int m=INF){if(x>=m)x%=m;if(x<0)x+=m;return x;}
inline int neg(int x,int m=INF){x=-x;return norm(x);}


struct dis_set
{
    vi p,r;
    dis_set(int n){p.rz(n);r.rz(n);FOR(i,0,n-1)p[i]=i;}

    int get(int i)
    {
        if(p[i]!=i)p[i]=get(p[i]);
        return p[i];
    }
    int connect(int i, int j)
    {
        int x=get(i),y=get(j);
        if(x==y) return 0;
        if(r[x]<r[y])p[x]=y;
        else {p[y]=x;if(r[x]==r[y])++r[x];}
        return 1;
    }
};
vvi a;
vvii R;
vvii C;
vi _x;
vvi g;
vi pos[1000000+1];
int dp[1000000+1];
int main()
{
    boost;
    int n,m;
    cin>>n>>m;
    a.rz(n);R.rz(n);C.rz(m);
    FOR(i,0,n-1)
    {
        a[i].rz(m);
        FOR(j,0,m-1)cin>>a[i][j],_x.pb(a[i][j]);
    }
    ufy(_x);

    dis_set YO(n*m);
    FOR(i,0,n-1)
    {
        FOR(j,0,m-1)
        a[i][j]=(lower_bound(all(_x),a[i][j])-_x.begin())+1,R[i].pb({a[i][j],j}),pos[a[i][j]].pb(i*m+j);
        sort(all(R[i]));
        FOR(j,1,m-1)
        if(R[i][j].F==R[i][j-1].F)
            YO.connect(i*m+R[i][j].S,i*m+R[i][j-1].S);
    }
    
    FOR(j,0,m-1)
    {
        FOR(i,0,n-1)C[j].pb({a[i][j],i});
        sort(all(C[j]));
        FOR(i,1,n-1)
        if(C[j][i].F==C[j][i-1].F)
            YO.connect(C[j][i].S*m+j,C[j][i-1].S*m+j);
    }

    g.rz(n*m);

    FOR(i,0,n-1)
    FOR(j,1,m-1)
    if(R[i][j].F!=R[i][j-1].F)
    {g[YO.get(i*m+R[i][j-1].S)].pb(YO.get(i*m+R[i][j].S));}

    FOR(j,0,m-1)
    FOR(i,1,n-1)
    if(C[j][i].F!=C[j][i-1].F)
        g[YO.get(C[j][i-1].S*m+j)].pb(YO.get(C[j][i].S*m+j));

    int bc=0;
    
    NFOR(i,1000000,1)
    {
        for(auto it:pos[i])
        {
            if(YO.get(it)!=it)continue;
            for(auto itt:g[it])
                dp[it]=max(dp[itt],dp[it]);
            dp[it]+=1;
            bc=max(bc,dp[it]);
        }
    }
    FOR(i,0,n-1)
    {
        FOR(j,0,m-1)
        {
            cout<<bc-dp[YO.get(i*m+j)]+1<<" ";
        }
        cout<<"\n";
    }



    return 0;
}