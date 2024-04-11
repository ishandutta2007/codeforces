#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[110];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        scanf("%s",s+1);
        bool flag=1;
        rep(i,n)if(s[i]!=s[n-i+1])flag=0;
        puts(flag||!k?"1":"2");
    }
    return 0;
}