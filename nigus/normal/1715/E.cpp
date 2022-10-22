#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;
 
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);
 
ll random2(){
    return (1ll << 31ll)*eng()+eng();
}
 
ll n,m,k,q,T;
 
const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 200001;

const ll inf = big*big;

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
        if(empty())return -big*big;
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

vector<vi> C(MAXN, vi());
vector<vl> CW(MAXN, vl());

ll dist[MAXN] = {0};
int mark[MAXN] = {0};
int cc = 0;

void dijkstra(){
    priority_queue<pll> pq;
    cc++;
    rep(c1,0,n){
        if(dist[c1] != inf){
            pq.push({-dist[c1], c1});
        }
    }
    while(!pq.empty()){
        int a = pq.top().second;
        pq.pop();
        if(mark[a] != cc){
            mark[a] = cc;
            rep(c1,0,sz(C[a])){
                ll w = CW[a][c1];
                int b = C[a][c1];
                if(dist[b] > dist[a] + w){
                    dist[b] = dist[a] + w;
                    pq.push({-dist[b], b});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll a,b,c,d;
    
    cin >> n >> m >> k;
    rep(c1,0,m){
        cin >> a >> b >> c;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
        CW[a].push_back(c);
        CW[b].push_back(c);
    }

    rep(c1,0,n){
        dist[c1] = inf;
    }
    dist[0] = 0;

    dijkstra();
    rep(c1,0,k){
        LineContainer LC;
        vl dist2;
        rep(c2,0,n){
            dist2.push_back(dist[c2]);
        }

        rep(c2,0,n){
            ll d2 = ll(c2)*ll(c2) - LC.query(ll(c2));
            if(d2 < dist2[c2]){
                dist2[c2] = d2;
            }
            LC.add(2*ll(c2), -dist[c2] - ll(c2)*ll(c2));
        }

        LineContainer LC2;
        for(int c2 = n-1; c2 >= 0; c2--){
            ll d2 = ll(c2)*ll(c2) - LC2.query(ll(c2));
            if(d2 < dist2[c2]){
                dist2[c2] = d2;
            }
            LC2.add(2*ll(c2), -dist[c2] - ll(c2)*ll(c2));
        }
        rep(c2,0,n){
            dist[c2] = dist2[c2];
        }
        dijkstra();
    }

    rep(c1,0,n){
        cout << dist[c1] << " ";
    }cout << "\n";
    
    return 0;
}