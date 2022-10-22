//#pragma GCC optimize("O3")   //
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

string s;

bool abc(int i){
    if(i < 0 || i+2 >= n)return 0;
    return s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n >> q;
    cin >> s;

    ll ans = 0;
    rep(c1,0,n){
        ans += int(abc(c1));
    }

    rep(c1,0,q){
        cin >> a;
        char ch;
        cin >> ch;
        a--;
        rep(c2,a-3,a+4){
            ans -= int(abc(c2));
        }
        s[a] = ch;
        rep(c2,a-3,a+4){
            ans += int(abc(c2));
        }
        cout << ans << "\n";
    }


    return 0;
}