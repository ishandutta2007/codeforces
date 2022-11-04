#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
typedef long long ll;
const int MAXN=100005;
ll a[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    stack<ll> lef,rig;
    ll res=0,now=1;
    for(int i=1,j=0;i<=n;i++)
    {
        while(j<i || (j<=n && (lef.empty() ? 1 : lef.top())*now%k!=0))
        {
            j++;
            rig.push(a[j]);
            now=now*a[j]%k;
        }
        res+=n+1-j;
        if(lef.empty())
        {
            while(!rig.empty())
            {
                lef.push((lef.empty() ? 1 : lef.top())*rig.top()%k);
                rig.pop();
            }
            now=1;
        }
        lef.pop();
    }
    return 0*printf("%lld\n",res);
}