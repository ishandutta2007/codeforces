#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=(1LL<<60)-1;
int solve()
{
    ll s,n,k,res=0;
    scanf("%lld%lld%lld",&s,&n,&k);
    if(s<k)return 0*printf("NO\n");
    if(s==k)return 0*printf("YES\n");
    if(s%k==0)res=(s/k)/2+(s/k+1)/2*(k-1);
    else res=(s/k+1)/2*(k-1-s%k)+(s/k+2)/2*(s%k-1)+(s/k)/2*2+1;
    //printf("%lld\n",res);
    return 0*printf("%s\n",(n>res ? "YES" : "NO"));
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}