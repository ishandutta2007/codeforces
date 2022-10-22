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

ll r;

struct pt{
    ld x,y;
};

pt mpt(ld x, ld y){
    pt p;
    p.x=x;
    p.y=y;
    return p;
}

ld dist(pt p1, pt p2){
    return sqrt( (p1.x-p2.x)*(p1.x-p2.x)  +  (p1.y-p2.y)*(p1.y-p2.y) );
}

vector<ll> X;

vector<ld> Y;

ld inter(ll i, ll j){

    if(abs(X[i]-X[j]) > 2*r)return -1;
    if(abs(X[i]-X[j]) == 2*r)return Y[i];
    pt p1 = mpt(X[i],Y[i]);

    ld L = 0;
    ld R = ld(2*r);

    while(abs(L-R) > 0.0000000001){
        ld MID = (L+R)/2.0;
        pt p2 = mpt(X[j],Y[i]+MID);
        if(dist(p1,p2) < ld(2*r)){
            L = MID;
        }
        else{
            R = MID;
        }
    }

    return L+Y[i];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n >> r;

    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        X.push_back(a);
        Y.push_back(r);
        for(ll c2 = 0; c2 < c1; c2++){
            Y[c1] = max(Y[c1],inter(c2,c1));
        }
    }

    for(ll c1 = 0; c1 < n; c1++){
        cout << setprecision(18) << Y[c1] << " ";
    }

    return 0;
}