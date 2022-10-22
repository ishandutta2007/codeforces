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

const ll MAXN = 200001;

vector<vi> C(MAXN, vi());

ll dist1[MAXN] = {0};
ll r1 = 0;
ll dm1 = 0;
void dfs1(ll i, ll par){
    rep(c1,0,sz(C[i])){
        ll a = C[i][c1];
        if(a != par){
            dist1[a] = dist1[i]+1;
            if(dist1[a] > dm1){
                dm1 = dist1[a];
                r1 = a;
            }
            dfs1(a,i);
        }
    }
}

ll dist2[MAXN] = {0};
ll r2 = 0;
ll dm2 = 0;
ll PAR[MAXN] = {0};
void dfs2(ll i, ll par){
    PAR[i] = par;
    rep(c1,0,sz(C[i])){
        ll a = C[i][c1];
        if(a != par){
            dist2[a] = dist2[i]+1;
            if(dist2[a] > dm2){
                dm2 = dist2[a];
                r2 = a;
            }
            dfs2(a,i);
        }
    }
}


ll dist3[MAXN] = {0};
void dfs3(ll i, ll par){
    rep(c1,0,sz(C[i])){
        ll a = C[i][c1];
        if(a != par){
            dist3[a] = dist3[i]+1;
            dfs3(a,i);
        }
    }
}


ll RES[MAXN] = {0};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> k;
    rep(c1,0,n-1){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }

    dfs1(0,-1);


    if(k == 2){
        rep(c1,0,n){
            RES[c1] = (dist1[c1]%2);
        }
        cout << "Yes\n";
        rep(c1,0,n){
            cout << RES[c1]+1 << " ";
        }cout << "\n";
        return 0;
    }


    dfs2(r1,-1);
    dfs3(r2,-1);
    ll now = r2;

    rep(c1,0,n){
        RES[c1] = -1;
    }

    a = 0;


    while(now != -1){
        RES[now] = a;
        now = PAR[now];
        a++;
        a %= k;
    }

    bool fail = 0;

    rep(c1,0,n){
        if(RES[c1] == -1){

            if(dist3[c1] >= k-1 && dist2[c1] >= k-1){
                fail = 1;
            }

            if(dist3[c1] > dist2[c1]){
                RES[c1] = dist3[c1]%k;
            }
            else{
                RES[c1] = (RES[r1] - dist2[c1] + n*k)%k;
            }
        }
    }


    if(fail){
        cout << "No\n";
    }
    else{
        cout << "Yes\n";
        rep(c1,0,n){
            cout << RES[c1]+1 << " ";
        }
        cout << "\n";
        return 0;
    }



    return 0;
}