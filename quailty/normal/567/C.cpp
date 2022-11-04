#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll a[MAXN];
map<ll,ll>cnt1,cnt2;
int main()
{
    ll n,k;
    scanf("%I64d%I64d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    ll res=0;
    cnt1[a[1]]++;
    if(a[2]==k*a[1])cnt2[a[2]]++;
    for(int i=3;i<=n;i++)
    {
        if(a[i]%k==0)
            if(cnt2.find(a[i]/k)!=cnt2.end())
                res+=cnt2[a[i]/k];
        cnt1[a[i-1]]++;
        if(a[i]%k==0)cnt2[a[i]]+=cnt1[a[i]/k];
    }
    printf("%I64d\n",res);
    return 0;
}