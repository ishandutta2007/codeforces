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

const int MAXN = 300001;

bool grid[5001][51] = {0};

vector<pii> ANS;

void f(int i, int j){
    grid[i][j] = 1;
    ANS.push_back({i,j});
}

void skull(int i, int j){
    f(i+1,j);
    f(i+2,j);
    f(i+3,j);
    f(i+4,j);

    f(i+4,j-1); f(i+4,j+1);
    f(i+4,j-2); f(i+4,j+2);
    f(i+3,j-2); f(i+3,j+2);
    f(i+2,j-2); f(i+2,j+2);
    f(i+2,j-1); f(i+2,j+1);

}

void join(int x1, int x2){
    rep(c1,0,5){
        f(x1,2+c1);
        f(x2,2+c1);
    }
    rep(c1,x1+1,x2){
        f(c1,6);
    }
}

void prnt(){
    rep(c1,0,50){
        rep(c2,0,8){
            if(grid[c1][c2]){
                cerr << "O";
            }
            else{
                cerr << " ";
            }
        }
        cerr << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;


    cin >> n;

    rep(c1,0,n/2){
        skull(4*c1+1,2);
    }

    f((n/2) * 4 + 2,2);

    join(1, (n/2) * 4 + 3);

    if(n%2 == 1){
        f((n/2) * 4 + 3, 1);
        f((n/2) * 4 + 4, 1);
        f((n/2) * 4 + 4, 2);

    }

    //prnt();
    cout << sz(ANS) << "\n";
    trav(p, ANS){
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}