//#pragma GCC optimize("O3")   //
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
const int LOG = 19;

vector<vi> C(MAXN, vi());
vector<vi> nums(LOG, vi());

bool col[MAXN] = {0};

vector<vi> VC(2, vi());

void dfs(int i, int par, int c){
    col[i] = c;
    VC[c].push_back(i);
    trav(y, C[i]){
        if(y != par){
            dfs(y,i,(c^1));
        }
    }
}

int LABEL[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    cin >> T;

    int t = 1;
    ll start = 1;
    rep(c1,0,LOG){
        rep(c2,0,t){
            nums[c1].push_back(start);
            start++;
        }
        t *= 2;
    }

    rep(c4,0,T){
        cin >> n;
        rep(c1,0,n){
            C[c1].clear();
            LABEL[c1] = -1;
        }
        VC[0].clear();
        VC[1].clear();
        vector<bool> marked(n+1, 0);
        rep(c1,0,n-1){
            cin >> a >> b;
            a--;
            b--;
            C[a].push_back(b);
            C[b].push_back(a);
        }
        dfs(0,-1,0);
        int cc = 0;
        if(sz(VC[1]) < sz(VC[0])){
            cc = 1;
        }
        int siz = sz(VC[cc]);
        vi labels;
        int siz2 = siz;
        rep(c1,0,LOG){
            if(siz2%2 == 1){
                rep(c2,0,sz(nums[c1])){
                    labels.push_back(nums[c1][c2]);
                    marked[nums[c1][c2]] = 1;
                }
            }
            siz2 /= 2;
        }
       // assert(siz == sz(labels));
        rep(c1,0,siz){
            LABEL[VC[cc][c1]] = labels[c1];
        }
        vi leftovers;
        rep(c1,1,n+1){
            if(!marked[c1])leftovers.push_back(c1);
        }
        rep(c1,0,n){
            if(LABEL[c1] == -1){
                LABEL[c1] = leftovers.back();
                leftovers.pop_back();
            }
        }
        rep(c1,0,n){
            C[c1].clear();
            cout << LABEL[c1] << " ";
        }cout << "\n";
    }

    return 0;
}