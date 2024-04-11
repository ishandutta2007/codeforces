#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
void NO(){puts("NO");exit(0);}
int main()
{
    int n;char s[310][310];
    scanf("%d",&n);
    rep(i,n)scanf("%s",s[i]+1);
    if(s[1][1]==s[1][2])NO();
    rep(i,n)if(s[i][i]!=s[1][1]||s[i][n-i+1]!=s[1][1])NO();
    rep(i,n)rep(j,n)if(i!=j&&j!=n-i+1&&s[i][j]!=s[1][2])NO();
    puts("YES");
    return 0;
}