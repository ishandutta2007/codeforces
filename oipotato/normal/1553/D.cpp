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
char s[100010],t[100010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%s%s",s+1,t+1);
        int n=strlen(s+1),m=strlen(t+1);
        for(;n>0&&m;)
        {
            for(;n>0&&s[n]!=t[m];n-=2);
            if(n>0&&s[n]==t[m])n--,m--;
        }
        puts(m?"NO":"YES");
    }
    return 0;
}