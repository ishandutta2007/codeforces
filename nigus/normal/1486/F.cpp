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

const int MAXN = 300001;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	int T = 0;
	vi time, path, ret;
	RMQ<int> rmq;

	LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
	void dfs(vector<vi>& C, int v, int par) {
		time[v] = T++;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	//dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};

vector<vi> C(MAXN, vi());
vector<vi> CC(MAXN, vi());

int pre[MAXN] = {0};
int SS[MAXN] = {0};
int seen = 0;
int level[MAXN] = {0};

vi ind;

void dfs1(int i, int par){
    pre[i] = seen;
    seen++;
    SS[i] = 1;
    trav(y, C[i]){
        if(y != par){
            level[y] = 1+level[i];
            dfs1(y, i);
            SS[i] += SS[y];
            CC[i].push_back(y);
        }
    }
}

int find_next(int i, int j){
    if(i == j)return -1;
    if(SS[CC[j][0]] + pre[CC[j][0]] > pre[i])return CC[j][0];
    int l = 0;
    int r = sz(CC[j])-1;
    while(l < r-1){
        int mid = (l+r)/2;
        if(SS[CC[j][mid]] + pre[CC[j][mid]] > pre[i]){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    return CC[j][r];
}

struct query{
    int u, v, u2, v2;
};

vector<vector<query> > Q(MAXN, vector<query>());
FT ft(MAXN+1);

ll subtree(int i){
    if(i == -1)return 0;
    return ft.query(pre[i]+SS[i]) - ft.query(pre[i]);
}

bool comp(ll i, ll j){
    return level[i] < level[j];
}

ll dsp(vector<pii> P){
    map<ll,ll> M, M2;
    ll res = 0;
    rep(c1,0,sz(P)){
        if(P[c1].first > P[c1].second){
            swap(P[c1].first, P[c1].second);
        }
        ll x = P[c1].first;
        ll y = P[c1].second;

      //  cerr << x << " " << y << "  -  " << res << "  hej\n";

        if(x == -1 && y == -1){
            res += ll(c1);
        }
        else{
            if(x == -1){
                if(M.find(y) == M.end())M[y] = 0;
                res += c1 - M[y];
                M[y]++;
            }
            else{
                ll h = x*(MAXN+4314123)+y;
                if(M.find(x) == M.end())M[x] = 0;
                if(M.find(y) == M.end())M[y] = 0;
                if(M2.find(h) == M2.end())M2[h] = 0;
                res += c1 - M[x] - M[y] + M2[h];
                M[x]++;
                M[y]++;
                M2[h]++;
            }
        }
    }
  //  cerr << "result: " << res << "\n";
    return res;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n;
    rep(c1,0,n-1){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    LCA lca(C);
    dfs1(0,-1);

    cin >> m;

    if(n == 1){
        cout << (m*(m-1))/2 << "\n";
        return 0;
    }

    rep(c1,0,m){
        cin >> a >> b;
        a--;
        b--;
        c = lca.lca(a, b);
        Q[c].push_back({a, b, find_next(a, c), find_next(b, c)});
    }

    rep(c1,0,n){
        ind.push_back(c1);
    }
    sort(all(ind), comp);

    ll cuts = 0;
    ll dsj = 0;
    rep(c1,0,n){
        int L = ind[c1];
        if(sz(Q[L]) == 0)continue;
        ll sum = subtree(L);
        ll cuts2 = 0;
        rep(c2,0,sz(Q[L])){
            a = Q[L][c2].u2;
            b = Q[L][c2].v2;
            cuts2 += (sum - subtree(a) - subtree(b));
        //    if(L == 9)cerr << a+1 << " " << b+1 << "  -  " << subtree(b) << "\n";
        }
        //cerr << L+1 << ": " << cuts2 << "\n";
        cuts += cuts2;
        rep(c2,0,sz(Q[L])){
            ft.update(pre[Q[L][c2].u], 1);
            ft.update(pre[Q[L][c2].v], 1);
        }

        vector<pii> P;
        rep(c2,0,sz(Q[L])){
            P.push_back({Q[L][c2].u2, Q[L][c2].v2});
        }
        dsj += dsp(P);

    }

    ll ans = cuts+dsj;
    cout << ans << "\n";

    return 0;
}