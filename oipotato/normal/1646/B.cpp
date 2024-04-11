#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[200010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        LL x=0,y=0;
        rep(i,(n+1)/2)x+=a[i];
        for(int i=n;i>n-(n-1)/2;i--)y+=a[i];
        puts(x<y?"YES":"NO");
    }
    return 0;
}