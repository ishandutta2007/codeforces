#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 51;

struct rect{
    ll x1,y1,x2,y2;
};

typedef ll Flow;
struct Edge {
	int dest, back;
	Flow f, c;
};

struct PushRelabel {
	vector<vector<Edge>> g;
	vector<Flow> ec;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

	void add_edge(int s, int t, Flow cap, Flow rcap=0) {
		if (s == t) return;
		g[s].push_back({t, sz(g[t]), 0, cap});
		g[t].push_back({s, sz(g[s])-1, 0, rcap});
	}

	void add_flow(Edge& e, Flow f) {
		Edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	Flow maxflow(int s, int t) {
		int v = sz(g); H[s] = v; ec[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i,0,v) cur[i] = g[i].data();
		trav(e, g[s]) add_flow(e, e.c);

		for (int hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -ec[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while (ec[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + sz(g[u])) {
					H[u] = 1e9;
					trav(e, g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						rep(i,0,v) if (hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
					add_flow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
};

set<ll> XS,YS;
vl X,Y;
vector<rect> R;

void inx(ll x){
    if(XS.find(x) == XS.end()){
        XS.insert(x);
        X.push_back(x);
    }
}

void iny(ll y){
    if(YS.find(y) == YS.end()){
        YS.insert(y);
        Y.push_back(y);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n >> m;
    rep(c1,0,m){
        cin >> a >> b >> c >> d;
        inx(a);inx(c+1);iny(b);iny(d+1);
        R.push_back({a,b,c,d});
    }


    if(m == 0){
        cout << "0\n";
        return 0;
    }

    sort(all(X));
    sort(all(Y));

    PushRelabel PR(sz(X) + sz(Y));

    rep(c1,0,sz(X)-1){
        PR.add_edge(0,c1+1,X[c1+1]-X[c1]);
    }

    rep(c1,0,sz(Y)-1){
        PR.add_edge(c1+sz(X),sz(X) + sz(Y) - 1,Y[c1+1]-Y[c1]);
    }

    rep(c1,0,sz(X)-1){
        rep(c2,0,sz(Y)-1){

            rep(c3,0,m){
                if(X[c1] >= R[c3].x1 && X[c1] <= R[c3].x2 && Y[c2] >= R[c3].y1 && Y[c2] <= R[c3].y2){
                    PR.add_edge(c1+1,c2+sz(X),big*big);
                    break;
                }
            }

        }
    }

    ll ans = PR.maxflow(0,sz(X)+sz(Y)-1);
    cout << ans << "\n";


    return 0;
}