#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int n,v,t[N],a[N],c[N];

typedef pair<int,int> pii;

vector<int>X,Y;

vector<pii>s;

void add(int x,int v)
{
    while(x<=n)
    {
        c[x]=max(c[x],v);
        x+=x&-x;
    }
}

int qry(int x)
{
    int ret=0;
    while(x)
    {
        ret=max(ret,c[x]);
        x-=x&-x;
    }
    return ret;
}

signed main()
{
    scanf("%lld%lld",&n,&v);
    for(int i=1;i<=n;i++)
        scanf("%lld",&t[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
    {
        if(abs(a[i])>v*t[i])
            continue;
        int x=a[i]+v*t[i];
        int y=-a[i]+v*t[i];
        X.push_back(x),Y.push_back(y);
        s.push_back({x,y});
    }
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    sort(s.begin(),s.end());
    int ans=0;
    for(auto [x,y]:s)
    {
        y=lower_bound(Y.begin(),Y.end(),y)-Y.begin()+1;
        int fx=qry(y)+1;
        ans=max(ans,fx);
        add(y,fx);
    }
    printf("%lld\n",ans);
}