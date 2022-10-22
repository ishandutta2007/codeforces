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

const ll big = 1000000007;

ll n,m,k,T;

ll x,y;

vector<ll> D;
vector<ll> F;

ll D2[42142] = {0};

ll ans = 0;

ll upp(ll i, ll j){
    if(j == 0)return 1;
    if(j% 2 == 0){
        ll h = upp(i,j/2);
        return (h*h)%big;
    }
    return (i*upp(i,j-1))%big;
}

ll gcd(ll i, ll j){
    if(i == 0 || j == 0)return max(i,j);
    return gcd(j,i%j);
}

ll stupid(ll i, ll g){
    if(i == 0)return (g == 1);
    ll ans = 0;
    for(ll c1 = 1; c1 <= i; c1++){
        ans += stupid(i-c1,gcd(g,c1));
    }
    ans %= big;
    return ans;
}

void brute(ll i){

    if(i == sz(D)){

        ll t = 1;
        ll f = 0;
        for(ll c1 = 0; c1 < sz(D); c1++){
            t *= upp(D[c1],D2[c1]);
            f += D2[c1];
        }


        ll mi = 1;
        if(f%2 == 1)mi = -1;

        //cout << y/t << " " << mi << "\n";

        ans += upp(2,y/t-1)*mi;
        ans += 12*big;
        ans %= big;
        return;
    }

    for(ll c1 = 0; c1 <= 1; c1++){
        D2[i] = c1;
        brute(i+1);
    }
    return;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> x >> y;

    if(y%x != 0){
        cout << "0\n";
    }
    else{

        y /= x;
        ll y2 = y;
        for(ll c2 = 2; c2*c2 <= y; c2++){
            ll f = 0;
            while(y2%c2 == 0){
                y2 /= c2;
                f++;
            }
            if(f > 0){
                D.push_back(c2);
                F.push_back(f);
            }
        }
        if(y2 != 1){
            D.push_back(y2);
            F.push_back(1);
        }
        brute(0);
        //cout << ans << " " << stupid(y,0) << "\n";
        cout << ans%big << "\n";
    }

    return 0;
}