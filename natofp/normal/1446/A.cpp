#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

void solve()
{
    ll n,w; cin>>n>>w;
    vector<pair<ll,int> > a;
    for(int i=1;i<=n;i++)
    {
        ll x; cin>>x;
        a.pb(mp(x,i));
    }

    sort(a.begin(),a.end());

    int wsk = a.size() - 1;
    while(wsk >= 0 && a[wsk].st > w) wsk--;

    if(wsk < 0)
    {
        cout<<-1<<"\n";
        return;
    }

    ll sum = 0;
    vector<int> ans;
    while(wsk >= 0)
    {
        sum += a[wsk].st;
        ans.pb(a[wsk].nd);
        wsk--;
        if(sum >= (w+1) / 2) break;
    }

    if(sum < (w+1) / 2) cout<<-1<<"\n";
    else
    {
        cout<<ans.size()<<"\n";
        for(int x : ans) cout<<x<<" ";
        cout<<"\n";
    }


}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}