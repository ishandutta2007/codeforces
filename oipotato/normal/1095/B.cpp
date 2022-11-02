#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[100010],n;
int main()
{
    int T;
    // for(scanf("%d",&T);T--;)
    {
        scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        printf("%d\n",min(a[n]-a[2],a[n-1]-a[1]));
    }
    return 0;
}