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
        int n,a[5010];scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]);
        int pos=-1;
        rep(i,n)if(a[i]!=a[1]){pos=i;break;}
        if(pos==-1)puts("NO");
        else
        {
            puts("YES");
            for(int i=2;i<=n;i++)if(a[i]!=a[1])printf("1 %d\n",i);else printf("%d %d\n",i,pos);
        }
    }
    return 0;
}