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
        int c[210],n,x;
        scanf("%d%d",&n,&x);
        rep(i,201)c[i]=0;
        rep(i,n){int x;scanf("%d",&x);c[x]++;}
        int ans=0;
        rep(i,201)
        if(!c[i])
        {
            if(x)x--;
            else{ans=i-1;break;}
        }
        printf("%d\n",ans);
    }
    return 0;
}