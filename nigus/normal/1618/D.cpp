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



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> k;
        vi A;
        map<int,int> M;
        rep(c1,0,n){
            cin >> a;
            A.push_back(a);
            M[a]=0;
        }
        sort(all(A));
        reverse(all(A));
        ll ans = 0;
        rep(c1,2*k,n){
            ans += A[c1];
        }

        n = 2*k;
        rep(c1,0,n){
            M[A[c1]]++;
        }
        int f = 0;
        rep(c1,0,n){
            f = max(f, M[A[c1]]);
        }
        int no = n-f;
        if(no >= k){
           // cout << "0\n";
        }
        else{
            k -= no;
           // cout << k << "\n";
            ans+=k;
        }
        cout << ans << "\n";
    }

    return 0;
}