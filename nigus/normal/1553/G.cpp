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

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
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

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 200001;
const int MAXS = 1000007;

vi primes;

vector<vl> fac(MAXS, vl());
vl A;
bool mark[MAXS] = {0};

set<ll> E;

ll h(ll i, ll j){
    if(i < j)swap(i,j);
    return i*ll(MAXS)+j;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;


    for(ll c2 = 2; c2 < MAXS; c2++){
        if(!mark[c2]){
            primes.push_back(c2);
            for(ll c3 = c2; c3 < MAXS; c3 += c2){
                fac[c3].push_back(sz(primes)-1);
                mark[c3] = 1;
            }
        }
    }

    cin >> n >> q;

    UF uf(sz(primes) + n);

    rep(c1,0,n){
        cin >> a;
        int i = sz(primes) + c1;
        A.push_back(a);
        trav(p, fac[a]){
            uf.join(p, i);
        }
    }


    rep(c1,0,n){
        trav(p, fac[A[c1]]){
            trav(pp, fac[A[c1]+1]){
                E.insert(h(uf.find(p), uf.find(pp)));
            }
        }
        trav(p, fac[A[c1]+1]){
            trav(pp, fac[A[c1]+1]){
                E.insert(h(uf.find(p), uf.find(pp)));
            }
        }
    }

    rep(c1,0,q){
        int i,j;
        cin >> i >> j;
        i--;j--;
        ll f1 = uf.find(i+sz(primes));
        ll f2 = uf.find(j+sz(primes));
        if(f1 == f2){
            cout << 0 << "\n";
        }
        else{

            ll hh = h(f1,f2);
            if(E.find(hh) != E.end()){
                cout << "1\n";
            }
            else{
                cout << "2\n";
            }

        }
    }

    return 0;
}