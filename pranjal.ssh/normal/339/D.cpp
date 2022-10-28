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
#define mid ((l+r)>>1)

int n,m;
int t[1<<20];
int a[1<<17];
void build(int no,int l,int r,bool op)
{
    if(l==r) {t[no]=a[l-1];return;}
    build(2*no,l,mid,!op);
    build(2*no+1,mid+1,r,!op);
    if(op)
    t[no]=t[2*no]|t[2*no+1];
    else t[no]=t[2*no]^t[2*no+1];
}
void upd(int no,int l,int r,int p,int val,bool op)
{
    if(l==r){t[no]=val;return;}
    if(p<=mid)upd(2*no,l,mid,p,val,!op);
    else upd(2*no+1,mid+1,r,p,val,!op);
    if(op)
    t[no]=t[2*no]|t[2*no+1];
    else t[no]=t[2*no]^t[2*no+1];
}
int main()
{
    boost;
    cin>>n>>m;
    int no=1<<n;
    FOR(i,0,no-1)cin>>a[i];
    build(1,1,no,n&1);
    while(m--)
    {
        int p,b;
        cin>>p>>b;
        upd(1,1,no,p,b,n&1);
        cout<<t[1]<<"\n";
    }
    return 0;
}