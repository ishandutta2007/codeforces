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

ll gcd(ll i, ll j){
    if(j == 0)return i;
    return gcd(j,i%j);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    ll la,ra,ta;
    ll lb,rb,tb;
    cin >> la >> ra >> ta;
    cin >> lb >> rb >> tb;
    ll g = gcd(ta,tb);

    ll LB = rb-lb;

    ra -= la;
    lb -= la;
    rb -= la;
    la = 0;

    if(lb < 0){
        lb = (g - (-lb)%g)%g;
    }
    else{
        lb = lb%g;
    }


    rb = lb+LB;



    ll ans1 = min(rb,ra)-max(la,lb)+1;
    ll ans2 = min(rb-g,ra)-max(la,lb-g)+1;

    cout << max(0ll,max(ans1,ans2)) << "\n";

    return 0;
}