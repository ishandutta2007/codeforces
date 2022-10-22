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

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 200002;

vector<vi> C(MAXN, vi());

vi X;
map<int,int> M;

vector<vi> XX;

vi D;

void dfs1(int i, int par){
    if(par != -1){
        D[i] += D[par];
    }
    trav(y, C[i]){
        if(y != par){
            dfs1(y,i);
        }
    }
}

bool mark[MAXN] ={0};

bool dfs2(int i, int par){
    if(mark[X[i]])return 0;
    bool res = 1;
    mark[X[i]] = 1;
    trav(y, C[i]){
        if(y != par){
            res &= dfs2(y, i);
        }
    }
    mark[X[i]] = 0;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n;
    rep(c1,0,n){
        cin >> a;
        D.push_back(0);

        if(M.find(a) == M.end()){
            M[a] = sz(XX);
            vi temp;
            XX.push_back(temp);
        }
        a = M[a];
        XX[a].push_back(c1);
        X.push_back(a);
    }
    rep(c1,0,n-1){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }

    LCA lca(C);

    rep(c1,0,sz(XX)){
        int L = XX[c1][0];
        rep(c2,1,sz(XX[c1])){
            L = lca.lca(L, XX[c1][c2]);
        }
        if(sz(XX[c1]) < 2)continue;
        if(X[L] == c1){
            a = -1;
            int other = XX[c1][0];
            if(other == L)other = XX[c1][1];

            trav(y, C[L]){
                if(lca.lca(y, L) == L && lca.lca(other, y) == y)a = y;
            }
            assert(a != -1);
            D[0]++;
            D[a]-=2;
        }
        trav(i, XX[c1]){
            D[i]++;
        }
    }

    dfs1(0,-1);

    vi ANS;
    rep(c1,0,n){
        if(D[c1] == 0)ANS.push_back(c1);
    }
    if(sz(ANS) > 0 && !dfs2(ANS[0], -1)){
        cout << "0\n";
    }
    else{
        cout << sz(ANS) << "\n";
    }



    return 0;
}