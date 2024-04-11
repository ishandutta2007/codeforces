#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[55][55];
void solve(int n)
{
    int x=0,y=n/2;
    for(int i=1;i<=n*n;i++)
    {
        a[x][y]=i;
        x=(x+n-1)%n;
        y=(y+1)%n;
        if(a[x][y])
        {
            x=(x+2)%n;
            y=(y+n-1)%n;
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    solve(n);
    for(int i=0;i<n;i++,printf("\n"))
        for(int j=0;j<n;j++)
            printf("%d ",a[i][j]);
    return 0;
}