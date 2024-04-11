#include<bits/stdc++.h>
#define MAXN 100
using namespace std;
long long a[MAXN][MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i+j!=0 && (i&1)) a[i][j]=1LL<<(i+j-1LL);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) printf("%lld ",a[i][j]);
        printf("\n");
        fflush(stdout);
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        long long k;
        scanf("%lld",&k);
        int x=0,y=0;
        while(x!=n-1 || y!=n-1)
        {
            printf("%d %d\n",x+1,y+1);
            fflush(stdout);
            if(x+1<n && a[x+1][y]==(k&(1LL<<(x+y)))) x++;
            else y++;
        }
        printf("%d %d\n",x+1,y+1);
        fflush(stdout);
    }
}