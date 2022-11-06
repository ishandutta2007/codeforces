#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pii pair<int , int>
#define pll pair<long long int,long long int>
#define mod 1000000007
#define inf 1e18+7
#define eps 0.00001
#define endl '\n'
int main()
{
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ll n,p;
    cin>>n>>p;
    ll a[n],b[n]={0};
    for(ll i=0;i<n;i++)
        cin>>a[i];
    b[0]=a[0];
    for(ll i=1;i<n;i++)
        b[i]+=a[i]+b[i-1];
    ll t=b[n-1];
    ll max=-1;
    for(ll i=0;i<n;i++)
    {
        ll x=b[i]%p,y=(t-b[i])%p;
        ll z=x+y;
        if(z>max)
            max=z;
    }
    cout<<max;
}