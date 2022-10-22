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

const int MAXN = 101;

vector<vi> C(MAXN, vi());
int deg[MAXN] = {0};

vl A,B;

bool mark[MAXN] = {0};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> k;
        A.clear();
        B.clear();
        rep(c1,0,n){
            C[c1].clear();
            deg[c1] = 0;
            cin >> a >> b;
            A.push_back(a);
            B.push_back(b);
        }

        rep(c1,0,n){
            rep(c2,c1+1,n){
                if(abs(A[c1]-A[c2]) + abs(B[c1]-B[c2]) <= k){
                    C[c1].push_back(c2);
                    C[c2].push_back(c1);
                }
            }
        }
        bool yes = 0;
        rep(c1,0,n){
            if(sz(C[c1]) == n-1){
                yes = 1;
            }
        }
        if(yes){
            cout << "1\n";
        }
        else{
            cout << "-1\n";
        }
    }


    return 0;
}