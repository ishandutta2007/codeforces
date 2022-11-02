#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[100010];
bool ocu[10];
int main()
{
    int n;scanf("%d%s",&n,s+1);
    rep(i,n)
    if(s[i]=='L')
    {
        for(int j=0;j<10;j++)if(!ocu[j]){ocu[j]=1;break;}
    }
    else if(s[i]=='R')
    {
        for(int j=9;j>=0;j--)if(!ocu[j]){ocu[j]=1;break;}
    }
    else ocu[s[i]-'0']=0;
    rep(i,10)printf("%d",ocu[i-1]);puts("");
    return 0;
}