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
        bool vis[110];rep(i,n)vis[i]=0;
        bool flag=1;
        rep(i,n)
        {
            int x;scanf("%d",&x);
            for(;x&&(x>n||vis[x]);x/=2);
            if(!x)flag=0;
            vis[x]=1;
        }
        puts(flag?"YES":"NO");
    }
    return 0;
}