#pragma GCC optimize("O3")

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

const int MAXN = 100001;

const int LOG = 512;
vi A;

bool tot[LOG] = {0};

int latest[LOG] = {0};


//vector<vi> C(MAXN, vi());

int smallest[LOG] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    int a,b,c,d,e;

    cin >> n;

    rep(c1,0,LOG){
        smallest[c1] = LOG;
    }

    smallest[0] = -1;

    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
        rep(c2,0,LOG){
            if(smallest[c2] < a)smallest[(c2^a)] = min(smallest[(c2^a)], a);
        }
    }


    vi res;
    rep(x,0,LOG){
        if(smallest[x] < LOG)res.push_back(x);
    }
    sort(all(res));
    cout << sz(res) << "\n";
    trav(y, res){
        cout << y << " ";
    }cout << "\n";



    return 0;
}