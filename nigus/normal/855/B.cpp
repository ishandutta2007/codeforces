#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll big = 1000000007ll;
const ll big2 = 1000000009ll;
ll n,m,k,q,w,h;

ll DP[100001][3] = {0};
bool fix[100001][3] = {0};
ll verysmall = -5ll*big*big;
vector<ll> A;
vector<ll> B;

ll dp(ll i, ll j){

    if(i == n)return verysmall;
    if(fix[i][j] == 1)return DP[i][j];

    ll a1;
    if(j == 2){
        a1 = B[2]*A[i];
    }
    else{
        a1 = B[j]*A[i] + dp(i,j+1);
    }

    a1 = max(a1, dp(i+1,j));
    DP[i][j] = a1;
    fix[i][j] = 1;
    return a1;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;
    for(ll c1 = 0; c1 < 3; c1++){
        cin >> a;
        B.push_back(a);
    }

    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
        for(ll c2 = 0; c2 < 3; c2++){
            DP[c1][c2] = -1;
        }
    }

   ll ans = dp(0,0);
    cout << ans << "\n";

    return 0;
}