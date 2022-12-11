#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll N = (ll)2e5 + 10;
const ll inf = (ll)1e9;
vector<ll> d[N];

ll n, m;



struct sols{
    ll xv;
    ll yv;
    ll xs;
    ll ys;
};

struct Rect{
    ll cl;
    ll cr;
    ll tl;
    ll x1;
    ll b;
};

sols xy[N];
vector<Rect> qq[N];
ll seg[N * 4 + 512];

void upd(ll node, ll cl, ll cr, ll pos, ll v){
    if(cl == cr){
        seg[node] = v;
        return ;
    }
    ll mid = (cl + cr) / 2;
    if(mid >= pos)
        upd(node * 2, cl, mid, pos, v);
    else
        upd(node * 2 + 1, mid + 1, cr, pos, v);
    seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
}

ll get(ll node, ll cl, ll cr, ll tl, ll tr){
    if(cr < tl || cl > tr)
        return 0ll;
    if(cl >= tl && cr <= tr){
        return seg[node];
    }
    ll mid = (cl + cr) / 2;
    return max(get(node * 2, cl, mid, tl, tr), get(node * 2 + 1, mid + 1, cr, tl, tr));
}

vector<ll> g[N];

int main(){
    fastIO;
    cin >> n >> m;
    ll li, ri;
    cin >> li >> ri;
    for(ll i = 1; i < N ; i ++ ){
        for(ll j = i; j < N; j += i){
            d[j].push_back(i);
            g[i].push_back(j);
        }
    }
    for(ll i = 1; i <= n; i ++ )
        xy[i] = {-1,-1,-1,-1};
    ll lf, rf;
    ll pi, qi;
    ll low;
    ll x2, y1, y2;
    ll kk;
    for(ll x1 = 1; x1 <= n; x1 ++ ){
        lf = (li+x1-1)/x1;
        rf = ri/x1;
        if(lf <= rf){
            for(auto b : d[x1]){
                if(b > m) continue;
                pi = b + 1;

                qi = min(m, (n * 1ll * b) / x1);
                qq[qi].push_back({lf, rf, pi, x1, b});
                /*
                low = get(1, 1, (ll)m, lf, rf, (ll)pi, (ll)qi);
                if(low != inf){
                    x2 = x1*low/b;
                    kk = (lf + low - 1) / low;
                    y1 = kk * low;
                    y2 = b * kk;
                    cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
                    sol = true;
                    break;
                }
                */
            }
        }
    }
    ll sol;
    for(ll i = 1; i <= n; i ++ ){
        for(auto p : g[i]){
            if(p <= m)
                upd(1, 1, m, p, i);
        }
        for(auto q : qq[i]){
            if(xy[q.x1].xs != -1) continue;
            sol = get(1, 1, m, q.cl, q.cr);
            if(sol >= q.tl){
                x2 = q.x1*sol/q.b;
                kk = (q.cl + sol - 1) / sol;
                y1 = kk * sol;
                y2 = q.b * kk;
                xy[q.x1] = {q.x1, y1, x2, y2};
            }
        }
    }
    for(ll i = 1; i <= n; i ++ ){
        if(xy[i].xs == -1) cout << "-1\n";
        else{
            cout << xy[i].xv << " " << xy[i].yv << " " << xy[i].xs << " " << xy[i].ys << "\n";
        }
    }
    return 0;
}