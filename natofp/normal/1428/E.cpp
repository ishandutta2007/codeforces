#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair

using namespace std;

const int nax = 1e5 + 5;

ll a[nax];

ll g(ll x)
{
    return x * x;
}

ll cost(ll ile, ll czesci)
{
    ll czesc = ile / czesci;
    ll rem = ile % czesci;

    ll duze = rem;
    ll male = czesci - duze;

    ll ans = duze * g(czesc + 1) + male * g(czesc);
    return ans;
}

ll cur[nax];

ll valdodam[nax];
ll valbiore[nax];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,k; cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);

    ll ans = 0;
    for(int i=1;i<n;i++) ans += cost(a[i],1);
    ans += cost(a[n],k - n + 1);

    if(k == n)
    {
        cout<<ans<<"\n";
        return 0;
    }

    for(int i=1;i<n;i++) cur[i] = 1;
    cur[n] = k - n + 1;

    for(int i=1;i<=n;i++)
    {
        valdodam[i] = valbiore[i] = -1e18;
    }

    multiset<pair<ll,ll> > dodam;
    for(int i=1;i<=n;i++)
    {
        pair<ll,ll> akt;
        akt.nd = i;
        akt.st = cost(a[i],cur[i]) - cost(a[i],cur[i] + 1);
        dodam.insert(akt);
        valdodam[akt.nd] = akt.st;
    }

    multiset<pair<ll,ll> > zabiore;
    pair<ll,ll> akt;
    akt.nd = n;
    akt.st = cost(a[n],cur[n] - 1) - cost(a[n],cur[n]);
    valbiore[akt.nd] = akt.st;
    zabiore.insert(akt);

    while(1)
    {


        pair<ll,ll> akt1 = *dodam.rbegin();

        pair<ll,ll> akt2 = *zabiore.begin();


        if(akt2.st >= akt1.st)
        {
            break;
        }


        dodam.erase(dodam.find(akt1));
        zabiore.erase(zabiore.find(akt2));

        valdodam[akt1.nd] = -1e18;
        valbiore[akt2.nd] - -1e18;

        int biore = akt1.nd;
        int wywalam = akt2.nd;

        ans -= cost(a[biore],cur[biore]) - cost(a[biore],cur[biore] + 1);

        ans -= cost(a[wywalam],cur[wywalam]) - cost(a[wywalam],cur[wywalam] - 1);

        cur[biore]++;
        cur[wywalam]--;

        if(valdodam[wywalam] != -1e18)
        {
            pair<ll,ll> xd = mp(valdodam[wywalam],wywalam);
            dodam.erase(dodam.find(xd));
            valdodam[wywalam] = -1e18;
        }

        if(valbiore[biore] != -1e18)
        {
            pair<ll,ll> xd = mp(valbiore[biore],biore);
            zabiore.erase(zabiore.find(xd));
            valbiore[biore] = -1e18;
        }


        pair<ll,ll> akt;
        akt.nd = biore;
        akt.st = cost(a[biore],cur[biore]) - cost(a[biore],cur[biore] + 1);
        dodam.insert(akt);
        valdodam[biore] = akt.st;


        akt.nd = wywalam;
        akt.st = cost(a[wywalam],cur[wywalam]) - cost(a[wywalam],cur[wywalam] + 1);
        dodam.insert(akt);
        valdodam[wywalam] = akt.st;


        if(cur[biore] > 1)
        {
            akt.nd = biore;
            akt.st = cost(a[biore],cur[biore] - 1) - cost(a[biore],cur[biore]);
            zabiore.insert(akt);
            valbiore[akt.nd] = akt.st;
        }

        biore = wywalam;

        if(cur[biore] > 1)
        {
            akt.nd = biore;
            akt.st = cost(a[biore],cur[biore] - 1) - cost(a[biore],cur[biore]);
            zabiore.insert(akt);
            valbiore[akt.nd] = akt.st;
        }


    }

    

    cout<<ans<<"\n";



    return 0;
}