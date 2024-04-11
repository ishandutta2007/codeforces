#pragma GCC optimize("O3")   //
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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

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

	void addEdge(int s, int t, Flow cap, Flow rcap=0) {
		if (s == t) return;
		g[s].push_back({t, sz(g[t]), 0, cap});
		g[t].push_back({s, sz(g[s])-1, 0, rcap});
	}

	void addFlow(Edge& e, Flow f) {
		Edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	Flow calc(int s, int t) {
		int v = sz(g); H[s] = v; ec[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i,0,v) cur[i] = g[i].data();
		trav(e, g[s]) addFlow(e, e.c);

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
					addFlow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
	bool leftOfMinCut(int a) { return H[a] >= sz(g); }
};


ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 2000001;

ll h,g;
ll moves;
vi A, prefer;
vi B;
int DEP[MAXN] = {0};


void solve(int i, int mv, int last){
    if(DEP[i] > g){
        rep(c1,0,mv-1){
            cout << i+1 << " ";
        }
    }
}

ll sum = 0;

int last_root[MAXN] = {0};

vector<pii> solve(int i, int mv){
    vector<pii> res;
    /*
    if(DEP[i] > g){
        rep(c1,0,mv){
            res.push_back({i,i});
        }
        return res;
    }
    */

    if(2*i+1 >= n){
        last_root[i] = i;
        return {{i,i}};
    }

    vector<pii> L,R;
    //cerr << i << "HEJ\n";
    L = solve(2*i+1, mv/2);
    R = solve(2*i+2, mv/2);
    int l = 0;
    int r = 0;
    int root = i;
    int lroot = A[L[0].second];
    int rroot = A[R[0].second];
    while(l < mv/2 || r < mv/2){
        /*
        if(i == 0){
            trav(l,L){
                cerr << l.first << " " << A[l.second] << "  LL\n";
            }
            trav(l,R){
                cerr << l.first << " " << A[l.second] << "  RR\n";
            }
        }
        */
        if(l != mv/2 && (r == mv/2 || lroot > rroot)){
          //  if(i == 0)cerr << lroot << " " << rroot << " fd\n";
            if(L[l].first == 2*i+1 && !(r == mv/2 && rroot > lroot)){
                res.push_back({i, root});
                root = L[l].second;
            }
            else{
                res.push_back({L[l].first, root});
            }
            l++;
        }
        else{
            if(R[r].first == 2*i+2 && !(l == mv/2 && lroot > rroot) ){
                res.push_back({i, root});
                root = R[r].second;
            }
            else{
                res.push_back({R[r].first, root});
            }
            r++;
        }

        if(l == mv/2){
            lroot = A[last_root[i*2+1]];
            if(DEP[2*i+1] > g){
                lroot = 0;
            }
        }
        else{
            lroot = A[L[l].second];
        }

        if(r == mv/2){
            rroot = A[last_root[2*i+2]];
            if(DEP[2*i+1] > g){
                rroot = 0;
            }
        }
        else{
            rroot = A[R[r].second];
        }
    }
    //cerr << i << "eh\n";
  //  cerr << A[root] << "  is root for " << i << "\n";

    last_root[i] = root;
    if(DEP[i] > g){
        res.push_back({i,root});
    }
    else{
        sum += A[root];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    DEP[0] = 1;
    rep(c1,1,MAXN){
        DEP[c1] = DEP[(c1+1)/2-1]+1;
    }

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> h >> g;
        n = (1 << h)-1;
        moves = n - (1 << g) + 1;
        A.clear();
        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
        }
        sum = 0;
        vector<pii> ANS = solve(0,moves);

        cout << sum << "\n";
        trav(p, ANS){
            cout << p.first+1 << " ";
        }cout << "\n";

    }

    return 0;
}