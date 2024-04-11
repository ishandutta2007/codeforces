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

const int MAXN = 300001;

vi A;

ll L[MAXN] = {0};
ll R[MAXN] = {0};

vi B;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n;
    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
    }

    rep(c1,0,n){
        if(c1 == 0 || A[c1] < A[c1-1]){
            L[c1] = 0;
        }
        else{
            L[c1] = 1 + L[c1-1];
        }
    }

    for(int c1 = n-1; c1 >= 0; c1--){
        if(c1 == n-1 || A[c1] < A[c1+1]){
            R[c1] = 0;
        }
        else{
            R[c1] = 1 + R[c1+1];
        }
    }

    rep(c1,0,n){
        B.push_back(max(L[c1], R[c1]));
    }
    sort(all(B));

    ll ma = 0;
    rep(c1,0,n){
        if(B[c1] == B[n-1])ma++;
    }


    ll ans = 0;
    ll i = -1;
    rep(c1,0,n){
        if(L[c1] == B[n-1] && L[c1] == R[c1]){
            ans++;
            i = c1;
        }
    }

    if(ans != 1 || B[n-1]%2 == 1 || ma > 1){
        cout << "0\n";
        return 0;
    }


    cout << ans << "\n";

    return 0;
}