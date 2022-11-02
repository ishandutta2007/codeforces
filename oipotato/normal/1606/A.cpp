#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[200010],n,m;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        char s[110];scanf("%s",s+1);
        int n=strlen(s+1);
        int x=0,y=0;
        rep(i,n-1)if(s[i]=='a'&&s[i+1]=='b')x++;else if(s[i]=='b'&&s[i+1]=='a')y++;
        if(x!=y)s[n]=s[n]=='a'?'b':'a';
        puts(s+1);
    }
    return 0;
}