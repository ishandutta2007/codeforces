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
        int n,a[55];scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]);
        if(a[1]==n&&a[n]==1)puts("3");
        else if(a[1]!=1&&a[n]!=n)puts("2");
        else
        {
            bool flag=1;
            rep(i,n)if(a[i]!=i)flag=0;
            puts(flag?"0":"1");
        }
    }
    return 0;
}