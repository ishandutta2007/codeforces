//#pragma GCC optimize("O3")   //
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

const int MAXN = 300001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    cin >> n;
    map<int,int> M;
    rep(c1,0,n){
        cin >> a;
        M[a-1] = c1;
    }
    vi A;
    rep(c1,0,n){
        cin >> a;
        A.push_back(M[a-1]);
    }
    vi MIN(n+1, big);
    for(int c1 = n-1; c1 >= 0; c1--){
        MIN[c1] = min(MIN[c1+1], A[c1]);
    }

    int ans = 0;
    rep(c1,0,n){
        if(A[c1] > MIN[c1+1])ans++;
    }
    cout << ans << "\n";



    return 0;
}