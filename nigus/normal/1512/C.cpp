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

string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> a >> b >> s;
        n = sz(s);
        ll F[2] = {0};
        bool fail = 0;
        rep(c1,0,n){
            if(s[c1] != '?'){
                F[s[c1]-'0']++;
                if(s[c1] != s[n-c1-1] && s[n-c1-1] != '?')fail = 1;
            }
            else{
                if(s[n-c1-1] != '?'){
                    s[c1] = s[n-c1-1];
                    F[s[c1]-'0']++;
                }
            }
        }
        a -= F[0];
        b -= F[1];

        if(a%2 == 1){
            s[n/2] = '0';
            a--;
        }
        if(b%2 == 1){
            s[n/2] = '1';
            b--;
        }

        rep(c1,0,n){
            if(s[c1] == '?'){
                if(a > 0){
                    s[c1] = '0';
                    s[n-c1-1] = '0';
                    a -= 2;
                }
                else{
                    s[c1] = '1';
                    s[n-c1-1] = '1';
                    b -= 2;
                }
            }
        }
        if(a != 0 || b != 0 || fail){
            cout << "-1\n";
        }
        else{
            cout << s << "\n";
        }

    }

    return 0;
}