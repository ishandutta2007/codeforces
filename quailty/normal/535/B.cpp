#include<cstdio>
#include<cstring>
const int MOD=1000000007;
char s[100005];
int main()
{
    scanf("%s",s);
    int n=strlen(s);
    int ans=0;
    for(int i=0;i<=n-1;i++)
    {
        if(s[i]=='4')
        {
            ans=(ans*2+1)%MOD;
        }
        else
        {
            ans=(ans*2+2)%MOD;
        }
    }
    printf("%d",ans);
}