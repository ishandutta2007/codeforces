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
        int ans=0;
        rep(i,8)
        {
            char s[10];scanf("%s",s+1);
            rep(j,8)
            {
                if(s[j]=='Q')ans+=9;
                if(s[j]=='R')ans+=5;
                if(s[j]=='B'||s[j]=='N')ans+=3;
                if(s[j]=='P')ans++;
                if(s[j]=='q')ans-=9;
                if(s[j]=='r')ans-=5;
                if(s[j]=='b'||s[j]=='n')ans-=3;
                if(s[j]=='p')ans--;
            }
        }
        if(ans>0)puts("White");
        else if(ans<0)puts("Black");
        else puts("Draw");
    }
    return 0;
}