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

vl P,Q,W,ind;

bool comp(int i, int j){
    return W[i] > W[j];
}

vl A,B;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> m >> n;

    rep(c1,0,m){
        cin >> a;
        A.push_back(a);
    }
    rep(c1,0,n){
        cin >> a;
        B.push_back(a);
    }
    UF uf(n+m);
    ll ans = 0;
    rep(c1,0,m){
        int siz;
        cin >> siz;
        rep(c2,0,siz){
            cin >> a;
            a--;
            ind.push_back(sz(ind));
            W.push_back(A[c1]+B[a]);
            P.push_back(c1);
            Q.push_back(a+m);
            ans += W.back();
        }
    }

    sort(all(ind),comp);

    trav(i, ind){
        a = P[i];
        b = Q[i];
        if(!uf.sameSet(a,b)){
            ans -= W[i];
            uf.join(a,b);
        }
    }
    cout << ans << "\n";

    return 0;
}