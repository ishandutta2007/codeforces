#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <iostream>
#include <algorithm>

#define X first
#define Y second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair < ll,ll> pii;
typedef pair < ll,pii> pip;

const ll N = 1e5 + 500;

ll g, r, n, q, l[N], ad[N];
set < pip > s;
vector < pii > v;
vector <ll > rrr;
map < ll, ll> mp;

bool llerval(ll l, ll rr, ll x){
    if(rr < 0) rr += (g + r);
    if(l <= rr) return (l <= x && x <= rr);
    return (x >= l || x <= rr);
}

ll dif(ll x, ll y){
    x %= (g + r);y %= (g + r);
    if(x <= y) return y - x;
    return (g + r) - (x - y);
}

void add(pii A, ll x){
    if(A.X <= A.Y){
        ad[A.X] += x;
        ad[A.Y] -= x;
    }
    else{
        ad[0] += x;
        ad[A.Y] -= x;
        ad[A.X] += x;
    }
}

ll neg(ll x){
    if(x > 0) return x % (g + r);
    else return ((g + r) - (-x)%(g + r)) % (g + r);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> g >> r;
    for(ll i = 0;i<=n;i++) cin >> l[i];
    cin >> q;
    for(ll i = 0;i<q;i++){
        ll x;cin >> x;
        v.PB(MP(x % (g + r), x));
        rrr.PB(x);
    }
    sort(v.begin(),v.end());
    for(ll i = 0;i<v.size();){
        ll j = i;
        while(i < v.size() && v[j].X == v[i].X) i++;
        s.insert(MP(v[j].X , MP(j, i)));
    }
    ll all = 0;
    for(ll i = 0;i<=n;i++){
        ad[0] += l[i];
        if(i == n) continue;
        all = neg(all - l[i]);
        auto it = s.lower_bound(MP((all + g) % (g + r), MP(0,0)));
        if(it == s.end()) it = s.begin();
        ll l = it->Y.X, rr = -1;
        while(llerval((all + g) % (g + r), all, it->X)){
            add(it->Y, dif(it->X, all));
            rr = it->Y.Y;
            auto old = it;
            it++;
            if(it != s.end() && old->Y.Y != q && old->Y.Y != it->Y.X) return -1;
            s.erase(old);
            if(s.empty()) break;
            if(it == s.end()) it = s.begin();
        }
        if(l == rr)
            l = 0, rr = q;
        if(rr == -1) continue;
        s.insert(MP(all , MP(l, rr)));
    }
    ll cur = 0;
    for(ll i = 0;i<q;i++){
        cur += ad[i];
        mp[v[i].Y] = cur + v[i].Y;
    }
    for(ll x : rrr){
        cout << mp[x] << "\n";
    }
}