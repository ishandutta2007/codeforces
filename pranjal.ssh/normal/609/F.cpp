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
#define N 200010
#define mid ((l+r)>>1)
int t[N<<2];
ii x[N];
ii bc[N];
void upd(int no,int l,int r,int p,int val)
{
    if(l==r)
    {t[no]=val;return;}
    if(p<=mid)
    upd(2*no,l,mid,p,val);
    else upd(2*no+1,mid+1,r,p,val);
    
    t[no]=max(t[2*no],t[2*no+1]);
}
int mm[N];
int n,m;
int mc[N];
map<ii,int> mp;
void qry(int no,int l,int r,int pos, int p,int num)
{
    if(l>pos)return;
    if(t[no]<p)return;
    if(l==r)
    {
        auto it=mp.lower_bound({p,-1});
        vii td;
        for(;it!=mp.end();++it)
        {
            if(x[l].F+x[l].S<it->F.F)break;
            x[l].S+=it->S;
            mm[l]++;
            td.pb(it->F);
        }
        tr(td,it)
        mp.erase(*it);
        
        upd(1,1,n,l,x[l].F+x[l].S);
        return;
    }
    if(pos<=mid)
    {
        qry(2*no,l,mid,pos,p,num);return;
    }
    if(pos>mid)
    {
        if(t[2*no]>=p)
        {qry(2*no,l,mid,pos,p,num);return;}
        qry(2*no+1,mid+1,r,pos,p,num);
    }
}
int main()
{
    boost;
    cin>>n>>m;
    FOR(i,1,n)cin>>x[i].F>>x[i].S;
    FOR(i,1,n)bc[i]={x[i].F,i};
    sort(bc+1,bc+n+1);
    FOR(i,1,n)mc[bc[i].S]=i;
    sort(x+1,x+n+1);
    x[0]={-1,-1};
    x[n+1]={INF,INF};
    FOR(i,1,n)upd(1,1,n,i,x[i].F+x[i].S);
    
    FOR(i,1,m)
    {
        int p,s;
        cin>>p>>s;
        int pos=upper_bound(x,x+n+2,MP(p,INF))-x;
        pos--;
        
        if(pos>=1)
        {
            mp[{p,i}]=s;
            qry(1,1,n,pos,p,i);
        }
        
    }
    FOR(i,1,n)cout<<mm[mc[i]]<<" "<<x[mc[i]].S<<"\n";
    return 0;
}