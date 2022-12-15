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
#define offset (110009)

int n,k,a,b,c,d;
vector<int> ans;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>k>>a>>b>>c>>d;
    if(n==4||k<n+1)
    {
        cout<<-1;return 0;
    }
    ans.pb(0);
    ans.pb(a);ans.pb(c);
    For(i,1,1+n) if(i!=a&&i!=b&&i!=c&&i!=d) ans.pb(i);
    ans.pb(d);ans.pb(b);
    For(i,1,1+n) cout<<ans[i]<<' ';
    cout<<endl;
    cout<<ans[2]<<' '<<ans[1]<<' ';
    For(i,3,n-1) cout<<ans[i]<<' ';
    cout<<ans[n]<<' '<<ans[n-1];
}