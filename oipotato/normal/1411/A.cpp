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
        int n;char s[110];
        scanf("%d%s",&n,s+1);
        int num=0;
        for(int i=n;i;i--)if(s[i]==')')num++;else break;
        puts(num>n-num?"Yes":"No");
    }
    return 0;
}