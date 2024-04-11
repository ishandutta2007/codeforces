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

ll expo(int base, int exp, int MOD=INF) {
    ll res=1;
    while(exp>0) {
       if(exp&1) res=(res*base)%MOD;
       base=((ll)base*base)%MOD;
       exp=exp>>1;
    }
    return res;
}
int a[200001];
vii b;

int main()
{
    boost;
    int n;cin>>n;
    FOR(i,1,n)cin>>a[i];
    sort(a+1,a+n+1);

    FOR(i,1,n)
    {
        int j=i;int x=1;
        while(j<=n and a[j+1]==a[j])
        {
            j++;x++;
        }
        b.pb({a[i],x});
        i=i+x-1;
    }
    
    int noo=sz(b);
    int ans=expo(b[0].F,((b[0].S*(b[0].S+1LL))/2)%(INF-1));
    int no=b[0].S+1;

    FOR(i,1,noo-1)
    {
        
        int bc=expo(b[i].F,((b[i].S*(b[i].S+1LL))/2)%(INF-1));
        ans=expo(ans,b[i].S+1);
        ans=mul(ans,expo(bc,no));
        no=mul(no,b[i].S+1,INF-1);
    }
    cout<<ans;
    return 0;
}