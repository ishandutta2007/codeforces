#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const int MAXM=100005;
ll a[MAXN],b[MAXM];
vector<pair<int,int> >e;
bool check(int n,int m,ll t)
{
    e.clear();
    for(int i=1;i<=m;i++)
    {
        int l=lower_bound(a+1,a+n+1,b[i]-t)-a;
        int r=upper_bound(a+1,a+n+1,b[i]+t)-a-1;
        e.push_back(make_pair(l-1,-1));
        e.push_back(make_pair(r,1));
    }
    sort(e.begin(),e.end());
    int sum=0,la=0,cnt=0;
    for(int i=0;i<(int)e.size();i++)
    {
        if(cnt>0)sum+=e[i].first-la;
        cnt-=e[i].second;
        la=e[i].first;
    }
    return sum==n;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%I64d",&b[i]);
    ll l=0,r=2000000000;
    while(l<r)
    {
        ll t=(l+r)/2;
        if(check(n,m,t))r=t;
        else l=t+1;
    }
    return 0*printf("%I64d",l);
}