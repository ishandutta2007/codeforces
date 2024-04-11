#pragma GCC optimize("O3")

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

const int MAXN = 100007;

map<ll,ll> M;
vector<vi> C(MAXN, vi());

int pek[MAXN] = {0};
int deg[MAXN] = {0};

vector<vi> uf;
vector<set<int> > S;

int par(int i){
    while(i != pek[i]){i = pek[i];}
    return i;
}

void merg(int i, int j){
    int i2 = par(i);
    int j2 = par(j);
    if(i2 != j2){
        if(deg[i2] < deg[j2])swap(i2,j2);

        trav(y, uf[j2]){
            trav(yy, C[y]){
                S[yy].erase(j2);
                S[yy].insert(i2);
            }
            pek[y] = i2;
            //cerr << i2+1 << " " << j2+1 << ": " << y+1 << "  fgdgfdgfd\n";
            uf[i2].push_back(y);
        }
        uf[j2].clear();

        deg[i2] += deg[j2];
        //pek[j2] = i2;
    }
}

void add(int i, int j, int c){
    ll h = ll(MAXN)*ll(i)+c;
    if(M.find(h) == M.end()){
        M[h] = j;
    }
    else{
        merg(M[h], j);
    }
}

void add_edge(int i, int j, int c){
    C[i].push_back(j);
    C[j].push_back(i);
    S[i].insert(par(j));
    S[j].insert(par(i));
    add(i,j,c);
    add(j,i,c);
}

bool slow(int i, int j){
    bool res = 0;
    cerr << "\n [";
    trav(y, C[j]){
        if(par(y) == par(i)){
            res = 1;
        }
        cerr << par(y) << " ";
    }
    cerr << "]   vs   [";
    trav(y, S[j]){
        cerr << y << " ";
    }
    cerr << "]\n\n";
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> m >> k >> q;
    rep(c1,0,n){
        deg[c1] = 1;
        pek[c1] = c1;
        uf.push_back({c1});
        set<int> temp;
        S.push_back(temp);
    }
    rep(c1,0,m){
        cin >> a >> b >> c;
        a--;
        b--;
        c--;
        add_edge(a,b,c);
    }
    rep(c1,0,q){
        char ch;
        cin >> ch;
        if(ch == '+'){
            cin >> a >> b >> c;
            a--;
            b--;
            c--;
            add_edge(a,b,c);
        }
        else{
            cin >> a >> b;
            a--;
            b--;
            if(par(a) == par(b) || S[b].find(par(a)) != S[b].end()){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
        }
    }

    return 0;
}