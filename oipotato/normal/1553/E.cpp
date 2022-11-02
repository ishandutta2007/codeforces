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
const int N=300010;
int cnt[N],p[N],fa[N],n,m;
vector<int>ans;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
bool check(int k)
{
    rep(i,n)fa[i]=i;
    rep(i,n)fa[find(i)]=find((p[i]+k-1)%n+1);
    int num=n;
    rep(i,n)if(find(i)==i)num--;
    return num<=m;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%d%d",&n,&m);
        rep(i,n)cnt[i-1]=0;
        rep(i,n){scanf("%d",&p[i]);cnt[(i-p[i]+n)%n]++;}
        ans.clear();
        for(int i=0;i<n;i++)if(cnt[i]>=n-2*m&&check(i))ans.pb(i);
        printf("%d",(int)ans.size());for(auto i:ans)printf(" %d",i);puts("");
    }
    return 0;
}