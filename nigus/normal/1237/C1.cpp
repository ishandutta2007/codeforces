#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 300001;

struct pt{
    ll x,y,z;
};

vl X,Y,Z,ind;
vector<pt> P;

bool le(pt p, pt q){
    if(p.x == q.x && p.y == q.y){
        return p.z < q.z;
    }
    if(p.x == q.x){
        return p.y < q.y;
    }
    return p.x < q.x;
}

bool comp(ll i, ll j){
    if(X[i] == X[j] && Y[i] == Y[j]){
        return Z[i] < Z[j];
    }
    if(X[i] == X[j]){
        return Y[i] < Y[j];
    }
    return X[i] < X[j];
}

bool mark[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;

    rep(c1,0,n){
        cin >> a >> b >> c;
        ind.push_back(c1);
        X.push_back(a);
        Y.push_back(b);
        Z.push_back(c);
        P.push_back({a,b,c});
    }
    sort(all(ind),comp);

    rep(c1,0,n){
        ll i = -1;
        if(mark[ind[c1]])continue;
        pt mip = {big,big,big};

        rep(c2,c1+1,n){
            if(!mark[ind[c2]]){
                pt diff = {abs(P[ind[c2]].x - P[ind[c1]].x) , abs(P[ind[c2]].y - P[ind[c1]].y), abs(P[ind[c2]].z - P[ind[c1]].z)};
                if(c1 == 0){
                   // cerr << diff.x << " " << diff.y << " " << diff.z << "  gdf\n";
                }
                if(le(diff, mip)){
                    mip = diff;
                    i = ind[c2];
                }
            }
        }
        mark[ind[c1]] = 1;
        mark[i] = 1;
        cout << ind[c1]+1 << " " << i+1 << "\n";
    }

    return 0;
}