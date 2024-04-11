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

vi pi(const string& s) {
	vi p(sz(s));
	rep(i,1,sz(s)) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

vi match(const string& s, const string& pat) {
	vi p = pi(pat + '\0' + s), res;
	rep(i,sz(p)-sz(s),sz(p))
		if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
	return res;
}

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 100002;

ll TWO[MAXN] = {0};

ll CSC[MAXN][26] = {0};

ll tocc(int i, int j, int ch){
    if(i == j)return 0;
    ll R = CSC[j][ch];
    ll L = (TWO[j-i]*CSC[i][ch])%big;
    return (R-L+big)%big;
}

string st;
vector<string> ss;

vi I;
vector<string> QS;

string alfa = "abcdefghijklmnopqrstuvwxyz";

bool DEBUG = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    ll t = 1;
    rep(c1,0,MAXN){
        TWO[c1] = t;
        t *= 2;
        t %= big;
    }


    cin >> n >> q;
    string s0;

    if(DEBUG){
        s0 = "";
        st = "";
        for(int c1 = 0; c1 < 100; c1++){
            s0 += alfa[random2()%26];
        }
        for(int c1 = 0; c1 < n; c1++){
            st += alfa[random2()%26];
        }

    }
    else{
        cin >> s0 >> st;
    }

    int ma = 0;

    rep(c1,0,q){
        string s;

        if(DEBUG){
            a = n;
            s = "";
            for(int c1 = 0; c1 < 1000000; c1++){
                s += alfa[random2()%26];
            }
        }
        else{
            cin >> a >> s;
        }
        I.push_back(a);
        QS.push_back(s);
        ma = max(ma, sz(s));
    }

    bool too_big = 0;
    rep(c1,0,n+1){
        if(c1 == 0){
            ss.push_back(s0);
        }
        else{
            if(!too_big){
                ss.push_back(ss[c1-1] + st[c1-1] + ss[c1-1]);
                if(sz(ss[c1]) >= ma)too_big = 1;
            }
            rep(c2,0,26){
                CSC[c1][c2] = 2*CSC[c1-1][c2];
                if(st[c1-1]-'a' == c2)CSC[c1][c2]++;
                CSC[c1][c2] %= big;
            }
        }
    }



    rep(c1,0,q){
        int i = 0;
        int j = I[c1];
        while(i < j && sz(ss[i]) < sz(QS[c1])){
            i++;
        }


        if(sz(ss[i]) < sz(QS[c1])){
            cout << "0\n";
            continue;
        }


        ll inner = sz(match(ss[i], QS[c1]));
        inner *= TWO[j-i];
        inner %= big;
        string thing = "";
        rep(c2,0,sz(QS[c1])-1){
            thing += ss[i][ sz(ss[i]) - sz(QS[c1]) + c2 + 1];
        }
        thing += 'a';
        rep(c2,0,sz(QS[c1])-1){
            thing += ss[i][c2];
        }

        ll outer = 0;
        rep(c2,0,26){
            thing[sz(QS[c1])-1] = alfa[c2];
            ll tt = tocc(i, j, c2);
        //    if(c1 == 2)cerr << c1 <<" " <<  c2 << ": " << thing << " " << tt << " " << sz(match(thing, QS[c1])) << "\n";
            outer += sz(match(thing, QS[c1])) * tt;
            outer %= big;
        }

        cout << (inner + outer)%big << "\n";

    }

    return 0;
}