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
        char s[100010];
        scanf("%s",s+1);
        int n=strlen(s+1);
        if(n==1){puts("0");return 0;}
        int sum=0;rep(i,n)sum+=s[i]-'0';
        int ans=1;
        for(;sum>=10;)
        {
            int x=0;
            for(;sum;x+=sum%10,sum/=10);
            ans++;
            sum=x;
        }
        printf("%d\n",ans);
    }
    return 0;
}