#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
char s[MAXN];
ll dp[MAXN][8];
int main()
{
    int n,m;
    scanf("%d%d%s",&n,&m,s+1);
    dp[0][7]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<8;j++)
            for(int k=0;k<m;k++)
            {
                int t[3]={i-3,i-2,i-2};
                for(int p=0;p<3;p++)
                    t[p]+=j>>p&1;
                int r[3],d[3]={i-2,i-1,i-1};
                r[0]=(s[i-1]=='a'+k ? t[0]+1 : t[1]);
                r[1]=(s[i]=='a'+k ? t[1]+1 : max(r[0],t[2]));
                r[2]=(s[i+1]=='a'+k ? t[2]+1 : r[1]);
                bool isok=1;
                for(int p=0;p<3;p++)
                    if(r[p]<d[p])isok=0;
                if(!isok)continue;
                int mask=0;
                for(int p=0;p<3;p++)
                    mask|=(r[p]-d[p])<<p;
                dp[i][mask]+=dp[i-1][j];
            }
    ll res=0;
    for(int i=0;i<8;i++)
        if(~i&2)res+=dp[n][i];
    printf("%I64d",res);
    return 0;
}