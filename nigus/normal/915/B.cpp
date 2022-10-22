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

ll n,m,k,T,q;

struct trip{
    ll x,y,z;
};

trip t(ll x, ll y, ll z){
    trip tr;
    tr.x = x;
    tr.y = y;
    tr.z = z;
    return tr;
}

ll DIST[101][101][101] = {0};

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    ll l,r;
    cin >> n >> a >> l >> r;
    a--;
    l--;
    r--;
    queue<trip> Q;
    Q.push(t(a,0,n-1));
    DIST[a][0][n-1] = 1;
    while(!Q.empty()){
        trip tr = Q.front();
        Q.pop();
        a = tr.x;
        b = tr.y;
        c = tr.z;



        trip t1 = t(min(a+1,c),b,c);
        if(DIST[t1.x][t1.y][t1.z] == 0){
            DIST[t1.x][t1.y][t1.z] = DIST[tr.x][tr.y][tr.z]+1;
            Q.push(t1);
        }

        t1 = t(max(a-1,b),b,c);
        if(DIST[t1.x][t1.y][t1.z] == 0){
            DIST[t1.x][t1.y][t1.z] = DIST[tr.x][tr.y][tr.z]+1;
            Q.push(t1);
        }

        t1 = t(a,a,c);
        if(DIST[t1.x][t1.y][t1.z] == 0){
            DIST[t1.x][t1.y][t1.z] = DIST[tr.x][tr.y][tr.z]+1;
            Q.push(t1);
        }

        t1 = t(a,b,a);
        if(DIST[t1.x][t1.y][t1.z] == 0){
            DIST[t1.x][t1.y][t1.z] = DIST[tr.x][tr.y][tr.z]+1;
            Q.push(t1);
        }
    }

    ll mi = big*big;

    for(ll c1 = 0; c1 < n; c1++){
        if(DIST[c1][l][r] != 0){
            mi = min(mi, DIST[c1][l][r]);
        }
    }
    cout << mi-1 << "\n";

    return 0;
}