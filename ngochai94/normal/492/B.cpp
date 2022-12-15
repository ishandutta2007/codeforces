#include <bits/stdc++.h>
using namespace std;

long long  n,x,y,a,b,k,t,cur,l;
long long lis[2000002];

int gcd(int x,int y)
{
    if(x<y) return gcd(y,x);
    if(y==0) return x;
    return gcd(y,x-y);
}
int main()
{
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin>>n>>l;
    double ans=0;
    for (int i=0;i<n;i++) cin>>lis[i];
    sort(lis,lis+n);
    ans=max(lis[0],l-lis[n-1]);
    for (int i=1;i<n;i++) ans=max(ans,(lis[i]-lis[i-1])/2.0);
    cout<<setprecision(11)<<ans;
    return 0;
}