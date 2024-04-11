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

const int MAXN = 300001;

const ll inf = 1LL << 62;
void floydWarshall(vector<vector<ll>>& m) {
	int n = sz(m);
	rep(i,0,n) m[i][i] = min(m[i][i], 0LL);
	rep(k,0,n) rep(i,0,n) rep(j,0,n)
		if (m[i][k] != inf && m[k][j] != inf) {
			auto newDist = max(m[i][k] + m[k][j], -inf);
			m[i][j] = min(m[i][j], newDist);
		}
	rep(k,0,n) if (m[k][k] < 0) rep(i,0,n) rep(j,0,n)
		if (m[i][k] != inf && m[k][j] != inf) m[i][j] = -inf;
}

ll W[201][201] = {0};
int ANS[201] = {0};

bool mark[201] = {0};

vector<vi> C(MAXN, vi());
vector<vi> C2(MAXN, vi());

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;


    cin >> n >> m;

    if(n == 1){
        cout << "YES\n0\n0\n";
        return 0;
    }

    rep(c1,0,n){
        rep(c2,0,n){
            W[c1][c2] = inf;
        }
    }
    rep(c1,0,m){
        cin >> a >> b >> c;
        a--;
        b--;
        if(c == 1){
            W[a][b] = 1;
            W[b][a] = -1;
        }
        else{
            W[a][b] = 1;
            W[b][a] = 1;
        }
    }
    vector<vl> W2;
    rep(c1,0,n){
        vl temp;
        rep(c2,0,n){
            temp.push_back(W[c1][c2]);
        }
        W2.push_back(temp);
    }
    floydWarshall(W2);
    ll best = -big;
    int start = -1;
    int goal = -1;

    /*
    rep(c1,0,n){
        rep(c2,0,n){
            cerr << W2[c1][c2] << " ";
        }cerr << "\n";
    }
    */

    rep(c1,0,n){
        ll mi = -big;
        ll tg = -1;
        rep(c2,0,n){
            if(c1 != c2){
                if(mi < W2[c1][c2]){
                    tg = c2;
                }
                mi = max(mi, W2[c1][c2]);
                if(W2[c1][c2] == inf)mi = inf;
            }
        }
        if(mi != inf && mi > best){
            best = mi;
            start = c1;
            goal = tg;
        }
    }

    bool bad = 0;

    /*
    queue<int> Q;
    Q.push(start);
    ANS[start] = 0;
    while(!Q.empty()){

    }
    */


    if(start == -1)bad = 1;


    if(!bad){
        rep(c1,0,n){
            ANS[c1] = W2[start][c1];
        }
        rep(c1,0,n){
            rep(c2,0,n){
                if(W[c1][c2] == 1){
                    if(abs(ANS[c1]-ANS[c2]) != 1)bad = 1;
                }
                if(W[c2][c1] == -1){
                    if(ANS[c1]+1 != ANS[c2])bad=1;
                }
            }
        }
    }
    if(bad){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << abs(best) << "\n";
    rep(c1,0,n){
        cout << ANS[c1] << " ";
    }cout << "\n";


    return 0;
}