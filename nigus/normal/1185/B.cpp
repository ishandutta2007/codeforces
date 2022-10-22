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

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 2001;

string s1,s2;

bool solve(){
    ll j = 0;
    for(int i = 0; i < s1.length(); i++){
        if(s1[i] == s2[j]){
            j++;
        }
        else{
            if(j == 0)return 0;
            while(s2[j] == s2[j-1]){
                j++;
            }
            if(s1[i] != s2[j])return 0;
            j++;
        }
    }
    return (j == s2.length());
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    cin >> n;
    rep(c4,0,n){
       // string s1,s2;
        cin >> s1 >> s2;
        s1 += 'X';
        s2 += 'X';
        if(solve()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }

    }

    return 0;
}