#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll b[MAXN];
int solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&b[i]);
    for(int i=n;i>=1;i--)
        b[i]-=b[i-1];
    ll res=0;
    for(int i=2;i<=n;i++)
    {
        if(b[i]>0)res+=b[i];
        else res-=b[i],b[1]+=b[i];
    }
    return 0*printf("%lld\n",res+abs(b[1]));
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}