#include <bits/stdc++.h>
using namespace std;

const int MAXN=2005;
const int MAXA=26;
const int INF=0x3f3f3f3f;

inline void update(int &x,int y)
{
    (x>y) && (x=y);
}

char s[MAXN],t[MAXN];
int ps[MAXN][MAXA],pt[MAXN][MAXA];
int dp[MAXN][MAXN];

void Main()
{
    int n;
    scanf("%d%s%s",&n,s+1,t+1);
    for(int i=1;i<=n;i++)
    {
        memcpy(ps[i],ps[i-1],sizeof(ps[i-1]));
        ps[i][s[i]-'a']++;
        memcpy(pt[i],pt[i-1],sizeof(pt[i-1]));
        pt[i][t[i]-'a']++;
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=INF;
    dp[0][0]=0;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
        {
            if(i<n && j<n && s[i+1]==t[j+1])
                update(dp[i+1][j+1],dp[i][j]);
            if(i<n && ps[i][s[i+1]-'a']<pt[j][s[i+1]-'a'])
                update(dp[i+1][j],dp[i][j]);
            if(j<n)update(dp[i][j+1],dp[i][j]+1);
        }
    printf("%d\n",(dp[n][n]<INF ? dp[n][n] : -1));
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)Main();    
    return 0;
}