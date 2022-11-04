#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100005;
int x[MAXN],v[MAXN];
ll solve(int n,int l,int wm)
{
    vector<int> t[2];
    for(int i=1;i<=n;i++)
    {
        if(x[i]>=0)continue;
        t[v[i]==-1].push_back(x[i]);
    }
    for(int i=0;i<2;i++)
        sort(t[i].begin(),t[i].end());
    ll res=0;
    for(int i=0,j=0;i<(int)t[0].size();i++)
    {
        while(j<(int)t[1].size() && 1LL*(wm-1)*t[0][i]>=1LL*(wm+1)*(t[1][j]+l))j++;
        res+=(int)t[1].size()-j;
    }
    return res;
}
int main()
{
    int n,l,wm;
    scanf("%d%d%d",&n,&l,&wm);
    int cnt[2]={0,0};
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x[i],&v[i]);
        if(v[i]==1 && x[i]<0)cnt[0]++;
        if(v[i]==-1 && x[i]+l>0)cnt[1]++;
    }
    for(int i=1;i<=n;i++)
        if(x[i]<0 && x[i]+l>0)
        {
            x[i]=x[n],v[i]=v[n],n--;
            break;
        }
    ll res=1LL*cnt[0]*cnt[1];
    res+=solve(n,l,wm);
    for(int i=1;i<=n;i++)
        x[i]=-x[i]-l,v[i]=-v[i];
    res+=solve(n,l,wm);
    printf("%lld\n",res);
    return 0;
}