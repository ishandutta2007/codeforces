#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int x,ans;
        scanf("%d",&x);
        if(x<=1399)ans=4;
        else if(x<=1599)ans=3;
        else if(x<=1899)ans=2;
        else ans=1;
        printf("Division %d\n",ans);
    }
    return 0;
}