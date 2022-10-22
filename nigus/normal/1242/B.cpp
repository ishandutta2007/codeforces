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

const int MAXN = 100001;

set<ll> E;

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

vector<vi> C(MAXN, vi());

vi ind;

bool comp(ll i, ll j){
    return sz(C[i]) < sz(C[j]);
}

bool gone[MAXN] = {0};



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;


    cin >> n >> m;
    rep(c1,0,m){
        cin >> a >> b;
        //a = 1;
        //b = c1+2;
        a--;
        b--;
        E.insert(a*n+b);
        E.insert(b*n+a);
        C[a].push_back(b);
        C[b].push_back(a);
    }
    rep(c1,0,n){
        ind.push_back(c1);
    }

    sort(all(ind),comp);
    a = ind[0];

    UF uf(n);

    rep(c1,0,n){
        if(c1 == a || E.find(ll(c1)*n + a) == E.end()){
            gone[c1] = 1;
            uf.join(c1,a);
        }
    }

    rep(c1,0,n){
        if(!gone[c1]){

            rep(c2,0,n){
                if(c2 != c1 && E.find((ll(c2)*n + ll(c1))) == E.end()){
                    uf.join(c1,c2);
                }
            }

        }
    }

    set<ll> pars;
    ll ans = 0;

    rep(c1,0,n){
        b = uf.find(c1);
        if(pars.find(b) == pars.end()){
            pars.insert(b);
            ans++;
        }

    }

    cout << ans-1 << "\n";

    return 0;
}