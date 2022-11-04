#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
char a[MAXN][MAXN];
int solve()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",a[i]);
    int res=0;
    for(int i=0;i<n/2;i++)
        for(int j=0;j<(n+1)/2;j++)
        {
            int c=0,x=i,y=j;
            for(int k=0;k<4;k++)
            {
                c+=a[x][y]-'0';
                swap(x,y),y=n-1-y;
            }
            res+=min(c,4-c);
        }
    return 0*printf("%d\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}