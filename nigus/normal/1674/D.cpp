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

const int MAXN = 200006;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n;
        vi A;
        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
        }
        reverse(all(A));
        vi B;
        for(int c1 = 0; c1 < n; c1 += 2){
            if(c1 == n-1){
                B.push_back(A[c1]);
            }
            else{
                B.push_back(max(A[c1], A[c1+1]));
                B.push_back(min(A[c1], A[c1+1]));
            }
        }
        bool yes = 1;
        rep(c1,0,n-1){
            if(B[c1] < B[c1+1])yes = 0;
        }
        if(yes){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }

    return 0;
}