#include<bits/stdc++.h>
using namespace std;
const int MAXN=35;
int v[MAXN][MAXN];
void init()
{
    for(int d=1;d<32;d<<=1)
    {
        for(int i=0;i<d;i++)
            for(int j=d;j<2*d;j++)
                v[i][j]=v[i][2*d-1-j]+d*d;
        for(int i=d;i<2*d;i++)
            for(int j=0;j<2*d;j++)
                v[i][j]=v[2*d-1-i][j]+2*d*d;
    }
}
int main()
{
    init();
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++,printf("\n"))
        for(int j=0;j+1<n;j++)
            printf("%d ",v[i][j]^v[i][j+1]);
    for(int i=0;i+1<n;i++,printf("\n"))
        for(int j=0;j<n;j++)
            printf("%d ",v[i][j]^v[i+1][j]);
    fflush(stdout);
    int s=0;
    while(k--)
    {
        int x;
        scanf("%d",&x);
        s^=x;
        int si=-1,sj=-1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(v[i][j]==s)si=i,sj=j;
        printf("%d %d\n",si+1,sj+1);
        fflush(stdout);
    }
    return 0;
}