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

ll n,m,k,T,q;

vl A;

ll DP[5001][2601][2] = {0};
bool DPC[5001][2601][2] = {0};

ll geti(ll i){
    if(i >= 0 && i < n)return A[i];
    return -big*big;
}

ll dp(int i, int j, bool mode){
    if(j == 0)return 0;
    if(i >= n)return big*big;
    if(DPC[i][j][mode])return DP[i][j][mode];
    ll prev = geti(i-1);
    if(mode){
        prev = min(prev, geti(i-2)-1);
    }
    ll nex = geti(i+1);
    ll ans = dp(i+1,j,0);
    ll temp = max(0ll, prev-A[i]+1) + max(0ll, nex-A[i]+1) + dp(i+2,j-1,1);
    ans = min(ans,temp);
    DPC[i][j][mode] = 1;
    DP[i][j][mode] = ans;
    return ans;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c;

    cin >> n;

    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }

    for(int c1 = 1; c1 <= (n+1)/2; c1++ ){
        a = dp(0,c1,0);
        cout << a << " ";
    }

    return 0;
}