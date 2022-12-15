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

int n,lis[1111];
vector<int> ans;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    For(i,0,n) cin>>lis[i];
    ans.pb(lis[0]);
    For(i,1,n)
    {
        if(__gcd(lis[i],lis[i-1])!=1) ans.pb(1);
        ans.pb(lis[i]);
    }
    cout<<ans.size()-n<<endl;
    for(int i:ans) cout<<i<<' ';
}