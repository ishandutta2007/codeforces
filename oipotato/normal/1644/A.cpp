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
        bool key[3]={0,0,0};
        char s[10];
        scanf("%s",s+1);
        bool flag=1;
        rep(i,6)
        if(s[i]=='r')key[0]=1;
        else if(s[i]=='g')key[1]=1;
        else if(s[i]=='b')key[2]=1;
        else if(s[i]=='R')flag&=key[0];
        else if(s[i]=='G')flag&=key[1];
        else if(s[i]=='B')flag&=key[2];
        puts(flag?"YES":"NO");
    }
    return 0;
}