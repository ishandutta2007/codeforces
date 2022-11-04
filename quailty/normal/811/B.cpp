#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=10005;
int p[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    for(int _=1;_<=m;_++)
    {
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        int c=l;
        for(int i=l;i<=r;i++)
            c+=(p[i]<p[x]);
        printf("%s\n",(c==x ? "Yes" : "No"));
    }
    return 0;
}