#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 5e5 + 100, inf = 1e9 + 100;

map<ll, ll> q;

ll pw(ll x){
    ll ret = 0;
    while (x > 0)
        x >>= 1, ret++;
    if (ret == 0)
        ret++;
    return ret;
}

ll lca(ll x, ll y){
    ll a = pw(x), b = pw(y);
    if (a < b)
        swap(a, b), swap(x, y);
    while (a > b)
        x >>= 1, a--;
    while (x != y)
        x >>= 1, y >>= 1;
    return x;
}

vector<ll> path(ll x, ll y){
    if (x > y)
        swap(x, y);
    vector<ll> ret;
    while (y != x){
        ret.push_back(y);
        y >>= 1;
    }
    return ret;
}

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    int zap;
    cin >> zap;
    for (int it = 0; it < zap; it++){
        int type;
        cin >> type;
        if (type == 1){
            ll x, y, w;
            cin >> x >> y >> w;
            ll z = lca(x, y);
            vector<ll> p = path(x, z);
            for (int i = 0; i < p.size(); i++)
                q[p[i]] += w;
            p = path(y, z);
            for (int i = 0; i < p.size(); i++)
                q[p[i]] += w;
        }
        else{
            ll x, y;
            cin >> x >> y;
            ll ans = 0;
            ll z = lca(x, y);
            vector<ll> p = path(x, z);
            for (int i = 0; i < p.size(); i++)
                ans += q[p[i]];
            p = path(y, z);
            for (int i = 0; i < p.size(); i++)
                ans += q[p[i]];
            cout << ans << '\n';
        }
    }
}