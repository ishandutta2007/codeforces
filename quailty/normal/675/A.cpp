#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if((c==0 && b!=a)||(b-a)%c!=0)return 0*printf("NO\n");
    if(c!=0 && (b-a)/c<0)return 0*printf("NO\n");
    return 0*printf("YES\n");
}