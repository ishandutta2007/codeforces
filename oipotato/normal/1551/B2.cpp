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
const int N=200010;
vector<int>g[N];
int ans[N],p[N];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,k;scanf("%d%d",&n,&k);
        rep(i,n)g[i].clear(),ans[i]=0;
        rep(i,n){int x;scanf("%d",&x);g[x].pb(i);}
        int cnt=0;
        rep(i,n)
        {
            if(g[i].size()>=k)
            {
                rep(j,k)ans[g[i][j-1]]=j;
            }
            else for(auto j:g[i])p[++cnt]=j;
        }
        for(int i=1;i+k-1<=cnt;i+=k)rep(j,k)ans[p[i+j-1]]=j;
        rep(i,n)printf("%d%c",ans[i]," \n"[i==n]);
    }
    return 0;
}