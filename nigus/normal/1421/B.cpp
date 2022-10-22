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

vector<pii> ANS;
int A[201][201];

void invert(int i, int j){
    ANS.push_back({i+1,j+1});
    A[i][j] ^= 1;
}

void turn(int i, int j, int to){
    if(A[i][j] != to)invert(i, j);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c;

    cin >> T;
    rep(c1,0,T){
        cin >> n;
        ANS.clear();
        rep(c1,0,n){
            string s;
            cin >> s;
            rep(c2,0,n){
                A[c1][c2] = s[c2]-'0';
            }
        }

        if(A[0][1] == A[1][0]){
            turn(n-1,n-2, (A[0][1]^1));
            turn(n-2,n-1, (A[0][1]^1));
        }
        else{
            if(A[n-1][n-2] == A[n-2][n-1]){
                turn(0,1, (A[n-1][n-2]^1));
                turn(1,0, (A[n-1][n-2]^1));
            }
            else{
                turn(n-1,n-2, 0);
                turn(n-2,n-1, 0);
                turn(0,1, 1);
                turn(1,0, 1);
            }
        }
        cout << sz(ANS) << "\n";
        trav(p, ANS){
            cout << p.first << " " << p.second << "\n";
        }

    }

    return 0;
}