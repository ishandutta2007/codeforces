#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return (1000000000 * ll(DD(eng)) + DD(eng))%r;
}

ll n,m,T,k,q;
const ll big = 1000000007;
const ll MAXN = 300001;

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

string s;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a,b,c;


    cin >> s;
    n = s.length();
    vector<FT> ft(26, FT(n));

    rep(c1,0,n){
        ft[s[c1]-'a'].update(c1,1);
    }

    cin >> q;
    rep(c1,0,q){
        cin >> a;
        if(a == 1){
            char ch;
            cin >> b >> ch;
            b--;
            ft[s[b]-'a'].update(b,-1);
            ft[ch-'a'].update(b,1);
            s[b] = ch;
        }
        else{
            cin >> a >> b;
            a--;
            b--;
            int ans = 0;
            rep(c2,0,26){
                ans += (ft[c2].query(b+1) != ft[c2].query(a));
            }
            cout << ans << "\n";
        }
    }

    return 0;
}