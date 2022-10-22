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

vector<vi> factor(10*MAXN, vi());
vi A;
ll DP[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    DP[0] = 1;
    for(int c1 = 1; c1 < MAXN; c1++){
        for(int c2 = c1; c2 < 10*MAXN; c2 += c1){
            factor[c2].push_back(c1);
        }
    }

    cin >> n;
    int ans = 0;
    rep(c1,0,n){
        cin >> a;
        vi temp;
        trav(d, factor[a]){
            ans += DP[d-1];
            ans %= big;
            temp.push_back(DP[d-1]);
        }
        rep(c2,0,sz(temp)){
            DP[factor[a][c2]] += temp[c2];
            DP[factor[a][c2]] %= big;
        }
    }
    cout << ans << "\n";

    return 0;
}