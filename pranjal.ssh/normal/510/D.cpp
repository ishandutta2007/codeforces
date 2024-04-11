#include <bits/stdc++.h>
using namespace std;



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
#define INF 1000000007

bool sv[31623];
vi p;
vi primes;
vi l,c,a;
int memo[300][1<<9];
vi masks;
int no;
int f(int n,int mask)
{
    
    if(n==-1&&mask==0) return 0;
    if(n==-1&&mask!=0)return INF;
    
    int &ans=memo[n][mask];
    if(ans!=-1)return ans;
    
    return ans=min(f(n-1,mask),f(n-1,mask&masks[n])+c[n]);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    sv[0]=sv[1]=1;
    FOR(i,2,31622)
    {
        if(!sv[i])
        for(int j=i*i;j<=31622;j+=i)
        sv[j]=1;
    }
    FOR(i,2,31622)
    {
        if(sv[i]==0)p.pb(i);
    }
    int n;
    cin>>n;
    a.rz(n);c.rz(n);
    FOR(i,0,n-1)cin>>a[i];
    FOR(i,0,n-1)cin>>c[i];
    int ans=INF;
    if(n==1){if(a[0]!=1)c[0]=-1;cout<<c[0];return 0;}
    masks.rz(n-1);
    FOR(i,0,n-1)
    {
        memset(memo,-1,sizeof(memo));
        swap(a[i],a[n-1]);swap(c[i],c[n-1]);
        primes.clear();
        int nr=sqrt(a[n-1]);
        int x=a[n-1];
        FOR(j,2,nr)
        {
            if(x==1)break;
            if(x%j==0)
            {
                primes.pb(j);
                while(x%j==0)x/=j;
            }
        }
        if(x!=1)primes.pb(x);
        FOR(i,0,n-2)
        {
            masks[i]=0;
            tr(primes,it)
            {
                if(a[i]%(*it)==0)
                masks[i]|=(1<<(it-primes.begin()));
            }
        }
        no=primes.size();
        ans=min(ans,f(n-2,(1<<no)-1)+c[n-1]);
        swap(a[i],a[n-1]);swap(c[i],c[n-1]);
    }
    if(ans>=INF)ans=-1;
    cout<<ans<<"\n";
    return 0;
}