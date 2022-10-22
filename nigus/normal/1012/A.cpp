#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<double,double> pdd;


const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,T;

vl A;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c;

    cin >> n;
    for(int c1 = 0; c1 < 2*n; c1++){
        cin >> a;
        A.push_back(a);
    }
    sort(all(A));

    ll ans = (A[2*n-1]-A[n])*(A[n-1] - A[0]);

    for(int c1 = 1; c1 < n; c1++){
        ans = min(ans, (A[2*n-1]-A[0]) * (A[c1+n-1]-A[c1]));
    }
    cout << ans << "\n";

    return 0;
}