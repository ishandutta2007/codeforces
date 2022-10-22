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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;


const int MAXN = 200001;

array<vi, 2> manacher(const string& s) {
	int n = sz(s);
	array<vi,2> p = {vi(n+1), vi(n)};
	rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	return p;
}


string s;

bool is_pal(ll i, ll j){
    for(int c1 = 0; c1 < j-i+1; c1++){
        if(s[c1+i] != s[j-c1])return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> T;
    rep(_,0,T){
        cin >> s;
      //  n = s.length();
        /*
        s = "";
        rep(c1,0,1000000){
            s += 'a';
        }s[979897] = 'b';
*/
        n = sz(s);
        string extra = "";
        ll l = 0;
        ll r = n-1;
        if(is_pal(0,n-1)){
            cout << s << "\n";
            continue;
        }
        while(s[l] == s[r]){
            extra += s[l];
            l++;
            r--;
        }

        string cut = "";
        for(int c1 = l; c1 <= r; c1++){
            cut += s[c1];
        }

        auto P = manacher(cut);

        ll ma = 0;
        ll L = -1;
        ll R = -1;

       // cerr << cut << "\n";

        for(int c1 = 0; c1 < sz(cut); c1++){
           // cerr << P[0][c1] << "  -  " << P[1][c1] << "\n";
            if(P[0][c1] == min(c1,sz(cut)-c1) && 2*P[0][c1] > ma){
                ma = 2*P[0][c1];
                L = c1-P[0][c1];
                R = c1+P[0][c1]-1;
            }
            if(P[1][c1] == min(c1,sz(cut)-c1-1) && 2*P[1][c1]+1 > ma){
                ma = 2*P[1][c1]+1;
                L = c1-P[1][c1];
                R = c1+P[1][c1];
            }
        }

/*
        rep(c1,l,r){
            if(c1-l+1 > ma && is_pal(l, c1)){
                ma = c1-l+1;
                L = l;
                R = c1;
            }
        }

        rep(c1,l,r){
            if(r-c1+1 > ma && is_pal(c1, r)){
                ma = r-c1+1;
                L = c1;
                R = r;
            }
        }
*/
        string ans = extra;
     //   cerr << "   reyw\n";
        if(L != -1){
            for(int c1 = L; c1 <= R; c1++){
                ans += cut[c1];
            }
        }
       // cerr << ans << "  312\n";
        for(int c1 = 0; c1 < sz(extra); c1++){
            ans += extra[sz(extra)-c1-1];
        }
        cout << ans << "\n";

    }

    return 0;
}