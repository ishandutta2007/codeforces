
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

const int MAXN = 300001;

void rev(string &s, int l, int r){
    string s2 = "";
    for(int c1 = r; c1 >= l; c1--){
        s2 += s[c1];
    }
    for(int c1 = l; c1 <=r; c1++){
        s[c1] = s2[c1-l];
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        string s;
        cin >> n >> k;
        cin >> s;
        string goal = "";
        rep(c1,0,k-1){
            goal += "()";
        }
        rep(c1,0,(n-2*k+2)/2){
            goal += "(";
        }
        rep(c1,0,(n-2*k+2)/2){
            goal += ")";
        }
        vector<pii> ANS;
        rep(c1,0,n){
            if(s[c1] == goal[c1])continue;
            rep(c2,c1+1,n){
                if(s[c2] == goal[c1]){
                    ANS.push_back({c1+1,c2+1});
                    rev(s, c1, c2);
                    break;
                }
            }
        }
        cout << sz(ANS) << "\n";
        rep(c1,0,sz(ANS)){
            cout << ANS[c1].first << " " << ANS[c1].second << "\n";
        }
    }

    return 0;
}