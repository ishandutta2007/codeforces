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

const int MAXN = 200006;

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
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

vi D,A,F;
map<int,int> M;
map<int,int> I;

bool comp(int i, int j){
    return M[i] < M[j];
}

int get_f(int x){
    if(M.find(x) == M.end())return 0;
    return M[x];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;
    cin >> T;
    rep(c4,0,T){
        cin >> n >> k;
        D.clear();
        M.clear();
        A.clear();
        F.clear();
        I.clear();
        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
            if(M.find(a) == M.end()){
                D.push_back(a);
                M[a] = 0;
            }
            M[a]++;
        }

        m = sz(D);
        rep(c1,0,m){
            F.push_back(M[D[c1]]);
        }

        sort(all(D), comp);
        rep(c1,0,m){
            I[D[c1]] = c1;
        }

        vi havenot;
        rep(c1,0,n+1){
            if(get_f(c1) == 0)havenot.push_back(c1);
        }

        FT ft1(m);
        FT ft2(m);
        trav(y, D){
            if(y >= n){
                int i = I[y];
                ft1.update(i, 1);
                ft2.update(i, M[y]);
            }
        }

        int ans = m - havenot[0];

        int prev = n;

        for(int c1 = sz(havenot)-1; c1 >= 0; c1--){
            int goal = havenot[c1];
            for(int c2 = prev-1; c2 > goal; c2--){
                assert(I.find(c2) != I.end());
                int i = I[c2];
                ft1.update(i, 1);
                ft2.update(i, M[c2]);
            }
            prev = goal;

            int need = c1;

            if(need > k)continue;
            int j = ft2.lower_bound(k+1);
            int dead = ft1.query(m);
            if(j != sz(D))dead = ft1.query(j);

            int dist = sz(D)-dead+need;
            int mex = goal;

            int temp = dist-mex;

           // cerr << "goal: " << goal << "   dead: " << dead << "   -   " << temp << "\n";

            ans = min(ans, temp);

        }
        cout << ans << "\n";

    }

    return 0;
}