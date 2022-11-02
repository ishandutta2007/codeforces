#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[110],t[110];
int n;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%d",&n);scanf("%s",s+1);
        rep(i,n)t[i]=s[i];
        sort(s+1,s+n+1);
        int ans=0;
        rep(i,n)if(s[i]!=t[i])ans++;
        printf("%d\n",ans);
    }
    return 0;
}