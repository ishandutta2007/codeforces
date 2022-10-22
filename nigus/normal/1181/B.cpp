#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
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

const ll MAXN = 500001;

string alfa = "0123456789";

string add(string s1, string s2){
    string res = "";
    int carry = 0;
    ll now = 0;
    while(now < max(s1.length(), s2.length())){
        int i1 = 0;
        if(s1.length() - now - 1 >= 0)i1 = s1[s1.length() - now - 1]-'0';
        int i2 = 0;
        if(s2.length() - now - 1 >= 0)i2 = s2[s2.length() - now - 1]-'0';
        int num = (i1+i2+carry);
        res += alfa[num%10];
        carry = num/10;
        now++;
    }
    if(carry != 0)res += alfa[carry];
    reverse(all(res));
    return res;
}

bool comp(string s1, string s2){
    if(s1.length() == s2.length()){
        return s1 < s2;
    }
    return s1.length() < s2.length();
}
vector<string> sums;
ll mi = big;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

   // cerr << comp("201", "101") << "\n";

    ll a,b,c,d;

    cin >> n;

    string s;
    cin >> s;

    rep(c1,1,n){
        if(s[c1] != '0'){
            ll L = max(ll(c1), n-c1);
            if(L < mi){
                mi = L;
            }
        }
    }
    cerr << mi << "\n";
    rep(c1,1,n){
        if(s[c1] != '0'){
            ll L = max(ll(c1), n-c1);
            if(L <= mi+5){
                string s1 = "";
                string s2 = "";
                rep(c2,0,c1){
                    s1 += s[c2];
                }
                rep(c2,c1,n){
                    s2 += s[c2];
                }
              //  cerr << c1 << " " << s1<<" "<<s2 << "   " << add(s1,s2) << "\n";
                sums.push_back(add(s1,s2));
            }
        }
    }

    sort(all(sums),comp);
    cout << sums[0] << "\n";

    return 0;
}