#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[200010],t[200010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        scanf("%s%s",s+1,t+1);
        int ans=0;
        rep(i,n)
        if(t[i]=='1')
        {
            if(s[i]=='0'||s[i-1]=='1')ans++;
            else if(s[i+1]=='1')s[i+1]='2',ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}