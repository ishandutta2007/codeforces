#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,q,T,k;

struct pt{
ld x;
ld y;
};

pt ptc(ld x, ld y){
    pt p;
    p.x = x;
    p.y = y;
    return p;
}

ld A(pt a, pt b, pt c){
    pt p = ptc(b.x-a.x, b.y-a.y);
    pt q = ptc(c.x-a.x, c.y-a.y);
    return abs(p.x*q.y-p.y*q.x)/2.0;
}

ld dist(pt a, pt b){
    ld dx = a.x-b.x;
    ld dy = a.y-b.y;
    return sqrt(dx*dx + dy*dy);
}

ld D(pt a, pt b, pt c){
    ld area = A(a,b,c);
    ld base = dist(a,c);
    return 2.0*area/base;
}

vector<pt> P;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c;

    cin >> n;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a >> b;
        pt p = ptc(a,b);
        P.push_back(p);
    }

    ld d = big*big;

    for(ll c1 = 0; c1 < n; c1++){
        for(ll c2 = 0; c2 < n; c2++){
            if(c2 != c1 && c2 != (c1+1)%n){
                d = min(d , D(P[c1] , P[(c1+1)%n] , P[c2])/2.0);
            }
        }
    }
    cout << setprecision(18) << d << "\n";

    return 0;
}