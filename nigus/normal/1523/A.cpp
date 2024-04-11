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

const int MAXN = 5001;



string solve(string s){
    string t = "";
    rep(c1,0,n){
        int near = 0;
        if(c1 > 0)near += (s[c1-1] == '1');
        if(c1 < n-1)near += (s[c1+1] == '1');
        if(near == 1 || s[c1] == '1'){
            t += '1';
        }
        else{
            t += '0';
        }
    }
    return t;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;


    cin >> T;
    rep(c1,0,T){
        cin >> n >> m;
        string s;
        cin >> s;
        rep(_,0,min(n+3, m)){
            s = solve(s);
        }
        cout << s << "\n";
    }

    return 0;
}