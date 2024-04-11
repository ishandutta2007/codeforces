#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
int l[MAXN],vis[MAXN];
pair<int,int>mx[MAXN];
vector<int>val[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        mx[i].second=i;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        mx[a].first=max(mx[a].first,b);
        val[a].push_back(b);
    }
    sort(mx+1,mx+n+1);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int k;
        scanf("%d",&k);
        for(int i=0;i<k;i++)
            scanf("%d",&l[i]),vis[l[i]]=1;
        int res=0,mi=0;
        for(int i=n;i>=1;i--)
        {
            if(!mx[i].first)break;
            if(vis[mx[i].second])continue;
            if(!res)res=mx[i].second;
            else
            {
                mi=mx[i].first;
                break;
            }
        }
        printf("%d %d\n",res,(res ? *lower_bound(val[res].begin(),val[res].end(),mi) : 0));
        for(int i=0;i<k;i++)
            vis[l[i]]=0;
    }
    return 0;
}