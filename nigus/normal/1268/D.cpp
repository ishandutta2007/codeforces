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


vi val, comp, z, cont;
int Time, ncomps;
template<class G> int dfs(int j, G& g) {
	int low = val[j] = ++Time, x; z.push_back(j);
	trav(e,g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G> void scc(G& g) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 2001;

vector<vi> C;

bool IB[MAXN] = {0};
bool OB[MAXN] = {0};

ll B[MAXN][MAXN] = {0};
ll B2[MAXN][MAXN] = {0};

ll brute(ll mask){
    vector<vi> C2;
    rep(c1,0,n){
        vi temp;
        rep(c2,0,n){
            B2[c1][c2] = B[c1][c2];
            if((mask&(1ll << c1)) != 0){
                B2[c1][c2] ^= 1;
            }
            if((mask&(1ll << c2)) != 0){
                B2[c1][c2] ^= 1;
            }
            if(B2[c1][c2]){
                temp.push_back(c2);
            }
        }
        C2.push_back(temp);
    }

    scc(C2);
if(ncomps > 1)return big;

    ll ones = 0;
    rep(c1,0,n){
        ones += mask%2;
        mask /= 2;
    }

    return ones;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    rep(c1,0,n){
        string s;
        cin >> s;
        vi temp;
        rep(c2,0,n){
            B[c1][c2] = (s[c2] == '1');
            if(s[c2] == '1'){
                temp.push_back(c2);
            }
        }
        C.push_back(temp);
    }

    if(n > 12){
    scc(C);

    ll inbad = 0;
    ll outbad = 0;

    rep(c1,0,n){
        if(sz(C[c1]) == 1)IB[C[c1][0]] = 1;
        trav(y, C[c1]){
            if(sz(C[y]) == n-2){
                OB[c1] = 1;
            }
        }
        if(sz(C[c1]) == 0)IB[c1] = 1;
        if(sz(C[c1]) == n-1)OB[c1] = 1;
    }

    ll non_bad = 0;
    rep(c1,0,n){
        non_bad += (!IB[c1] && !OB[c1]);
        inbad += IB[c1];
        outbad += OB[c1];
    }

    if(ncomps == 1){
        cout << "0 1\n";
        return 0;
    }

    if(non_bad > 0){
        cout << "1 " << non_bad << "\n";
        return 0;
    }
    }

    ll ways = 0;
    ll ans = big;

    ll FAC[MAXN] = {0};
    ll t = 1;
    for(ll c1 = 0; c1 < MAXN; c1++){
        FAC[c1] = t;
        t *= (c1+1);
        t %= mod;

    }

    for(ll mask = 0; mask < (1ll << n); mask++){
        ll hej = brute(mask);
        if(hej != big){
            if(hej < ans){
                ans = hej;
                ways = 0;
            }
            if(hej == ans){
                ways += FAC[hej];
                ways %= mod;
            }
        }
    }

    if(ans != big){
        cout << ans << " " << ways << "\n";
    }
    else{
        cout << "-1\n";
    }

    return 0;
}