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
int F[1111] = {0};

vi ANS;

bool bad[1111] = {0};

int mex(){
    rep(c1,0,1111){
        if(F[c1] == 0)return c1;
    }
    return -1;
}

void to(ll i, ll x){
    F[A[i]]--;
    F[x]++;
    A[i]=x;
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

    cin >> T;
    rep(c4,0,T){
        cin >> n;
        A.clear();
        rep(c1,0,1111){
            F[c1] = 0;
            bad[c1] = 0;
        }
        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
            F[a]++;
        }
        ANS.clear();
        rep(c1,0,2*n){
            if(sorted())break;
            int mx = mex();
            if(mx == n){
                ANS.push_back(n-1);
                to(n-1,mx);
                bad[n-1] = 1;
            }
            else{
                if(bad[mx]){
                    ANS.push_back(mx-1);
                    to(mx-1,mx);
                    bad[mx-1] = 1;
                }
                else{
                    ANS.push_back(mx);
                    to(mx,mx);
                }
            }
        }
        cout << sz(ANS) << "\n";
        trav(x,ANS){
            cout << x+1 << " ";
        }cout << "\n";
    }

    return 0;
}