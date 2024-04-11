#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000001
#define pb push_back

int n,m,ans,cnt[1000006],lcm,lis[1000006],mul[1000006];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    For(i,0,n)
    {
        cin>>lis[i];
        if(lis[i]<1000006) cnt[lis[i]]++;
    }
    ans=0;
    For(i,1,m+1) if(cnt[i])
    {
        for(int j=i;j<=m;j+=i) mul[j]+=cnt[i];
    }
    For(j,1,m+1)
    {
        if(ans<mul[j])
        {
            ans=mul[j];
            lcm=j;
        }
    }
    if(ans==0)
    {
        cout<<"1 0\n";
        return 0;
    }
    cout<<lcm<<' '<<ans<<endl;
    For(i,0,n) if(lcm%lis[i]==0) cout<<i+1<<' ';
}