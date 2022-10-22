#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;

ll n,m,k,T;

ll p1,p2;
ll q1,q2;
ll DP[1001][1001] = {0};
bool DPC[1001][1001] = {0};

ll DP2[1001][1001] = {0};
bool DPC2[1001][1001] = {0};


ll upp(ll i, ll j){
    if(j == 0)return 1;
    ll h = upp(i,j/2);
    if(j%2 == 0)return (h*h)%big;
    return (i*((h*h)%big))%big;
}
ll dp2(ll i, ll j);

ll dp(ll i, ll j){
    if(j >= k)return j;
    if(DPC[i][j])return DP[i][j];
    ll ans = 0;
    ll up = max(0ll, k-j-i);
    ll pa = 1;
    for(int c1 = 0; c1 < up; c1++){
       // ans += pa*dp(i+c1,j+i+c1);
       // ans %= big;
        pa *= p1;
        pa %= big;
    }
    ans = dp2(i,i+j);
    ll start = i+j+up;
    ll rest = ((((start-1)*pa)%big)*q1 + ((pa*q1)%big)*q1)%big;

    ans += rest;
    ans *= p2;
    ans %= big;
    DPC[i][j] = 1;
    DP[i][j] = ans;
    return ans;
}

ll dp2(ll i, ll j){
    if(j >= k)return 0;
    if(DPC2[i][j])return DP2[i][j];
    DP2[i][j] = (dp(i,j) + p1*dp2(i+1,j+1))%big;
    DPC2[i][j] = 1;
    return DP2[i][j];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    cin >> k >> a >> b;
    p1 = (a*upp(a+b,big-2))%big;
    p2 = (b*upp(a+b,big-2))%big;
    q1 = upp(big+1-p1,big-2);
    q2 = upp(big+1-p2,big-2);

    cout << (((p1*q2)%big)*dp(1,0))%big << "\n";

    return 0;
}