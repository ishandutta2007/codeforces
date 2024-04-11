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

vector<ll> A;
ll DP[51][2] = {0};

ll dp(ll i, ll turn){
    if(i == n)return 0;
    if(DP[i][turn] != -1)return DP[i][turn];
    ll a = 0;
    if(turn == 1){
        a = min(dp(i+1,0) , A[i]+dp(i+1,1));
    }
    else{
        a = max(A[i]+dp(i+1,1),dp(i+1,0));
    }
    DP[i][turn] = a;
    return a;
}

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    b = 0;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        b += a;
        DP[c1][0] = -1;
        DP[c1][1] = -1;
        A.push_back(a);
    }

    ll ans = dp(0,0);
    cout << b-ans << " " << ans << "\n";

    return 0;
}