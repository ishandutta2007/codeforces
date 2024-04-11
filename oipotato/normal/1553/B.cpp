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
char s[1010],t[1010],a[1010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%s",s+1);
        scanf("%s",t+1);
        int n=strlen(s+1),m=strlen(t+1);
        bool flag=0;
        rep(i,n)
        {
            for(int j=i;j<=n;j++)
            {
                int cnt=0;
                for(int k=i;k<=j;k++)a[++cnt]=s[k];
                for(int k=j-1;k;k--)a[++cnt]=s[k];
                if(cnt<m)continue;
                bool ff=1;
                rep(k,m)if(a[k]!=t[k]){ff=0;break;}
                if(ff){flag=1;break;}
            }
            if(flag)break;
        }
        puts(flag?"YES":"NO");
    }
    return 0;
}