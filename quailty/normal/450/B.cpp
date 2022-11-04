#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int Mod=1000000007;
int main()
{
    int x,y,n;
    scanf("%d%d%d",&x,&y,&n);
    int res[6]={x,y,y-x,-x,-y,x-y};
    printf("%d",(res[(n-1)%6]%Mod+Mod)%Mod);
    return 0;
}