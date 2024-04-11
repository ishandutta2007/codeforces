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

const int MAXN = 300001;

bool mark[MAXN] = {0};

bool DEBUG = 0;

bool done = 0;

ll ma = 0;
int tot = 0;

void ask(){
    if(tot == ma){
        done = 1;
        //cerr << "TOT: " << tot << "\n";
        return;
    }
    vi ans;
    rep(c1,0,n-1){
        if(c1%k != (k-1) && !mark[c1]){
            ans.push_back(c1);
        }
        if(sz(ans) == k)break;
    }
    if(sz(ans) == 0){
        done = 1;
        return;
    }
    cout << sz(ans) << " ";
    trav(j,ans){
        cout << j+1 << " ";
        if(!mark[j])tot++;
        mark[j] = 1;

    }
    cout << "\n";
    fflush(stdout);

    int x;

    if(DEBUG){
        x = rand()%n+1;
    }
    else{
        cin >> x;
    }

    if(x == -1){
        cerr << "ERROR\n";
        while(1){
            int a = 1;
            int b = a;
            b += b;
            a *= b;
        }
    }

    x--;

    rep(c1,0,sz(ans)){
        if(mark[(x+c1)%n])tot--;
        mark[(x+c1)%n] = 0;
    }

}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;



    cin >> n;

    if(n <= 3){
        cout << "0\n";
        fflush(stdout);
        return 0;

    }

    k = 0;

    rep(c1,1,n+1){
        a = c1-1 + (n+c1-1)/c1;
        a = n-a;

        if(ma < a){
            k = c1;
            ma = a;
        }
    }

    rep(c1,0,10000){
        ask();
        if(done)break;
    }

    cout << "0\n";
    fflush(stdout);

    return 0;
}