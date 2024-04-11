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

const ll MAXN = 1001;

vl A;
string abc = "abc";

bool mat(string s, string two){
    rep(c1,0,s.length()){
        string temp = "";
        rep(c2,0,2){
            temp += s[(c1+c2)%(s.length())];
        }
        if(temp == two)return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;
    string s1,s2;
    cin >> s1 >> s2;


    if(s1[0] == s2[1] && s1[1] == s2[0] && s1[0] != s1[1]){


        cout << "YES\n";
        char mid = 'a';
        if(s1[0] == mid || s1[1] == mid)mid = 'b';
        if(s1[0] == mid || s1[1] == mid)mid = 'c';
        rep(c1,0,n){cout << s1[0];}
        rep(c1,0,n){cout << mid;}
        rep(c1,0,n){cout << s1[1];}
        return 0;
    }

    if(s1[0] == s2[0] && (s1[1] != s2[1]) && (s1[1] != s1[0]) && (s2[1] != s1[0])){
        char last = s1[0];
        string ans = "";
        rep(c1,0,3){
            if(abc[c1] != last){
                rep(c2,0,n){
                    ans += abc[c1];
                }
            }
        }
        rep(c2,0,n){
            ans += last;
        }cout << "YES\n";
        cout << ans << "\n";
        return 0;
    }

    if(s1[1] == s2[1] && (s1[0] != s2[0]) && (s1[0] != s1[1]) && (s2[0] != s1[1])){
        char last = s1[1];
        string ans = "";

        rep(c2,0,n){
            ans += last;
        }

        rep(c1,0,3){
            if(abc[c1] != last){
                rep(c2,0,n){
                    ans += abc[c1];
                }
            }
        }
cout << "YES\n";
        cout << ans << "\n";
        return 0;
    }

    string ans = "abc";
    string good = "X";
    for(int c1 = 0; c1 < 6; c1++){
        if(!mat(ans,s1) && !mat(ans,s2)){
            good = ans;
            break;
        }
        next_permutation(all(ans));
    }

    if(good == "X"){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        rep(c1,0,n){
            cout << good;
        }cout <<"\n";
    }

    return 0;
}