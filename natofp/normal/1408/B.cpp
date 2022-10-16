#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define pii pair<int,int>

using namespace std;

const int nax = 105;
int a[nax];


void solve()
{
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k == 1)
    {
        bool ok = true;
        for(int i=1;i<n;i++)
        {
            if(a[i] != a[i+1]) ok = false;
        }
        if(ok) cout<<1<<"\n";
        else cout<<-1<<"\n";
        return;
    }
    int cnt = 1;
    for(int i=2;i<=n;i++)
    {
        if(a[i] != a[i-1]) cnt++;
    }
    int ans = 0;
    while(cnt > k)
    {
        cnt -= (k-1);
        ans++;
    }
    ans++;
    cout<<ans<<"\n";



}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--) solve();

    return 0;
}