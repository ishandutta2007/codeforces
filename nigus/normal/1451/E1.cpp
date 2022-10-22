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

bool DEBUG = 0;

vl A;

int xor2(int i, int j){
    if(DEBUG){
        return (A[i]^A[j]);
    }
    cout << "XOR " << i+1 << " " << j+1 << "\n";
    fflush(stdout);
    int a;
    cin >> a;
    return a;
}

int and2(int i, int j){
    if(DEBUG){
        return (A[i]&A[j]);
    }
    cout << "AND " << i+1 << " " << j+1 << "\n";
    fflush(stdout);
    int a;
    cin >> a;
    return a;
}

int or2(int i, int j){
    if(DEBUG){
        return (A[i]|A[j]);
    }
    cout << "OR " << i+1 << " " << j+1 << "\n";
    fflush(stdout);
    int a;
    cin >> a;
    return a;
}

vl X;
vector<pii> XI;

int main() {
   // ios_base::sync_with_stdio(0);
   // cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    cin >> n;

    if(DEBUG){
        rep(c1,0,n){
           // A.push_back(random2()%n);
            A.push_back(c1);
        }
    }

    rep(c1,1,n){
        a = xor2(0,c1);
        XI.push_back({a,c1});
        X.push_back(a);
    }
    sort(all(XI));

    int x = -1;

    if(XI[0].first == 0){
        x = and2(0, XI[0].second);
    }

    rep(c1,0,n-2){
        if(XI[c1].first == XI[c1+1].first){
            int xo = XI[c1].first;
            int y = and2(XI[c1+1].second,XI[c1].second);
            x = (y^xo);
            break;
        }
    }
    vi ANS;

    if(x != -1){
        rep(c1,0,n){
            if(c1 == 0){
                ANS.push_back(x);
            }
            else{
                ANS.push_back(X[c1-1]^x);
            }
        }
    }
    else{
        int i1,i2;
        rep(c1,0,n-1){
            if(X[c1] == 1)i1 = c1+1;
            if(X[c1] == 2)i2 = c1+1;
        }
        int j1 = or2(0, i1);
        int j2 = or2(0, i2);
        x = 2*(j1/2) + j2%2;
        rep(c1,0,n){
            if(c1 == 0){
                ANS.push_back(x);
            }
            else{
                ANS.push_back(X[c1-1]^x);
            }
        }

    }

    cout << "! ";
    rep(c1,0,n){
        int y = ANS[c1];
        cout << y << " ";
        if(DEBUG){
            assert(y == A[c1]);
        }
    }cout << "\n";

    return 0;
}