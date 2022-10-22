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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return DD(eng)%r;
}

const ll big = 1000000007;

ll n,m,T,k,q;
const int MAXN = 5000;

string s;

bool solve(ll i){
    if(i <= 0 || i >= n)return 0;
    string res = "";
    bool eq = 1;
    for(int c1 = 0; c1 < n; c1++){
        char ch1 = s[(c1+i)%n];
        char ch2 = s[(i-c1-1+2*n)%n];
        if(ch1 != ch2)return 0;
        if(ch1 != s[c1])eq = 0;
    }
    if(eq)return 0;
    return 1;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> s;
    n = s.length();
    char ch = s[0];
    bool fail = 1;

    for(int c1 = 0; c1 < n; c1++){
        if(c1 != n-c1-1 && s[c1] != ch)fail = 0;
    }
    if(fail){
        cout << "Impossible\n";
        return 0;
    }
    ll ans = 2;
    for(int c1 = 1; c1 < n; c1++){
        if(solve(c1)){ans = 1;}
    }

    cout << ans << "\n";

    return 0;
}