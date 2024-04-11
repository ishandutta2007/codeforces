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

const int MAXN = 200101;

int DP[2][27] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;


    cin >> T;
    rep(c4,0,T){
        cin >> n;
        vl F;
        rep(c1,0,n){
            cin >> a;
            F.push_back(a);
        }
        sort(all(F));
        bool yes = 1;


        if(n == 1 && F[0] > 1)yes = 0;
        if(n > 1 && F[n-1] > F[n-2]+1)yes = 0;

        if(yes){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }


    return 0;
}