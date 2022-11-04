#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
const int INF=0x3f3f3f3f;
char s[MAXN];
int x[MAXN];
int main()
{
    int n;
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    int res=INF;
    for(int i=1;i<n;i++)
        if(s[i]=='R' && s[i+1]=='L')
            res=min(res,(x[i+1]-x[i])/2);
    printf("%d\n",(res<INF ? res : -1));
    return 0;
}