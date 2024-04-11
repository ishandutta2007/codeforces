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

const int MAXN = 100001;

string gone(string &s, int pos){
    string L = "";
    string R = "";
    L += s[pos];
    R += s[pos];
    rep(c1,1,sz(s)){
        int i = pos-c1;
        int j = pos+c1;
        if(i >= 0)L += s[i];
        if(j < sz(s))R += s[j];
        if(i >= 0 && j < sz(s) && s[i] != s[j])return "";
    }
    reverse(all(R));
    reverse(all(L));
    if(sz(R) > sz(L))return R;
    return L;
}

bool sub(string &s1, string &s2){
    rep(c1,0,sz(s1)-sz(s2)+1){
        bool yes = 1;
        rep(c2,0,sz(s2)){
            if(s1[c1+c2] != s2[c2]){
                yes = 0;
                break;
            }
        }
        if(yes)return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        string s,t;
        cin >> s >> t;
        n = sz(s);
        m = sz(t);
        bool ans = 0;
        rep(c1,0,m){
            string ss = gone(t, c1);
        //    cerr << ss << "  GGGGdg\n";
            if(ss != "" && sub(s,ss)){
                ans = 1;
                break;
            }
        }
        if(ans){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}