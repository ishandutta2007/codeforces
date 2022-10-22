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

ll n,m,k,T;

struct pt{
    ll x,y;
};

vector<pt> P;

ll area(pt p1, pt p2, pt p3){
    return abs( (p1.x*p2.y-p1.y*p2.x) + (p2.x*p3.y-p2.y*p3.x) + (p3.x*p1.y-p3.y*p1.x));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c;

    cin >> n;
    rep(c1,0,n){
        cin >> a >> b;
        P.push_back({a,b});
    }

    int i2 = -1;
    ll mid = 4*big*big;
    rep(c1,1,n){
        ll d = (P[0].x-P[c1].x) * (P[0].x-P[c1].x) + (P[0].y-P[c1].y) * (P[0].y-P[c1].y);
        if(d < mid){
            mid = d;
            i2 = c1;
        }
    }

    ll mi = 4*big*big;
    rep(c1,1,n){
        if(c1 != i2){
            a = area(P[0], P[i2], P[c1]);
            if(a < mi && a > 0){
                mi = a;
                b = c1;
            }
        }
    }
    cout << "1 " << i2+1 << " " << b+1 << "\n";

    return 0;
}