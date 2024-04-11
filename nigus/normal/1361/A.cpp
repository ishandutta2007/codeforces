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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 500001;

vector<vi> C(MAXN, vi());

vector<vi> mex(MAXN, vi());

bool mark[MAXN] = {0};

vl A;

queue<int> Q;

int MEX[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> m;
    rep(c1,0,m){
        cin >> a >> b;
        a--,
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
        mex[a].push_back(0);
        mex[b].push_back(0);
    }

    rep(c1,0,n){
        mex[c1].push_back(0);
        cin >> a;
        A.push_back(a-1);
        if(a == 1)Q.push(c1);
        MEX[c1] = 0;
    }

    rep(c1,0,n){
        trav(y, C[c1]){
            if(A[c1] == A[y]){
                cout << "-1\n";
                return 0;
            }
        }
    }

    vi ANS;

    while(!Q.empty()){
        a = Q.front();
        Q.pop();
        if(!mark[a]){
            mark[a] = 1;
            ANS.push_back(a+1);
            trav(y, C[a]){
                if(!mark[y]){
                    if(A[a] < sz(mex[y])){
                        mex[y][A[a]] = 1;
                    }
                    while(mex[y][MEX[y]]){
                        MEX[y]++;
                    }
                    if(MEX[y] == A[y]){
                        Q.push(y);
                    }
                }
            }
        }
    }

    if(sz(ANS) == n){
        rep(c1,0,n){
            cout << ANS[c1] << " ";
        }cout << "\n";
    }
    else{
        cout << "-1\n";
    }

    return 0;
}