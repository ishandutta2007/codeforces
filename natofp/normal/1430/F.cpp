#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair

using namespace std;

const int nax = 2005;

int lo[nax];
int hi[nax];
int cnt[nax];

vector<pair<ll,ll> > pop;
vector<pair<ll,ll> > nxt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,k; cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>lo[i]>>hi[i]>>cnt[i];
    }
    lo[n+1] = 1e9 + 5;
    hi[n+1] = 1e9 + 5;
    cnt[n+1] = 0;

    pop.pb(mp(k,0));

    for(int i=1;i<=n;i++)
    {
        nxt.clear();
        ll cand = 1e18;
        int l = lo[i];
        int h = hi[i];
        int ile = cnt[i];
        for(auto akt : pop)
        {
            ll kule = akt.st;
            ll wasted_before = akt.nd;

            ll tmp = ile - kule;
            ll czas = (tmp+k-1)/k;
            ll koniec = l + czas;

            if(koniec > h)
            {
                continue;
            }

            ll wasted_now = wasted_before + ile;

            ll zostalo = (k - tmp % k) % k;

            nxt.pb(mp(zostalo,wasted_now));

            // wyjebansko

            if(koniec < lo[i+1])
            {
                wasted_now += zostalo;
                cand = min(cand,wasted_now);
            }
        }
        if(cand < 1e18) nxt.pb(mp(k,cand));

        pop = nxt;

    }

    ll ans = 1e18;
    for(auto akt : nxt)
    {
        ans = min(ans,akt.nd);
    }
    if(ans == 1e18) ans = -1;
    cout<<ans;


    return 0;
}