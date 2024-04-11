//#pragma GCC optimize("O3")   //
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

const int MAXS = 1000001;

const int MAXN = 1001;

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

int seen[MAXN] = {0};
int cc = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n >> m;

    UF uf(n);
    ll ans = 1;

    int extra = 1;

    rep(c1,0,m){
        cin >> a >> b;
        a--;
        b--;
        if(uf.sameSet(a, b)){
            extra++;
        }
        else{
            uf.join(a, b);
        }
        vi comps;
        cc++;
        rep(c2,0,n){
            c = uf.find(c2);
            if(seen[c] != cc){
                comps.push_back(uf.size(c));
                seen[c] = cc;
            }
        }
        sort(all(comps));
        reverse(all(comps));
        int ans = 0;
        rep(c1,0,min(extra, sz(comps))){
            ans += comps[c1];
        }
        cout << ans-1 << "\n";
    }

    return 0;
}