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

const int MAXN = 100101;

const ll ex = 60;

ll lim = (1ll << ex);

set<ll> S;
vl A;

bool chosen[MAXN] = {0};

vl P,A2;

vector<pll> ANS;
vector<char> OP;

void add(ll x, ll y){
    ll z = x+y;
    if(S.find(z) == S.end()){
        S.insert(z);
        A.push_back(z);
        n++;
        ANS.push_back({x,y});
        OP.push_back('+');
    }
}

void xo(ll x, ll y){
    ll z = (x^y);
    if(S.find(z) == S.end()){
        S.insert(z);
        A.push_back(z);
        n++;
        ANS.push_back({x,y});
        OP.push_back('^');
    }
}

bool getb(ll x, ll i){
    return (((1ll << i)&x) != 0);
}

void gauss(){
    rep(c1,0,n){
        A2.push_back(A[c1]);
    }

    for(ll c1 = ex-1; c1 >= 0; c1--){
        ll xo = -1;
        rep(c2,0,n){
            if(getb(A2[c2], ll(c1))){
                P.push_back(A[c2]);
                xo = A2[c2];
                break;
            }
        }
        rep(c2,0,n){
            if(getb(A2[c2], ll(c1))){
                A2[c2] ^= xo;
            }
        }
    }
}

string bin(ll x){
    string res = "";
    string o1 = "01";
    rep(c1,0,ex){
        res += o1[getb(x,ll(c1))];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c;
    ll x;
    cin >> x;

    //524289

    n = 1;
    S.insert(x);
    A.push_back(x);

    int ops = 99000;

    while(2*A.back() < lim){
        add(A.back(), A.back());
    }

    while(n < ops-1){
        int i = rand()%n;
        int j = rand()%n;
        if(A[i] + A[j] < lim){
            add(A[i], A[j]);
        }
        else{
            xo(A[i], A[j]);
        }
    }

    gauss();

    reverse(all(P));
/*
    rep(c1,0,sz(P)){
        cerr << bin(P[c1]) << "\n";
    }cerr << "AFTER\n\n\n";
*/
    for(ll c1 = sz(P)-1; c1 >= 0; c1--){
        //cerr << bin(P[c1]) << "\n";
        rep(c2,0,c1){
            if(getb(P[c2], c1)){
                xo(P[c1], P[c2]);
               // cerr << P[c1] << " - " << P[c2] << ": " << (P[c1]) << "\n";
                P[c2] ^= P[c1];

            }
        }
    }

    cout << sz(ANS) << "\n";
    rep(c1,0,sz(ANS)){
        pll y = ANS[c1];
        cout << y.first << " " << OP[c1] << " " << y.second << "\n";
    }

   // cerr << sz(ANS) << "\n";
    if(S.find(1) == S.end()){
        cerr << "ERROR " << sz(P) << "\n";

    }

    return 0;
}