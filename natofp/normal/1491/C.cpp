#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

const int nax = 5005;
ll a[nax];
int n;

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll ans = 0;

    for(int i=1;i<=n;i++) ans += (a[i] - 1);
    set<int> bigs;
    for(int i=n;i>=1;i--)
    {
        int to = a[i] + i;
        to = min(to, n);

        while(to > i + 1)
        {
            auto it = bigs.lower_bound(to);
            if(it == bigs.end())
            {
                to--;
            }
            else
            {
                int pos = *it;
                ans--;
                a[pos]--;
                if(a[pos] == 1) bigs.erase(pos);
                to--;
            }
        }

        if(a[i] > 1) bigs.insert(i);
    }
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