#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
priority_queue<pair<ll, pair<ll, ll> > > q;
int n, k;
ll t[200001];
ll c[200001];
bool ker(ll a)
{
    priority_queue<pair<ll, pair<ll, ll> > > q;
    for (int i=1; i<=n; i++) {
        q.push({-(t[i]/c[i]), {t[i], c[i]}});
    }
    for (int i=0; i<k; i++) {
        ll fi=q.top().first;
        ll sefi=q.top().second.first;
        ll sese=q.top().second.second;
        q.pop();
        if (i>-fi) {
            return false;
        }
        sefi+=a;
        q.push({-(sefi/sese), {sefi, sese}});
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> c[i];
    }
    ll x=-1, y=2000000000000;
    while(y-x>1) {
        ll z=(x+y)/2;
        if (ker(z)) {
            y=z;
        } else {
            x=z;
        }
    }
    if (y==2000000000000) {
        cout << -1 << "\n";
    } else {
        cout << y << "\n";
    }
    return 0;
}