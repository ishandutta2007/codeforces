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
        int n,a[200010];scanf("%d",&n);
        rep(i,n)a[i]=i-1;
        int x=1;
        for(int i=20;i>=0;i--)if((n-1)&(1<<i)){x=1<<i;break;}
        reverse(a+1,a+x+1);
        rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
    }
    return 0;
}