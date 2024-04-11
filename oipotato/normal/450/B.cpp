#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int MOD=(int)1e9+7;
int main()
{
    int x,y,n;scanf("%d%d%d",&x,&y,&n);
    n=(n-1)%6+1;
    int ans;
    if(n==1)ans=x;
    else if(n==2)ans=y;
    else if(n==3)ans=y-x;
    else if(n==4)ans=-x;
    else if(n==5)ans=-y;
    else if(n==6)ans=x-y;
    ans=(ans%MOD+MOD)%MOD;
    printf("%d\n",ans);
    return 0;
}