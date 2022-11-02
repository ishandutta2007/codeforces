#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

typedef long long ll;

int n,a[N];

ll s[N];

vector<ll>x;

int c[N];

void add(int x,int v)
{
    while(x<=n)
    {
        c[x]+=v;
        x+=x&-x;
    }
}

int qry(int x)
{
    int ret=0;
    while(x)
    {
        ret+=c[x];
        x-=x&-x;
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),s[i]=s[i-1]+a[i],x.push_back(s[i]);
    sort(x.begin(),x.end());
    if(s[n]!=x.back())
    {
        puts("-1");
        return 0;
    }
    for(int i=1;i<=n;i++)
        if(s[i]<0)
        {
            puts("-1");
            return 0;
        }
    for(int i=1;i<=n;i++)
        s[i]=lower_bound(x.begin(),x.end(),s[i])-x.begin()+1;
    ll ans=0;
    for(int i=1;i<n;i++)
    {
        ans+=qry(n-s[i]);
        add(n-s[i]+1,1);
    }
    printf("%lld\n",ans); 
}