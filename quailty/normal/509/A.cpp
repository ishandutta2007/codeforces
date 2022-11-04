#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[15][15];
bool v[15][15];
void s(int x,int y)
{
    if(v[x][y])return;
    v[x][y]=1;
    if(x==1||y==1){
        a[x][y]=1;
        return;
    }
    s(x-1,y);
    s(x,y-1);
    a[x][y]=a[x-1][y]+a[x][y-1];
}
int main()
{
    int n;
    scanf("%d",&n);
    s(n,n);
    printf("%d",a[n][n]);
    return 0;
}