#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[110][110];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,m,r,c;
        scanf("%d%d%d%d",&n,&m,&r,&c);
        rep(i,n)scanf("%s",s[i]+1);
        int cnt=0;
        rep(i,n)rep(j,m)cnt+=s[i][j]=='B';
        if(!cnt)puts("-1");
        else if(s[r][c]=='B')puts("0");
        else
        {
            bool flag=0;
            rep(i,n)if(s[i][c]=='B')flag=1;
            rep(i,m)if(s[r][i]=='B')flag=1;
            if(flag)puts("1");else puts("2");
        }
    }
    return 0;
}