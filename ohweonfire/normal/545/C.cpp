//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
#define position(v) (lower_bound(pt.begin(),pt.end(),v)-pt.begin())
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
ll n,pos,ans;
pair<ll,ll>a[100111];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].FF>>a[i].SS;
    sort(a+1,a+1+n);
    pos=-LINF;
    for(int i=1;i<=n;i++)
    {
        if(a[i].FF-a[i].SS>pos&&(i==1||a[i].FF-a[i].SS>a[i-1].FF))ans++,pos=a[i].FF;
        if(a[i].FF>pos&&(i==n||a[i].FF+a[i].SS<a[i+1].FF))ans++,pos=a[i].FF+a[i].SS;
    }
    cout<<ans<<endl;
    return 0;
}