#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll c=2002, mod=1000000007;
ll n, m, p, sum, dist[c];
vector<int> sz[c], s[c];
vector<pair<int, int> > ut;
vector<pair<int, pair<int, int> > > el;
priority_queue<pair<int, int> > q;
bool v[c];
ll mp(pair<int, int> x, pair<int, int> y) {
    ll a=x.first, b=x.second, c=y.first, d=y.second, e=a-c, f=d-b;
    if (e==0) {
        if (f<0) return 0;
        else return p+1;
    }
    return f/e+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> p;
    for (ll i=1; i<=m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        sz[a].push_back(b), sz[b].push_back(a), s[a].push_back(c), s[b].push_back(c);
        el.push_back({c, {a, b}});
    }
    sort(el.begin(), el.end());
    for (ll i=0; i<m; i++) {
        ll h=el[i].first, fi=el[i].second.first, se=el[i].second.second;
        for (ll i=1; i<=n; i++) v[i]=0, dist[i]=0;
        q.push({0, 1});
        while(q.size()>0) {
            ll t=q.top().first, id=q.top().second;
            q.pop();
            if (!v[id]) {
                v[id]=true, dist[id]=t;
                for (ll i=0; i<sz[id].size(); i++) {
                    ll x=sz[id][i], y=s[id][i];
                    if (!v[x] && y<=h) q.push({t-h+y, x});
                }
            }
        }
        if (v[fi]) {
            ll mini=min(dist[fi], dist[se]);
            pair<int, int> x={h, mini};
            ll si=ut.size();
            while(si>=2 && mp(ut[si-1], ut[si-2])>=mp(x, ut[si-1])) ut.pop_back(), si--;
            while(si>=1 && mp(x, ut[si-1])<=1) ut.pop_back(), si--;
            if (!si || mp(x, ut[si-1])<=p) ut.push_back(x);
        }
    }
    for (ll i=0; i<ut.size(); i++) {
        ll kezd, veg;
        if (i==0) kezd=0;
        else kezd=mp(ut[i], ut[i-1])-1;
        if (i+1==ut.size()) veg=p;
        else veg=mp(ut[i+1], ut[i])-1;
        sum+=(veg-kezd)*ut[i].second, sum%=mod;
        sum+=(veg*(veg+1)-kezd*(kezd+1))/2%mod*ut[i].first, sum%=mod;
    }
    cout << (sum+mod*mod)%mod << "\n";
    return 0;
}