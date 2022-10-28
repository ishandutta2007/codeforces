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

#define all(x) x.begin(), x.end()
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
#define ntr(x,it) for(auto it = x.rbegin();it!=x.rend();++it)
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
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,n) FOR(i,0,n-1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)

struct BIT1
{
    vector<int> t;
    int n;
    BIT1()
    {
            n=0;
            t.clear();
    }
    BIT1(int sz)
    {
        n=sz;
        t.clear();
        t.resize(sz+1);
    }
    void clear(int sz)
    {
        n=sz;
        t.clear();
        t.resize(sz+1);
    }
    void update(int i, int val)
    {
        while(i<=n)
        {
            t[i]+=val;
            if(t[i]>=INF)t[i]-=INF;
            i+=i&-i;
        }
    }
    int query(int i)
    {
        int ans=0;
        while(i>0)
        {
            ans+=t[i];
            if(ans>=INF)ans-=INF;
            i-=i&-i;
        }
        return ans;
    }
};


int a[100001];

BIT1 bt1(1000000);
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int n;
    cin>>n;
    FOR(i,1,n)cin>>a[i];
    ll ans=0;
    FOR(i,1,n)
    {
        ll x=bt1.query(a[i]);
        ll y=x-bt1.query(a[i]-1);
        
        
        ll now=x*a[i]+a[i]-y;
        now%=INF;
        if(now<0)now+=INF;
        ans+=now;
        if(ans>=INF)ans-=INF;
        
        bt1.update(a[i],now);
        
    }
    cout<<ans<<"\n";
    return 0;
}