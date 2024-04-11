#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int vis[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1,j=n;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        vis[a]=1;
        while(vis[j])printf("%d ",j--);
        printf("\n");
    }
    return 0;
}