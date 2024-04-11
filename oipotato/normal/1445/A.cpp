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
        int n,x,a[55],b[55];scanf("%d%d",&n,&x);
        rep(i,n)scanf("%d",&a[i]);
        rep(i,n)scanf("%d",&b[i]);
        sort(a+1,a+n+1);
        sort(b+1,b+n+1,greater<int>());
        bool flag=1;
        rep(i,n)if(a[i]+b[i]>x)flag=0;
        puts(flag?"Yes":"No");
    }
    return 0;
}