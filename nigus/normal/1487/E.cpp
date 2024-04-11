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

const int MAXN = 600007;

const int inf = big/2;
int N[4] = {0};
int cost[4][MAXN/4] = {0};
int DP[4][MAXN/4] = {0};
vector<vi> C(MAXN, vi());
set<pii> S;

int index(int i, int j){
    return (MAXN/4) * i + j;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    rep(c1,0,4){
        cin >> N[c1];
    }
    rep(c1,0,4){
        rep(c2,0,N[c1]){
            cin >> cost[c1][c2];
        }
    }
    rep(c1,0,3){
        cin >> m;
        rep(c2,0,m){
            cin >> a >> b;
            a--;
            b--;
            int i = index(c1,a);
            int j = index(c1+1,b);
            C[i].push_back(j);
        }
    }

    for(int c1 = 0; c1 < N[3]; c1++){
        DP[3][c1] = cost[3][c1];
        S.insert({DP[3][c1], c1});
    }
    for(int c1 = 2; c1 >= 0; c1--){
        for(int c2 = 0; c2 < N[c1]; c2++){
            int i = index(c1, c2);
            trav(y, C[i]){
                int x = y%(MAXN/4);
                S.erase({DP[c1+1][x], x});
            }
            if(S.empty()){
                DP[c1][c2] = inf;
            }
            else{
                DP[c1][c2] = cost[c1][c2] + (*S.begin()).first;
            }
            trav(y, C[i]){
                int x = y%(MAXN/4);
                S.insert({DP[c1+1][x], x});
            }
        }
        S.clear();
        for(int c2 = 0; c2 < N[c1]; c2++){
            S.insert({DP[c1][c2], c2});
        }
    }
    int ans = (*S.begin()).first;
    if(ans >= inf){
        cout << "-1\n";
    }
    else{
        cout << ans << "\n";
    }

    return 0;
}