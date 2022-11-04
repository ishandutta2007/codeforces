#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=100005;
ll a[MAXN];
map<ll,int>mp;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    ll tot=0;
    mp.clear();
    for(int i=0;i<n;i++)
    {
        tot+=a[i];
        mp[tot]++;
    }
    int ans=n-mp[0];
    ll off=0;
    for(int i=0;i<n;i++)
    {
        off+=a[i];
        ans=min(ans,n-mp[off]);
    }
    printf("%d\n",ans);
    return 0;
}