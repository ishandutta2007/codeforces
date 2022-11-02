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
        int n,a[110];
        scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int ans=1;
        rep(i,n-1)if(a[i]==a[i+1]-1)ans=2;
        printf("%d\n",ans);
    }
    return 0;
}