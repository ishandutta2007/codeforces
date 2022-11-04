#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN=250005;
const int MAXM=10000005;
const ll INF=(1LL<<60)-1;

vector<int> ta[MAXN],tc[MAXN];

int a[MAXM];
ll c[MAXM],dp[MAXM];

void init(int n,int m)
{
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        ta[i].resize(k);
        for(int j=0;j<k;j++)
            scanf("%d",&ta[i][j]);
        tc[i].resize(k);
        for(int j=0;j<k;j++)
            scanf("%d",&tc[i][j]);
    }
    int q;
    scanf("%d",&q);
    for(int i=1,s=0;i<=q;i++)
    {
        int id,mul;
        scanf("%d%d",&id,&mul);
        int k=(int)ta[id].size();
        for(int j=0;j<k;j++)
            a[++s]=ta[id][j],c[s]=1LL*mul*tc[id][j];
    }
}

stack<pair<int,ll> > stk_1;
stack<ll> stk_2;

int pop_cnt[MAXM];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    init(n,m);
    stk_1.push({m+1,0});
    stk_2.push(INF);
    for(int i=m;i>=1;i--)
    {
        int r=min(m,i+a[i]-1);
        while(r>=stk_1.top().first)stk_1.pop();
        pop_cnt[stk_1.top().first-1]++;
        stk_1.push({i,0});
    }
    while(!stk_1.empty())stk_1.pop();
    stk_1.push({0,0});
    for(int i=1;i<=m;i++)
    {
        int l=max(1,i-a[i]+1);
        ll val=dp[i-1];
        while(l<=stk_1.top().first)
        {
            val=min(val,stk_1.top().second);
            stk_1.pop();
        }
        stk_1.push({i,val});
        stk_2.push(min(stk_2.top(),dp[i-1]+c[i]));
        dp[i]=min(val+c[i],stk_2.top());
        for(int j=0;j<pop_cnt[i];j++)
            stk_2.pop();
    }
    printf("%lld\n",dp[m]);
    return 0;
}