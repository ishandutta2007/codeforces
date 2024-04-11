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

ll A[3] = {0};
vi ind;

int pre = -1;
bool done = 0;

bool comp(ll i, ll j){
    return A[i] < A[j];
}

bool DEBUG = 0;

void answer(ll x){
    if(done)return;
    cout << x << "\n";
    fflush(stdout);
    int i;
    cin >> i;
    if(i == 0){
        done = 1;
        return;
    }
    i--;
    pre = i;
    A[i] += x;

    if(DEBUG){
        cerr << A[0] << " " << A[1] << " " << A[2] << "  fsd\n";

    }

    return;
}

int aprev(){
    sort(all(ind), comp);
    rep(c1,0,3){
        if(ind[c1] == pre)return c1;
    }
    return -1;
}

void killer(){
    sort(all(ind), comp);
    ll x = A[ind[1]] - A[ind[0]];
    ll y = A[ind[2]] - A[ind[1]];
    answer(x+2*y);
    sort(all(ind), comp);
    x = A[ind[1]] - A[ind[0]];
    answer(x);
    if(!done){
        cerr << "NOOOOO\n" << A[0] << " " << A[1] << " " << A[2] << "\n";
    }
}

void mid(){
    sort(all(ind), comp);
    ll x = A[ind[1]] - A[ind[0]];
    answer(x);
    killer();
}

void start(){
    /*
    sort(all(ind), comp);
    ll x = A[ind[1]] - A[ind[0]];
    ll y = A[ind[2]] - A[ind[1]];
    if(x <= y){
        answer(x);
        mid();
    }
    else{
        answer(6000000000);
        start();
    }
    */
    answer(6000000000);
    killer();
}

int main() {
   // ios_base::sync_with_stdio(0);
    //cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    rep(c1,0,3){
        ind.push_back(c1);
        cin >> A[c1];
    }

    cout << "First\n";
    fflush(stdout);

    start();


    return 0;
}