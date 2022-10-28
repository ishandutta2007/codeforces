#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000000000

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
#define N 4001

vll v,d,p;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int n;
    cin>>n;
    v.rz(n);d.rz(n);p.rz(n);
    
    FOR(i,0,n-1)cin>>v[i]>>d[i]>>p[i];
    
    FOR(i,0,n-1)
    {
        //FOR(i,0,n-1)cout<<p[i]<<" ";cout<<endl;
        if(p[i]==INF)continue;
        ll ctr=0;
        
        FOR(j,i+1,n-1)
        {
            if(v[i]-ctr==0)break;
            if(p[j]==INF)continue;
            p[j]-=v[i]-ctr;
            ++ctr;
        }
        FOR(j,i+1,n-1)
        {
            if(p[j]<0)
            {
                FOR(k,j+1,n-1)
                {
                    if(p[k]==INF)continue;
                    p[k]-=d[j];
                }
                p[j]=INF;
            }
        }
    }
    //cout<<p[4];
    int ans=0;
    FOR(i,0,n-1)if(p[i]!=INF)++ans;
    cout<<ans<<"\n";
    FOR(i,0,n-1)if(p[i]!=INF)cout<<i+1<<" ";
    return 0;
}