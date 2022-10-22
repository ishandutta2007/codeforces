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

const int MAXN = 500001;

string s;

bool smaller(string s1, string s2){
    if(s1.length() < s2.length())return 1;
    if(s1.length() > s2.length())return 0;
    rep(c1,0,s1.length()){
        if(s1[c1]-'0' < s2[c1]-'0')return 1;
        if(s1[c1]-'0' > s2[c1]-'0')return 0;
    }
    return 1;
}

string ans1(){
    string res = "";
    for(int c1 = 0; c1 < k; c1++){
        res += s[c1];
    }
    for(int c1 = k; c1 < n; c1++){
        res += res[c1-k];
    }
    return res;
}

string num = "0123456789";

string ans2(){
    string res = "";
    for(int c1 = 0; c1 < k; c1++){
        res += s[c1];
    }
    for(int c1 = k-1; c1 >= 0; c1--){
        if(res[c1] != '9'){
            res[c1] = num[1 + res[c1]- '0'];
            rep(c2,c1+1,k){
                res[c2] = '0';
            }
            break;
        }
    }
    for(int c1 = k; c1 < n; c1++){
        res += res[c1-k];
    }
    return res;
}

string ans3(){
    string res = "";
    for(int c1 = 0; c1 < n; c1++){
        res += '9';
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> k;
    cin >> s;

    string ss1 = ans1();
    if(smaller(s, ss1)){
        cout << n << "\n";
        cout << ss1 << "\n";
        return 0;
    }

    string ss2 = ans2();
    if(smaller(s, ss2)){
        cout << n << "\n";
        cout << ss2 << "\n";
        return 0;
    }

    cout << n << "\n";
    cout << ans3() << "\n";

    return 0;
}