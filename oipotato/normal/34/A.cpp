#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int n,a[110];
    scanf("%d",&n);
    rep(i,n)scanf("%d",&a[i]);
    int ans=abs(a[1]-a[n]),x=1,y=n;
    rep(i,n-1)if(abs(a[i+1]-a[i])<ans)ans=abs(a[i+1]-a[i]),x=i,y=i+1;
    printf("%d %d\n",x,y);
    return 0;
}