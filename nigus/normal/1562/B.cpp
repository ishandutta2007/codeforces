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

const int MAXN = 1000001;

bool prime[101] = {0};
bool mark[101] = {0};

int solve(string s){
    int nn = sz(s);
    rep(c1,0,nn){
        if(!prime[s[c1]-'0'])return s[c1]-'0';
    }

    rep(c1,0,nn){
        rep(c2,c1+1,nn){
            int dig = (s[c1]-'0') * 10 + (s[c2]-'0');
            if(!prime[dig])return dig;
        }
    }
    return -1337;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    for(int c1 = 2; c1 < 101; c1++){
        if(!mark[c1]){
            prime[c1] = 1;
            for(int c2 = 2*c1; c2 < 101; c2 += c1){
                mark[c2] = 1;
            }
        }
    }

    ll a,b,c,d,e;

    cin >> T;
    rep(c1,0,T){
        string s;
        cin >> n;
        cin >> s;
        a = solve(s);
        cout << 1 + (a >= 10) << "\n" << a << "\n";
    }

    return 0;
}