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
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<double,double> pdd;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,q;

vl A;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;
    ll diff = 0;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        diff += a;
        A.push_back(a);
    }
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        diff -= a;
        A.push_back(a);
    }
    sort(all(A));
    reverse(all(A));
    for(int c1 = 0; c1 < 2*n; c1++){
        if(c1%2 == 0){
            diff += A[c1];
        }
        else{
            diff -= A[c1];
        }
    }
//    cout << diff << "\n";
    diff /= 2;
    cout << diff << "\n";

    return 0;
}