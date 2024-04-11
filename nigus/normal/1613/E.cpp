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

const int MAXN = 1000001;

bool inbounds(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

int DX[4] = {0,0,-1,1};
int DY[4] = {1,-1,0,0};

vector<vector<bool> > blocked;
vector<bool> mark;
int start;
int deg[MAXN] = {0};
vector<vi> C(MAXN, vi());

void dfs(int i){
    int x = i/m;
    int y = i%m;
    mark[i] = 1;
    rep(c1,0,4){
        int x2 = x + DX[c1];
        int y2 = y + DY[c1];
        int j = x2*m+y2;
        if(inbounds(x2,y2) && !mark[j]){
            deg[j]--;
            if(deg[j] <= 1)dfs(j);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> m;
        blocked.clear();
        mark.clear();
        rep(c1,0,n){
            string s;
            cin >> s;
            vector<bool> temp;
            rep(c2,0,m){
                int i = c1*m+c2;
                C[i].clear();
                deg[i] = 0;
                if(s[c2] == '#'){
                    temp.push_back(1);
                    mark.push_back(1);
                }
                else{
                    temp.push_back(0);
                    mark.push_back(0);
                    if(s[c2] == 'L')start = i;
                }
            }
            blocked.push_back(temp);
        }
        rep(c1,0,n){
            rep(c2,0,m){
                rep(c3,0,4){
                    int x = c1+DX[c3];
                    int y = c2+DY[c3];
                    if(inbounds(x, y) && !blocked[x][y])deg[c1*m+c2]++;
                }
            }
        }

        dfs(start);
        rep(c1,0,n){
            rep(c2,0,m){
                if(blocked[c1][c2]){
                    cout << "#";
                }
                else{
                    int i = c1*m+c2;
                    if(i == start){
                        cout << "L";
                    }
                    else{
                        if(mark[i]){
                            cout << "+";
                        }
                        else{
                            cout << ".";
                        }
                    }
                }
            }
            cout << "\n";
        }

    }

    return 0;
}