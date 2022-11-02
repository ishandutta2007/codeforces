#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[20],a[20],b[20];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%s",s+1);
        rep(i,5)a[i]=s[2*i-1],b[i]=s[2*i];
        int x=0,y=0,ans=10;
        rep(i,5)
        {
            if(a[i]=='?')x++;else x+=a[i]-'0';
            if(y+5-i+1<x){ans=min(ans,2*i-1);break;}
            if(b[i]!='?')y+=b[i]-'0';
            if(y+5-i<x){ans=min(ans,2*i);break;}
        }
        x=0;y=0;
        rep(i,5)
        {
            if(a[i]!='?')x+=a[i]-'0';
            if(x+5-i<y){ans=min(ans,2*i-1);break;}
            if(b[i]=='?')y++;else y+=b[i]-'0';
            if(x+5-i<y){ans=min(ans,2*i);break;}
        }
        printf("%d\n",ans);
    }
    return 0;
}