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

const int MAXN = 500006;

vector<vi> C(MAXN, vi());
vi A,B;
vi start;

int F[MAXN] = {0};
int F2[MAXN] = {0};

vi ind;

bool comp(int i, int j){
    return F[i] < F[j];
}

void add_edge(int i, int j){
    int x = start[i];
    B[C[i][x]] = j;
    F2[i]--;
    start[i]++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n;
        A.clear();
        ind.clear();
        start.clear();
        B.clear();
        rep(c1,0,n){
            start.push_back(0);
            C[c1].clear();
            F[c1] = 0;
            F2[c1] = 0;
            B.push_back(-1);
        }
        rep(c1,0,n){
            cin >> a;
            a--;
            A.push_back(a);
            F[a]++;
            F2[a]++;
            C[a].push_back(c1);
            ind.push_back(c1);
        }
        sort(all(ind), comp);
        rep(c1,0,n){
            int i = ind[c1];
            if(F2[i] == 0)continue;
            vi I;
            ll f = F2[i];
            rep(c2,c1,n){
                I.push_back(ind[c2]);
            }
            m = sz(I);
            rep(c2,0,m){
                rep(_,0,f){
                    add_edge(I[c2], I[(c2+1)%m]);
                }
            }
        }
        rep(c1,0,n){
            cout << B[c1]+1 << " ";
        }cout << "\n";

    }

    return 0;
}