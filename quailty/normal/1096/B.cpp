#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
const int Mod=998244353;
char s[MAXN];
int main()
{
    int n;
    scanf("%d%s",&n,s+1);
    int l=1,r=n;
    for(int i=1;i<=n;i++)
        if(s[i]!=s[1])
        {
            l=i-1;
            break;
        }
    for(int i=n;i>=1;i--)
        if(s[i]!=s[n])
        {
            r=n-i;
            break;
        }
    printf("%lld\n",(1+l+r+1LL*(s[1]==s[n])*l*r)%Mod);
    return 0;
}