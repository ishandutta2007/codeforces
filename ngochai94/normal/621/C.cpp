#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

long long n,pp,l,r;
long double ans,p[100005];

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>pp;
    For(i,0,n)
    {
        cin>>l>>r;
        p[i]=1.0*(r/pp-(l-1)/pp)/(r-l+1);
        ans+=p[i];
    }
    ans*=2;
    //cout<<ans<<endl;
    For(i,0,n-1) ans-=p[i]*p[i+1];
    ans-=p[0]*p[n-1];
    //cout<<ans<<endl;
    cout<<setprecision(11)<<ans*2000;
}