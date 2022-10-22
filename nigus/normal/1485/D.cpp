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

const int MAXN = 501;

const int fours = 32;
ll FOUR[fours] = {0};

ll A[MAXN][MAXN] = {0};
ll B[MAXN][MAXN] = {0};

int cc = 0;
int CC[1000001] = {0};

bool inbounds(ll i, ll j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

bool inbounds2(ll x){
    return x > 0 && x <= 1000000;
}

ll consider(ll i, ll j, ll x){
    for(int c1 = fours-1; c1 >= 1; c1--){
        ll y = x - FOUR[c1];
        if(!inbounds2(y) || y%A[i][j] != 0)continue;
        if(CC[y] == cc)return y;
        CC[y] = cc;
    }
    for(int c1 = 1; c1 < fours; c1++){
        ll y = x + FOUR[c1];
        if(!inbounds2(y) || y%A[i][j] != 0)continue;
        if(CC[y] == cc)return y;
        CC[y] = cc;
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    for(ll c1 = 0; c1 < fours; c1++){
        FOUR[c1] = c1*c1*c1*c1;
    }
    cin >> n >> m;
    rep(c1,0,n){
        rep(c2,0,m){
            cin >> a;
           // a = rand()%16+1;
            A[c1][c2] = a;
        }
    }

    rep(c1,0,n){
        rep(c2,0,m){
            if((c1+c2)%2 == 0){
                B[c1][c2] = 720720;
            }
        }
    }

    rep(c1,0,n+m){
        for(int c2 = c1; c2 >= 0; c2--){
            int i = c1-c2;
            int j = c2;
            if(!inbounds(i, j) || (i+j)%2 == 0)continue;
            cc++;
            consider(i,j,720720);
            B[i][j] = consider(i,j,720720);

            if(B[i][j] == -1)cerr << "ERROR\n";
        }
    }

    rep(c1,0,n){
        rep(c2,0,m){
            cout << B[c1][c2] << " ";
        }cout << "\n";
    }

    return 0;
}