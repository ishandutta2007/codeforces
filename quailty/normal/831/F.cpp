#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=105;
ll a[MAXN];
int main()
{
    int n;
    ll k;
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]),a[i]--;
    vector<ll> key;
    key.push_back(0);
    key.push_back(1e12);
    for(int _=1;_<=n;_++)
    {
        ll t;
        for(t=1;t*t<=a[_];t++)
            key.push_back(t);
        for(ll i=a[_]/t;i>0;i--)
            key.push_back(a[_]/i);
    }
    sort(key.begin(),key.end());
    key.erase(unique(key.begin(),key.end()),key.end());
    ll res=1,rhs=n+k;
    for(int i=1;i<=n;i++)
        rhs+=a[i];
    for(int i=0;i+1<(int)key.size();i++)
    {
        ll c=n,d=key[i]+1;
        for(int j=1;j<=n;j++)
            c+=a[j]/d;
        ll t=rhs/c;
        if(t>key[i])res=max(res,min(t,key[i+1]));
    }
    return 0*printf("%lld",res);
}