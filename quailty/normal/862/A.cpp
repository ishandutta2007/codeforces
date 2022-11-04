#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=105;
int c[MAXN];
int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    for(int i=1,a;i<=n;i++)
        scanf("%d",&a),c[a]=1;
    int res=0;
    for(int i=0;i<=x;i++)
        res+=(c[i]==(i==x));
    printf("%d\n",res);
    return 0;
}