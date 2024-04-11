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
    // for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        int a[200010];
        rep(i,n)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int now=1;
        rep(i,n)if(a[i]>=now)now++;
        printf("%d\n",now-1);
    }
    return 0;
}