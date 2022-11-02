#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[100010];
int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    rep(i,n)if(s[i]=='0')
    {
        for(int j=i;j<n;j++)s[j]=s[j+1];
        break;
    }
    s[n]=0;
    puts(s+1);
    return 0;
}