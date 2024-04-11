#include <bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;
 
#define ll long long 
#define ull unsigned long long
#define ui unsigned int
#define mod 1000000007
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0); 
#define INF LONG_MAX
#define PI 3.1415926535897932384626
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define rep(x,j,n)for(int x=j;x<n;x++)
typedef vector<pair<ll,ll>> vpi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
 
ll modexp(ll a,ll b,ll m)
{
	ll r=1;
	a=a%m;
	while(b>0)
	{
		if(b&1)
		    r=(r*a)%m;
		b>>1;
		a=(a*a)%m;
	}
	return r%m;
}
 
int main(){
    ll n; cin>>n;
    vpi arr(n);
    rep(i,0,n)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    vi ans(n);
    rep(i,1,n)
    {
        ans[i]= ans[i-1]+arr[i-1].first;
    }
    ll x = INT_MAX ,y =INT_MIN,ind = -1;
    rep(i, 0 ,n)
    {
        if(arr[i].second==1)
            x= min(x,ans[i]);
        else
        {
            if(ans[i]>y)
            {
                y= ans[i];
                ind = i;
            }
        }
    }
    ll sum = 1899;
    if(x<=y)
    {
        cout<<"Impossible\n";
        return 0;
    }
    else
    {
        if(ind==-1)
            cout<<"Infinity\n";
        else
        {
            rep(i,ind,n)
            {
                sum+=arr[i].first;
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}