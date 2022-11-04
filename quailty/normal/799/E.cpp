#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long ll;

const int MAXN=200005;
const ll INF=(1LL<<60)-1;

int c[MAXN],lik[MAXN];
vector<int> val[4];

priority_queue<int> lef,rig;
ll kth,tot;

void modify()
{
    while((int)lef.size()>kth)
    {
        rig.push(-lef.top());
        tot-=lef.top();
        lef.pop();
    }
    while((int)lef.size()<kth && !rig.empty())
    {
        lef.push(-rig.top());
        tot-=rig.top();
        rig.pop();
    }
}

void add(int x)
{
    if(lef.empty() || x>lef.top())rig.push(-x);
    else lef.push(x),tot+=x;
    modify();
}

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=0;i<2;i++)
    {
        int t,x;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d",&x);
            lik[x]|=(1<<i);
        }
    }
    for(int i=1;i<=n;i++)
        val[lik[i]].push_back(c[i]);
    for(int i=1;i<4;i++)
        sort(val[i].begin(),val[i].end());
    int cnt[3]={0,0,0};
    ll sum=0,res=INF;
    for(int _=1;_<=2;_++)
    {
        for(int i=0;i<k && i<(int)val[_].size();i++)
            sum+=val[_][i],cnt[_]++,cnt[0]++;
        for(int i=k;i<(int)val[_].size();i++)
            val[0].push_back(val[_][i]);
    }
    kth=max(0,m-cnt[0]);
    for(int i=0;i<(int)val[0].size();i++)
        add(val[0][i]);
    if(cnt[1]==k && cnt[2]==k && cnt[0]+(int)lef.size()==m)
        res=sum+tot;
    for(int i=0;i<(int)val[3].size();i++)
    {
        sum+=val[3][i],cnt[0]++;
        for(int j=1;j<=2;j++)
            if(cnt[j]>=max(1,k-i))
            {
                sum-=val[j][--cnt[j]];
                add(val[j][cnt[j]]);
                cnt[0]--;
            }
        kth=max(0,m-cnt[0]);
        modify();
        if(cnt[1]>=k-i-1 && cnt[2]>=k-i-1 && cnt[0]+(int)lef.size()==m)
            res=min(res,sum+tot);
    }
    return 0*printf("%lld\n",(res<INF ? res : -1));
}