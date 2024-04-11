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

const int MAXN = 2000001;

vi A;
vector<vi> C(1001, vi());

vector<pll> ANS;

vi A2;

//map<int,int> M;
//ll NEXT[1001][1001] = {0};

int CC[1001][1001] = {0};
int cc = 0;


bool comp(ll i, ll j){
    if(A[i] == A[j])return i > j;
    return A[i] > A[j];
}

bool sorted(){
    rep(c1,0,n-1){
        if(A[c1] > A[c1+1])return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n;

    cc++;

    rep(c1,0,n){
        cin >> a;
       // a = rand()%3;
        A.push_back(a);
      //  M[a] = c1;
    }

    rep(c1,0,n){
        rep(c2,c1+1,n){
            if(A[c1] > A[c2]){
                C[c1].push_back(c2);
                CC[c1][c2] = -1;
            }
        }
    }

    /*
    rep(c1,0,n){
        NEXT[c1] = n;
        rep(c2,c1+1,n){
            if(A[c1] == A[c2]){
                NEXT[c1] = c2;
                break;
            }
        }
    }
    */


    rep(c1,0,n){
        sort(all(C[c1]), comp);
        rep(ii,0,sz(C[c1])){

            int i = C[c1][ii];
            if(CC[c1][i] == -1){
                CC[c1][i] = 1;
                ANS.push_back({c1, i});
                swap(A[c1], A[i]);

                rep(c2,c1+1,i){
                    if(A[c2] == A[i] && CC[c2][i] == -1){
                        CC[c2][i] = 1;
                        ANS.push_back({c2, i});
                    }
                }

            }
        }
    }
    if(!sorted()){

        cout << "-1\n";
    }
    else{
        cout << sz(ANS) << "\n";
        trav(p, ANS){
            cout << p.first+1 << " " << p.second+1 << "\n";
        }
    }

    return 0;
}