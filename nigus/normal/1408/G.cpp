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

int edges[1501] = {0};

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b){
            edges[a]++;
            return 0;
		}
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		edges[a] += edges[b];
		edges[a]++;
		return true;
	}
};


ll A[1501][1501] = {0};

vector<pii> P;
bool comp(pii p1, pii p2){
    return A[p1.first][p1.second] < A[p2.first][p2.second];
}

vector<set<int> > C;

vi ind2;

bool comp2(int i, int j){
    return sz(C[i]) > sz(C[j]);
}


vector<vi> tree(100000, vi());
bool mark[100000] = {0};


unordered_map<ll,ll> DP;

int leaves[100000] = {0};
int dfs(int i){
    leaves[i] = 0;
    trav(y, tree[i]){
        leaves[i] += dfs(y);
    }
    if(leaves[i] == 0)leaves[i] = 1;
    return leaves[i];
}

ll dp(ll i, ll c, ll col){
    if(col < 0)return 0;
    if(sz(tree[i]) == 0)return (col == 1);
    if(c == sz(tree[i]))return (col == 0);
    ll h = 15001*15001*i + 15001*c + col;

    if(DP.find(h) != DP.end())return DP[h];
    ll ans = 0;

    int nex = tree[i][c];

    rep(c1,1,leaves[nex]+1){
        ans += dp(tree[i][c],0, c1) * dp(i,c+1,col-c1);
        ans %= mod;
    }
    if(col == 1 && c == 0)ans++;
    ans %= mod;
    DP[h] = ans;

   // cerr << i+1 << " c=" << c << " col=" << col << "  ans=" << ans << "\n";

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    int a,b,c,d,e;

    cin >> n;

    rep(c1,0,n){
        rep(c2,0,n){
            cin >> a;
            A[c1][c2] = a;
            if(c1 != c2)P.push_back({c1,c2});

        }
    }
    UF uf(n);
    sort(all(P), comp);
    trav(p,P){
        a = p.first;
        b = p.second;
        uf.join(a,b);
        int p2 = uf.find(a);
        int nodes = uf.size(p2);

       // cerr << a+1 << " - " << b+1 << "  p2: " << p2 << " n=" << nodes << " e=" << edges[p2] << "\n";

        if(nodes*nodes-nodes == edges[p2]){
            set<int> S;
            rep(c1,0,n){
                if(uf.find(c1) == p2)S.insert(c1);
            }
            C.push_back(S);
        }

    }

    rep(c1,0,n){
        set<int> S;
        S.insert(c1);
        C.push_back(S);
    }

    m = sz(C);

    rep(c1,0,m){
        ind2.push_back(c1);
    }
    sort(all(ind2),comp2);
    for(int c1 = m-1; c1 >= 0; c1--){
        int i = ind2[c1];

        rep(c2,c1+1,m){
            int j = ind2[c2];
            if(mark[j])continue;
            bool ispar = 0;
            trav(y, C[j]){
                if(C[i].find(y) != C[i].end()){ispar = 1;break;}
            }
            mark[j] = ispar;
            if(ispar){
                tree[i].push_back(j);
             //   cerr << i+1 << " - " << j+1 << "\n";
            }
        }
    }

/*
    rep(c1,0,m){
        trav(y, C[ind2[c1]]){
            cerr << y+1 << " ";
        }cerr << "\n";
    }
*/
    dfs(ind2[0]);
    rep(c1,0,n){
        ll temp = dp(ind2[0],0,c1+1);
        cout << temp << " ";
    }cout << "\n";

    return 0;
}