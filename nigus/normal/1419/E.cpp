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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 400001;

vi grey;

void get_grey(int x){
    grey.clear();
    grey.push_back(0);
    grey.push_back(1);
    bool alt = 0;
    rep(_,0,x-1){
        vi grey2;
        trav(g, grey){
            grey2.push_back(2*g+alt);
            grey2.push_back(2*g+(alt^1));
            alt ^= 1;
        }
        grey = grey2;
    }
}

vi divs;
vi F;

vector<vi> D(300001, vi());

int mask(ll x){
    int res = 0;
    trav(d, divs){
        res *= 2;
        if(x%d == 0)res++;
    }
    return res;
}

vi ANS;

int gcd(int a, int b){
    if(b == 0)return a;
    return gcd(b,a%b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;
    cin >> T;
    rep(_,0,T){
        cin >> n;
        divs.clear();
        F.clear();
        ll n2 = n;
        for(ll d = 2; d*d <= n; d++){
            if(n2%d == 0){
                divs.push_back(d);
                F.push_back(0);
                while(n2%d == 0){
                    n2 /= d;
                    F[sz(F)-1]++;
                }
            }
        }
        if(n2 != 1){
            divs.push_back(n2);
            F.push_back(1);
        }
        get_grey(sz(divs));
        rep(c1,0,sz(grey)+100){
            D[c1].clear();
        }

        for(ll d = 2; d*d <= n; d++){
            if(n%d == 0){
                D[mask(d)].push_back(d);
                if(d*d != n){
                    D[mask(n/d)].push_back(n/d);
                }
            }
        }

        ANS.clear();

        ANS.push_back(n);
        rep(c1,1,sz(grey)){
            int msk = grey[c1];
            trav(d, D[msk]){
                ANS.push_back(d);
            }
        }
        trav(a, ANS){
            cout << a << " ";
        }cout << "\n";
        ll penalty = 0;
        rep(c1,0,sz(ANS)){
            a = c1;
            b = (c1+1)%sz(ANS);
            penalty += (gcd(ANS[a], ANS[b]) == 1);
        }
        cout << penalty << "\n";

    }

    return 0;
}