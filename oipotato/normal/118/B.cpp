#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        rep(j,2*(n-i)-1)putchar(' ');
        for(int j=0;j<=i;j++)if(i==n&&j==0)printf("0");else printf(" %d",j);
        for(int j=i-1;j>=0;j--)printf(" %d",j);
        puts("");
    }
    for(int i=n-1;i>=0;i--)
    {
        rep(j,2*(n-i)-1)putchar(' ');
        for(int j=0;j<=i;j++)printf(" %d",j);
        for(int j=i-1;j>=0;j--)printf(" %d",j);
        puts("");
    }
    return 0;
}