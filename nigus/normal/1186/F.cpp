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

const int MAXN = 1000005;

int D[MAXN] = {0};
int its[MAXN] = {0};

vi eulerWalk(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi eu(nedges), ret;
	vector<pii> s = {{src, -1}};
	D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		pii x = s.back();
		int y, e, &it = its[x.first], end = sz(gr[x.first]);
		if (it == end){ ret.push_back(x.second); s.pop_back(); continue; }
		tie(y, e) = gr[x.first][it++];
		if (!eu[e]) {
			D[x.first]--, D[y]++;
			eu[e] = 1; s.push_back({y, e});
		}}
	//for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
	return {ret.rbegin(), ret.rend()};
}

vector<vector<pii> > C(MAXN, vector<pii>());

vector<vector<pii> > C2(MAXN, vector<pii>());
int start = 0;

int deg[MAXN] = {0};
int deg2[MAXN] = {0};
vi A,B,ind;


int EE[2*MAXN] = {0};

bool mark[MAXN] = {0};
int degsum(int i){
    vi Q;
    Q.push_back(i);
    int ans = 0;
    while(!Q.empty()){
        int a = Q.back();
        Q.pop_back();
        if(!mark[a]){
            mark[a] = 1;
            D[a] = 0;
            its[a] = 0;
            ans += deg[a];
            if(a == n)ans += deg[a];
            trav(y, C[a]){
                int j = y.first;
                if(!mark[j]){
                    EE[start] = y.second;
                    C2[a].push_back({j, start});
                    C2[j].push_back({a, start});
                    start++;
                    Q.push_back(j);
                }
            }
        }
    }
    return ans;
}

bool taken[2*MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n >> m;
    rep(c1,0,m){
        cin >> a >> b;
        a--;
        b--;
        A.push_back(a);
        B.push_back(b);
        ind.push_back(c1);
        deg[a]++;
        deg[b]++;
        C[a].push_back({b, c1});
        C[b].push_back({a, c1});

    }
    int m2 = m;
    rep(c1,0,n){
        if(deg[c1]%2 != 0){
            C[n].push_back({c1, m2});
            C[c1].push_back({n, m2});
            deg[n]++;
            m2++;

        }
    }

    vi ANS;

    rep(c1,0,n){
        if(!mark[c1]){
            start = 0;
            ll m3 = degsum(c1);
            //cerr << start << " " << m3/2 << " ds\n";
            vi ew = eulerWalk(C2, m3/2, c1);
            rep(c2,1,sz(ew)){
                int edge = EE[ew[c2]];
                // cerr << "euler " << ew[c2]+1 << " " << ew[(c2+1)]+1 << "\n";
                if(c2%2 == 0 && edge < m){
                    ANS.push_back(edge);
                    taken[edge] = 1;
                    deg2[A[edge]]++;
                    deg2[B[edge]]++;
                 //   cerr << "added " << A[edge]+1 << " " << B[edge]+1 << "\n";
                }
            }
        }
    }

    rep(c1,0,n){
        if(deg2[c1] < (deg[c1]+1)/2){
            trav(p, C[c1]){
                int pi = p.second;
                if(!taken[pi] && pi < m){
                    ANS.push_back(pi);
                    taken[pi] = 1;
                    break;
                }
            }
        }
    }

    assert(sz(ANS) <= (n+m+1)/2);

    cout << sz(ANS) << "\n";
    trav(y, ANS){
        cout << A[y]+1 << " " << B[y]+1 << "\n";
    }


    return 0;
}