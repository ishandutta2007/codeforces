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
#define mid ((l+r)>>1)

const int N =4e5+10;
int a[N];
vi _x;
vi t;

void upd(int no,int l,int r,int pos,int val)
{
    if(l==r)
        {t[no]=max(t[no],val);return;}
    if(pos>mid)
        upd(no+no+1,mid+1,r,pos,val);
    else upd(no+no,l,mid,pos,val);
    t[no]=max(t[2*no],t[2*no+1]);
}
int qry(int no,int l,int r,int ql,int qr)
{
    if(l>=ql and r<=qr)
        return t[no];
    if(mid<ql)   
        return qry(no+no+1,mid+1,r,ql,qr);
    else if(qr<=mid) return qry(no+no,l,mid,ql,qr);
    else return max(qry(no+no,l,mid,ql,qr),qry(no+no+1,mid+1,r,ql,qr));
}
vi pos[N];
int ans[N];
vii q[N];
int ql[N];
int qr[N];
int can[N];
int R[N];
int main()
{
    boost;
    int n,m;
    cin>>n>>m;
    FOR(i,1,n)cin>>a[i],_x.pb(a[i]);
    FOR(i,1,m)
    {
        int x,y;
        cin>>x>>y;
        q[x].pb({y,i});
        _x.pb(y);
    }
    ufy(_x);
    FOR(i,1,n)a[i]=lower_bound(all(_x),a[i])-_x.begin()+1;
    
    int S = sz(_x)+5;
    t.rz(4*S);
    int YO = 0;
    NFOR(i,n,1)
    {
        int x = qry(1,1,S,a[i]+1,S);
    
        for(auto it:q[i])
        {
            auto p = lower_bound(all(_x),it.F);
            qr[it.S]=qry(1,1,S,p-_x.begin()+2,S);
        }
        upd(1,1,S,a[i],x+1);
        YO=max(YO,x+1);
        R[i]=x;
    }

    fill(all(t),0);
    FOR(i,1,n)
    {
        int x =(a[i]==1)?0:qry(1,1,S,1,a[i]-1);
        if(R[i]+x+1==YO)
        pos[x+1].pb(i);
        for(auto it:q[i])
        {
            auto p = lower_bound(all(_x),it.F);
            ql[it.S]=(p==_x.begin())?0:qry(1,1,S,1,p-_x.begin());
        }
        upd(1,1,S,a[i],x+1);
    }

    FOR(i,1,n)
    {
        if(sz(pos[i])==1)
            can[pos[i][0]]=1;
    }
    FOR(i,1,n)
    {
        for(auto it : q[i])
        {
            ans[it.S]=YO-can[i];
            ans[it.S]=max(ans[it.S],ql[it.S]+qr[it.S]+1);
        }
    }
    FOR(i,1,m)
    cout<<ans[i]<<"\n";

    
    return 0;
}