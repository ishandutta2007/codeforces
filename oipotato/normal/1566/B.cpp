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
        char s[100010];scanf("%s",s+1);
        int n=strlen(s+1);
        int cnt=0;
        rep(i,n)if(i==1||s[i]!=s[i-1])s[++cnt]=s[i];
        if(cnt==1&&s[1]=='1')puts("0");
        else
        {
            int cc=0;
            rep(i,cnt)cc+=s[i]=='0';
            if(cc==1)puts("1");
            else puts("2");
        }
    }
    return 0;
}