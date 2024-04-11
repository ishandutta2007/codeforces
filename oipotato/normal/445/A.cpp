#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int n,m;
    char s[110][110];
    scanf("%d%d",&n,&m);
    rep(i,n)scanf("%s",s[i]+1);
    rep(i,n)rep(j,m)if(s[i][j]=='.')s[i][j]=(i+j)%2?'B':'W';
    rep(i,n)puts(s[i]+1);
    return 0;
}