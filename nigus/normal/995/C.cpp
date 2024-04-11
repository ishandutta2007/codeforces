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

pt mulp(ll c, pt p){
    return {c*p.x,c*p.y};
}

pt pp(pt p1, pt p2){
    return {p1.x+p2.x,p1.y+p2.y};
}

ll dist2(pt p1, pt p2){
    ll dx = p1.x-p2.x;
    ll dy = p1.y-p2.y;
    return dx*dx+dy*dy;
}

pt Q[4];
vector<pt> P;

ll sol[100001][4] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c;

    cin >> n;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a >> b;
        P.push_back({a,b});
    }

    if(n == 1){
        cout << 1 << "\n";
        return 0;
    }
    ll t = 0;
    for(int c1 = -1; c1 <= 1; c1 +=2){
        for(int c2 = -1; c2 <= 1; c2 += 2){
            sol[0][t] = c1;
            sol[1][t] = c2;
            Q[t] = pp(mulp(c1,P[0]),mulp(c2,P[1]));
            t++;
        }
    }

    for(int c1 = 2; c1 < n; c1++){
        for(int c2 = 0; c2  < 4; c2++){
            ll i = 0;
            ll mind = big*big;
            for(int c3 = -1; c3 <= 1; c3+=2){
                pt newp = pp(Q[c2],mulp(c3,P[c1]));
                ll d = dist2(newp,{0,0});
                if(d < mind){
                    mind = d;
                    i = c3;
                }
            }
            sol[c1][c2] = i;
            Q[c2] = pp(Q[c2],mulp(i,P[c1]));
        }
    }

    ll mind = big*big;
    ll i = 0;
    for(int c1 = 0; c1 < 4; c1++){
        ll d = dist2(Q[c1],{0,0});
        if(d < mind){
            mind = d;
            i = c1;
        }
    }
   // cout << dist2(Q[i],{0,0}) << " " << ll(2e12) << "\n";
    for(int c1 = 0; c1 < n; c1++){
        cout << sol[c1][i] << " ";
    }

    return 0;
}