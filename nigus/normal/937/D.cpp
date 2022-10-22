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

const int MAXN = 200001;

vector<vi> C(MAXN, vi());
vector<vi> C2(MAXN, vi());
bool mark[MAXN] = {0};
int par[MAXN] = {0};
int start;

int win = -1;
int lose = -1;

bool dead_end[MAXN] = {0};

void dfs(int i){
    //cerr << i/2+1 << "  fds\n";
    if(sz(C[i]) == 0){
        if(i%2 == 0)lose = i;
        if(i%2 == 1)win = i;
    }
    mark[i] = 1;
    trav(y, C[i]){
        if(!mark[y]){
            par[y] = i;
            dfs(y);
        }
    }
}

int deg[MAXN] = {0};

void get_dead(){
    vi Q;
    rep(c1,0,2*n){
        deg[c1] = sz(C[c1]);
        if(deg[c1] == 0){
            Q.push_back(c1);
        }
    }
    while(!Q.empty()){
        int a = Q.back();
       // cerr << a/2+1 << "  fd\n";
        Q.pop_back();
        dead_end[a] = 1;
        trav(y, C2[a]){
            deg[y]--;
            if(deg[y] == 0)Q.push_back(y);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> m;
    rep(c1,0,n){
        cin >> c;
        rep(c2,0,c){
            cin >> a;
            a--;
            C[2*c1].push_back(2*a+1);
            C[2*c1+1].push_back(2*a);
            C2[2*a].push_back(2*c1+1);
            C2[2*a+1].push_back(2*c1);
        }
    }
    cin >> start;
    start--;
    dfs(2*start);
    get_dead();
    if(win != -1){
        cout << "Win\n";
        vi ANS;
        while(win != 2*start){
            ANS.push_back(win/2);
            win = par[win];
        }
        ANS.push_back(start);
        reverse(all(ANS));
        trav(y, ANS){
            cout << y+1 << " ";
        }
        cout << "\n";
    }
    else{
        if(dead_end[2*start]){
            cout << "Lose\n";
        }
        else{
            cout << "Draw\n";
        }
    }

    return 0;
}