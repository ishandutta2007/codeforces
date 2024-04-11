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
    // for(scanf("%d",&T);T--;)
    {
        char s[110];scanf("%s",s+1);
        int n=strlen(s+1);
        int ans=(n-1)/2;
        bool flag=!(n&1);
        rep(i,n-1)if(s[i+1]=='1')flag=1;
        printf("%d\n",ans+flag);
    }
    return 0;
}