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

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,q,T;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;
    cin >> n >> k;

    vl A;
    bool mark[1000] = {0};
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }
    ll ans = 0;
    for(int c1 = 0; c1 < n; c1++){
        if(A[c1] <= k){
            mark[c1] = 1;
            ans++;
        }
        else{
            break;
        }
    }
    for(int c1 = n-1; c1 >= 0; c1--){
        if(A[c1] <= k && mark[c1] == 0){
            ans++;
        }
        else{
            break;
        }
    }
    cout << ans << "\n";


    return 0;
}