#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[300010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        char s[3010];
        scanf("%s",s+1);
        int pos1=-1,pos2=-1;
        rep(i,n)if((s[i]-'0')&1)
        {
            if(pos1==-1)pos1=i;else pos2=i;
        }
        if(pos2==-1)puts("-1");
        else printf("%c%c\n",s[pos1],s[pos2]);
    }
    return 0;
}