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
        int n,q,c[2][110];scanf("%d%d",&n,&q);
        char s[110];scanf("%s",s+1);
        rep(i,2)rep(j,n+1)c[i-1][j-1]=0;
        rep(i,n)c[0][i]=c[0][i-1]+(s[i]=='0'),c[1][i]=c[1][i-1]+(s[i]=='1');
        rep(i,q)
        {
            int l,r;scanf("%d%d",&l,&r);
            puts(!c[s[l]-'0'][l-1]&&!(c[s[r]-'0'][n]-c[s[r]-'0'][r])?"NO":"YES");
        }
    }
    return 0;
}