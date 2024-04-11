#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int main()
{
    int T;
    // for(scanf("%d",&T);T--;)
    {
        int n,p[1010],vis[1010];
        scanf("%d",&n);
        rep(i,n)scanf("%d",&p[i]);
        rep(i,n)
        {
            rep(j,n)vis[j]=0;
            int x=i;
            for(;!vis[x];vis[x]=1,x=p[x]);
            printf("%d%c",x," \n"[i==n]);
        }
    }
    return 0;
}