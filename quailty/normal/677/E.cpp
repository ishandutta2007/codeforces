#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long double ldb;
const int MAXN=1005;
const int INF=0x3f3f3f3f;
const int Mod=1000000007;
const int d[8][2]=
{
    {0,1},{1,1},{1,0},{1,-1},
    {0,-1},{-1,-1},{-1,0},{-1,1}
};
char s[MAXN][MAXN];
int b[MAXN][MAXN][8];
int c[2][MAXN][MAXN][8];
int pw[2][MAXN<<2];
int fp(int a,int k)
{
    int res=1;
    while(k)
    {
        if(k&1)res=1LL*res*a%Mod;
        a=1LL*a*a%Mod;
        k>>=1;
    }
    return res;
}
pair<ldb,int> get_cross(int x,int y,int t,int n)
{
    int len=INF,cnt[2]={0,0};
    for(int i=t;i<8;i+=2)
        len=min(len,b[x][y][i]);
    pair<int,int>p[4];
    for(int i=t;i<8;i+=2)
        p[i/2]=make_pair(x+(len-1)*d[i][0],y+(len-1)*d[i][1]);
    for(int i=t;i<8;i+=2)
        for(int j=0;j<2;j++)
            cnt[j]+=c[j][p[i/2].first][p[i/2].second][i]-c[j][x][y][i];
    if(s[x][y]>='2')cnt[s[x][y]-'2']++;
    ldb res=0;
    int ans=1;
    for(int i=0;i<2;i++)
    {
        res+=cnt[i]*log(i+2);
        ans=1LL*ans*pw[i][cnt[i]]%Mod;
    }
    return make_pair(res,ans);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    pw[0][0]=pw[1][0]=1;
    for(int i=1;i<=4*n;i++)
    {
        pw[0][i]=2LL*pw[0][i-1]%Mod;
        pw[1][i]=3LL*pw[1][i-1]%Mod;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=0;k<4;k++)
            {
                b[i][j][k]=(s[i][j]-'0' ? b[i-d[k][0]][j-d[k][1]][k]+1 : 0);
                for(int t=0;t<2;t++)
                    c[t][i][j][k]=c[t][i-d[k][0]][j-d[k][1]][k]+(s[i][j]=='2'+t);
            }
    for(int i=n;i>=1;i--)
        for(int j=n;j>=1;j--)
            for(int k=4;k<8;k++)
            {
                b[i][j][k]=(s[i][j]-'0' ? b[i-d[k][0]][j-d[k][1]][k]+1 : 0);
                for(int t=0;t<2;t++)
                    c[t][i][j][k]=c[t][i-d[k][0]][j-d[k][1]][k]+(s[i][j]=='2'+t);
            }
    int ans=0;
    ldb res=-1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(s[i][j]=='0')continue;
            pair<ldb,int>t;
            for(int k=0;k<2;k++)
            {
                t=get_cross(i,j,k,n);
                if(t.first>res)res=t.first,ans=t.second;
            }
        }
    return 0*printf("%d",ans);
}