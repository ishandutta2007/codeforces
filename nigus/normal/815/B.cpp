#include <bits/stdc++.h>

using namespace std;
#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,T,k,q;

ll FAC[200001] = {0};
ll INV[200001] = {0};

vector<ll> A;

vector<ll> K;

ll mod(ll i){
    if(i < 0)return mod(big-(mod(-i)));
    if(i < big)return i;
    return i%big;
}

ll upp(ll i, ll j){
if(j == 0)return 1;
if(j%2 == 0){
    ll h = upp(i,j/2);
    return (h*h)%big;

}
return (i*upp(i,j-1))%big;
}

ll bin(ll i, ll j){
if(j > i || i < 0 || j < 0)return 0;
ll num = FAC[i];
ll den = (INV[j]*INV[i-j])%big;
return (num*den)%big;
}

ll PM(ll i, ll j, ll mi){

    if(i < 0)return 0;
    if(i >= j)return 0;

    if(j == 1){
        return 1;
    }
    ll mi2 = mi;
    if(j%2 == 0){
        mi2 = -mi;
    }

    if((i%2 == 0 && mi == 1) || (i%2 == 1 && mi == -1)){
        return (PM(i,j-1,mi2) - PM(i-1,j-1,mi2));
    }
    else{
        return (PM(i,j-1,mi2)+PM(i-1,j-1,mi2));
    }
}

void setup(){
ll t = 1;
for(ll c1 = 0; c1 < 200001; c1++){
    FAC[c1] = t;
    INV[c1] = upp(t,big-2);
    t *= (c1+1);
    t %= big;
}
}

void spread(){
    vector<ll> B;

    for(ll c1 = 1; c1 < n; c1++){
        if(c1%2 == 1){
            B.push_back(A[c1-1]+A[c1]);
        }
        else{
            B.push_back(A[c1-1]-A[c1]);
        }
    }

    A.clear();
    for(ll c1 = 0; c1 < n-1; c1++){
        A.push_back(B[c1]);
    }

}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;

    setup();

    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }
    if(n%4 == 3){
        spread();
        n--;
    }

    if(n%4 == 0){
        ll mi = 1;
        for(ll c1 = 0; c1 < n; c1++){
            a = bin((n-2)/2,c1/2)*mi;
            a += big*2;
            a %= big;
            K.push_back(a);
            mi *= -1;
        }
    }
    if(n%4 == 1){
        for(ll c1 = 0; c1 < n; c1++){
            a = bin(n/2,c1/2);
            if(c1%2 == 1)a = 0;
            a %= big;
            K.push_back(a);
        }
    }
    if(n%4 == 2){
        for(ll c1 = 0; c1 < n; c1++){
            a = bin((n-2)/2,c1/2);
            a %= big;
            K.push_back(a);
        }
    }

    ll ans = 0;

    for(ll c1 = 0; c1 < n; c1++){

        a = mod(K[c1]*A[c1]);
        ans += a;
        ans = mod(ans);

    }

    cout << ans << "\n";

    return 0;
}