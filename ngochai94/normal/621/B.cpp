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

long long n,cnt1[3333],cnt2[3333],x,y,ans;


int main( ){
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    while(n--)
    {
        cin>>x>>y;
        cnt1[x+y]++;
        cnt2[x-y+1500]++;
    }
    ans=0;
    For(i,0,3333)
    {
        ans+=cnt1[i]*(cnt1[i]-1)/2;
        ans+=cnt2[i]*(cnt2[i]-1)/2;
    }
    cout<<ans;
}