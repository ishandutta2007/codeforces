#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

const int nax = 105;
ll a[nax];
int n;
ll u,v;

void solve()
{
    cin>>n>>u>>v;
    for(int i=1;i<=n;i++) cin>>a[i];

    ll ans = (ll)2e9 + 100;

    for(int i=2;i<=n;i++)
    {
        if(abs(a[i] - a[i - 1]) > 1) ans = 0;
    }

    if(ans == 0)
    {
        cout<<ans<<"\n";
        return;
    }

    bool rowne = true;
    for(int i=2;i<=n;i++)
    {
        if(a[i] != a[i - 1]) rowne = false;
    }

    if(!rowne)
    {
        ans = min(u, v);
    }
    else ans = v + min(u, v);
    cout<<ans<<"\n";


}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}