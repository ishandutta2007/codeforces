#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;char s[55][55];
        scanf("%d",&n);
        rep(i,n)scanf("%s",s[i]+1);
        bool flag=1;
        rep(i,n-1)rep(j,n-1)if(s[i][j]=='1'&&s[i+1][j]=='0'&&s[i][j+1]=='0')flag=0;
        puts(flag?"YES":"NO");
    }
    return 0;
}