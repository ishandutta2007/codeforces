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

long long n,a,b,c,ans;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>a>>b>>c;
    if(a<=b-c)
    {
        cout<<n/a;return 0;
    }
    if(n>=b)
    {
        ans+=(n-b)/(b-c)+1;
        n-=ans*(b-c);
        ans+=n/min(a,b);
    }
    else ans=n/a;
    cout<<ans;
}