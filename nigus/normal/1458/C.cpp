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

int grid[1000001][3] = {0};
vi P, D;
int grid2[1001][1001] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> T;

    rep(c4,0,T){
        cin >> n >> m;
        P.clear();
        D.clear();
        rep(c1,0,3){
            P.push_back(c1);
            D.push_back(0);
        }
        rep(c1,0,n){
            rep(c2,0,n){
                cin >> a;
                a--;
                grid[c1*n+c2][0] = a;
                grid[c1*n+c2][1] = c1;
                grid[c1*n+c2][2] = c2;
            }
        }
        string s;
        cin >> s;
        rep(c1,0,m){
            if(s[c1] == 'R'){
                D[P[2]]++;
            }
            if(s[c1] == 'L'){
                D[P[2]]--;
            }
            if(s[c1] == 'D'){
                D[P[1]]++;
            }
            if(s[c1] == 'U'){
                D[P[1]]--;
            }
            if(s[c1] == 'I'){
                swap(P[0], P[2]);
            }
            if(s[c1] == 'C'){
                swap(P[0], P[1]);
            }
        }
        rep(c1,0,n*n){
            rep(c2,0,3){
                grid[c1][c2] += D[c2];
                grid[c1][c2] += n*m+n;
                grid[c1][c2] %= n;
            }
            int x = grid[c1][P[1]];
            int y = grid[c1][P[2]];
            grid2[x][y] = grid[c1][P[0]]+1;
        }
        rep(c1,0,n){
            rep(c2,0,n){
                cout << grid2[c1][c2] << " ";
            }cout << "\n";
        }cout << "\n";
    }

    return 0;
}