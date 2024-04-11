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

const int MAXN = 200001;

vl A;

bool test(ll mid){
    ll tot = 0;
    rep(c1,n/2,n){
        tot += max(0ll, mid-A[c1]);
        if(tot > k)return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> k;
    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
    }
    sort(all(A));
    ll L = 0;
    ll R = big*3;
    while(L < R-1){
        ll mid = (L+R)/2;
        if(test(mid)){
            L = mid;
        }
        else{
            R = mid;
        }
    }
    cout << L << "\n";

    return 0;
}