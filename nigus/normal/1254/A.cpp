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

string alfa = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";


bool rice[101][101] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> m >> k;
        ll totrice = 0;
        rep(c1,0,n){
            string s;
            cin >> s;
            rep(c2,0,m){
                rice[c1][c2] = (s[c2] == 'R');
                totrice += rice[c1][c2];
            }
        }
        ll low = totrice / k;
        ll num = k - totrice % k;

        ll now = 0;
        ll has = 0;

        rep(c1,0,n){
            string prnt = "";
            rep(c3,0,m){
                ll c2 = c3;
                if(c1%2 == 1)c2 = m-c3-1;
                if(now == k)now--;
               // cout << alfa[now];
                prnt += alfa[now];
                has += rice[c1][c2];
                if(has == low+1){
                    has = 0;
                    now++;
                }
                else{

                    if(has == low && num > 0){
                        has = 0;
                        now++;
                        num--;
                    }

                }
            }
            if(c1%2 == 1){
                reverse(all(prnt));
            }
            cout << prnt << "\n";
        }

    }

    return 0;
}