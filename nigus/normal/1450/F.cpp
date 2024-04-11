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

int F[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;


    cin >> T;
    rep(c4,0,T){
        vi X,Y,A;
        cin >> n;
        rep(c1,0,n){
            cin >> a;
            a--;
            F[c1] = 0;
            A.push_back(a);
        }
        int start = A[0];
        rep(c1,0,n){
            if(c1 == n-1 || A[c1+1] == A[c1]){
                X.push_back(start);
                Y.push_back(A[c1]);
                if(c1 < n-1)start = A[c1+1];
            }
        }

        int f = -1;
        int bad = -1;
        rep(c1,0,sz(X)){
            F[X[c1]]++;
            F[Y[c1]]++;
        }
        rep(c1,0,n){
            if(F[c1] > f){
                f = F[c1];
                bad = c1;
            }
        }
        int need = 2*f - 2 - (2*sz(X));
        need = max(0, need);
        int extra = 0;
        rep(c1,0,n-1){
            if(A[c1] != bad && A[c1+1] != bad && A[c1] != A[c1+1]){
                extra += 2;
            }
        }
        if(need > extra){
            cout << "-1\n";
        }
        else{
            cout << sz(X) -1 + (need)/2 << "\n";
        }

    }


    return 0;
}