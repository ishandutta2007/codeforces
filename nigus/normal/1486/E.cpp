#pragma GCC optimize("O3")   //
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 100001;

vector<vi> C(51*MAXN, vi());
vector<vi> CW(51*MAXN, vi());

int dist[51*MAXN] = {0};
bool mark[51*MAXN] = {0};

void dijkstra(){
    priority_queue<pii> pq;
    pq.push({0,0});
    rep(c1,0,51*n){
        dist[c1] = -1;
    }
    dist[0] = 0;
    while(!pq.empty()){
        int i = pq.top().second;
        pq.pop();
        if(!mark[i]){
            mark[i] = 1;
            rep(c1,0,sz(C[i])){
                ll w = CW[i][c1];
                ll j = C[i][c1];
                if(dist[j] == -1 || dist[j] > dist[i] + w){
                    dist[j] = dist[i] + w;
                    pq.push({-dist[j], j});
                }
            }
        }
    }
}

void add_edge(int i, int j, int w){
    C[51*i].push_back(51*j+w);
    CW[51*i].push_back(0);
    for(ll w2 = 1; w2 <= 50; w2++){
        C[51*i+w2].push_back(51*j);
        CW[51*i+w2].push_back((w+w2)*(w+w2));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    cin >> n >> m;
    rep(c1,0,m){
        cin >> a >> b >> c;
        a--;b--;
        add_edge(a,b,c);
        add_edge(b,a,c);
    }
    dijkstra();
    rep(c1,0,n){
        cout << dist[51*c1] << " ";
    }cout << "\n";


    return 0;
}