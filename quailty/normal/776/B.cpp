#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int np[MAXN];
void build()
{
    for(int i=2;i<MAXN;i++)if(!np[i])
        for(int j=2*i;j<MAXN;j+=i)np[j]=1;
}
int main()
{
    build();
    int n;
    scanf("%d",&n);
    printf("%d\n",1+(n>=3));
    for(int i=2;i<=n+1;i++)
        printf("%d ",1+np[i]);
    return 0;
}