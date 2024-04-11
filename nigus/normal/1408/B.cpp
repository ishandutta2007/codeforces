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

struct pt{
    ll x,y;
};

vector<pt> light;
vector<pt> P;

vector<vector<pt> > penalty(2001, vector<pt>());

bool comp(pt p1, pt p2){
    if(p1.x == p2.x)return p1.y > p2.y;
    return p1.x < p2.x;
}

ll PEN[1000012] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;

    rep(c4,0,T){
        cin >> n >> k;
        vi A;
        set<ll> S;
        rep(c1,0,n){
            cin >> a;
            S.insert(a);
        }
        if(k == 1){
            if(sz(S) == 1){
                cout << "1\n";
            }
            else{
                cout << "-1\n";
            }

        }
        else{
            cout << max(1ll, (sz(S)-2)/(k-1) + 1) << "\n";
        }
    }

    return 0;
}