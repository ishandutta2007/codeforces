#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

ll n,m,T,k,d;
const ll big = 1000000007;

vi A;
vi B;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

   cin >> n >> k;
   ll ma = -1;
   for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
   }

    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        B.push_back(a);
        if(a == 1 && A[c1] == 1)ma = c1;
    }

    k--;

    if(A[0] == 0){
        cout << "NO\n";
        return 0;
    }

    if(A[k] == 1){
        cout << "YES\n";
        return 0;
    }

    if(B[k] == 1 && ma > k){
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";


    return 0;
}