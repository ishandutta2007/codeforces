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

long long n,ans,val,cnt,minodd;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    ans=0;minodd=mod;
    while(n--)
    {
        cin>>val;
        ans+=val;
        if(val&1)
        {
            cnt++;
            minodd=min(minodd,val);
        }
    }
    if(cnt&1) ans-=minodd;
    cout<<ans;
}