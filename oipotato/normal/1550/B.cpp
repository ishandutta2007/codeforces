#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[110];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        scanf("%s",s);
        if(b>=0)printf("%d\n",n*(a+b));
        else
        {
            int len=strlen(s),cnt=0;
            for(int i=1;i<len;i++)if(s[i]!=s[i-1])cnt++;
            printf("%d\n",n*a+b*((cnt+1)/2+1));
        }
    }
    return 0;
}