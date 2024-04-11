#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,h[1000001],sum,i,j;
ll l,r,mid;
ll arr[10001];
vector<ll> bruh;
vector<pair<ll,ll>> res;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>arr[i];
        bruh.push_back(i);
    }
    sort(bruh.begin(),bruh.end(),[](ll a, ll b){
        if (arr[a]-arr[b]) return (arr[a]>arr[b]);
        return (a>b);
    });
    for (i=0;i<n;i++)
    {
        for (j=1;j<bruh[i];j++) if (arr[j]>arr[bruh[i]]) res.push_back({j,bruh[i]});
    }
    cout<<res.size()<<endl;
    for (pair<ll,ll> g : res) cout<<g.first<<' '<<g.second<<endl;
}