#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t,s,x;
    scanf("%d%d%d",&t,&s,&x);
    if(x<t || x==t+1)return 0*printf("NO");
    return 0*printf("%s",((x-t)%s<2 ? "YES" : "NO"));
}