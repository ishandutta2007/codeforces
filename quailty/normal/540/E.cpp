#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
map<int,int>p;
vector<pair<int,int> >aa;
vector<int>sec;
int cnt=0;
ll ans=0;
ll c[200005];
int lowbit(int x)
{
    return x&(-x);
}
void update(int p,ll k)
{
    for(int i=p;i<=cnt;i+=lowbit(i))
    {
        c[i]+=k;
    }
}
ll query(int p)
{
    ll res=0;
    for(int i=p;i>0;i-=lowbit(i))
    {
        res+=c[i];
    }
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a,b;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        if(p.find(a)==p.end())
        {
            p[a]=a;
        }
        if(p.find(b)==p.end())
        {
            p[b]=b;
        }
        swap(p[a],p[b]);
    }
    cnt=0;
    map<int,int>::iterator itr;
    for(itr=p.begin();itr!=p.end();itr++)
    {
        cnt++;
        aa.push_back(*itr);
        sec.push_back((*itr).second);
        //printf("%d %d\n",(*itr).first,(*itr).second);
    }
    sort(sec.begin(),sec.end());
    for(int i=cnt-1;i>0;i--)
    {
        int loc=lower_bound(sec.begin(),sec.end(),aa[i].second)-sec.begin()+1;
        ans+=query(loc-1);
        update(loc,1);
        //printf("++++%d\n",loc);
        int t=lower_bound(sec.begin(),sec.end(),aa[i-1].first+1)-sec.begin();
        int now=min(sec[t],aa[i].first-1)-aa[i-1].first;
        ans+=now*query(t);
        update(t,now);
    }
    int loc=lower_bound(sec.begin(),sec.end(),aa[0].second)-sec.begin()+1;
    ans+=query(loc-1);
    printf("%I64d\n",ans);
    return 0;
}