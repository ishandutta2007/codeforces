#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[200010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%s",s+1);
        int n=strlen(s+1);
        int c[2]={0,0};
        rep(i,n)c[s[i]-'0']++;
        printf("%d\n",c[0]==c[1]?c[0]-1:min(c[0],c[1]));
    }
    return 0;
}