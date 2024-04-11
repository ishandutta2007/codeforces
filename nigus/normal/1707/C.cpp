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

const ll MAXN = 200006;

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

vector<vi> C(MAXN, vi());
vector<vi> CI(MAXN, vi());
vector<vi> MST(MAXN, vi());

bool TREE[MAXN] = {0};


ll ADD[MAXN] = {0};
ll SUB[MAXN] = {0};

int PATH[MAXN] = {0};
bool SEEN[MAXN] = {0};
vi STACK;

void dfs1(int i, int par){
    PATH[i] = sz(STACK);
    SEEN[i] = 1;
    STACK.push_back(i);

    rep(c1,0,sz(C[i])){
        int w = CI[i][c1];
        int j = C[i][c1];
        if(!TREE[w] && SEEN[j]){
            if(PATH[j] == -1){
                ADD[i]++;
                ADD[j]++;
            }
            else{
                ADD[i]++;
                ADD[0]++;
                int j2 = STACK[PATH[j]+1];
                ADD[j2]--;
            }
        }
    }


    trav(y, MST[i]){
        if(y != par){
            dfs1(y, i);
        }
    }

    STACK.pop_back();
    PATH[i] = -1;
}

ll SUM[MAXN] = {0};


void dfs2(int i, int par){
    trav(y, MST[i]){
        if(y != par){
            ADD[y] += ADD[i];
            dfs2(y, i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll a,b,c,d;
    
    cin >> n >> m;

    UF uf(n);
    rep(c1,0,m){
        cin >> a >> b;
        a--;
        b--;
        CI[a].push_back(c1);
        CI[b].push_back(c1);
        C[a].push_back(b);
        C[b].push_back(a);

        if(uf.find(a) != uf.find(b)){
            TREE[c1] = 1;
            MST[a].push_back(b);
            MST[b].push_back(a);
            uf.join(a, b);
        }
    }
    rep(c1,0,n){
        PATH[c1] = -1;
    }

    
    dfs1(0,-1);
    dfs2(0, -1);

    int non_mst = m-n+1;
    rep(c1,0,n){
        if(ADD[c1] == non_mst){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }
    cout <<  "\n";


    return 0;
}