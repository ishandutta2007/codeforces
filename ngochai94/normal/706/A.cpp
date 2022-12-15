#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-8
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

long double a,b,n,x,y,v,ans;

int main( ){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ans = -1;
    cin>>a>>b>>n;
    while(n--) {
        cin>>x>>y>>v;
        if(ans < 0) ans = sqrt(sqr(x-a)+sqr(y-b))/v;
        else ans = min(ans, sqrt(sqr(x-a)+sqr(y-b))/v);
    }
    cout<<setprecision(11)<<ans;
}