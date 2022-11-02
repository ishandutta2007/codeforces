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
        int n;scanf("%d",&n);
        char s[1010];
        scanf("%s",s+1);
        int flag;
        if(n&1)
        {
            flag=2;
            for(int i=1;i<=n;i+=2)if((s[i]-'0')%2==1)flag=1;
        }
        else
        {
            flag=1;
            for(int i=2;i<=n;i+=2)if((s[i]-'0')%2==0)flag=2;
        }
        printf("%d\n",flag);
    }
    return 0;
}