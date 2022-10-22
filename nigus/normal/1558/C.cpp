//#pragma GCC optimize("O3")   //
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

const int big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 40004;

vi A;
vi ANS;

int var[MAXN] = {0};

void prnt(){
    trav(a, A){
        cerr << a+1 << " ";
    }cerr << "\n";

    rep(c1,0,n){
        cerr << var[c1] << " ";
    }cerr << "\n-----------\n";

}

void mov(int x){
 /*   if(x%2 != 1){
        cerr << "EVEN!!! " << x << "\n";
    }*/
    x++;
    /*cerr << "HEJ " << x << "\n";
    prnt();
    cerr << "\n";*/
    rep(c1,0,x/2){
        swap(A[c1], A[x-c1-1]);
        var[A[c1]] = c1;
        var[A[x-c1-1]] = x-c1-1;
    }
    ANS.push_back(x);
}

void solve(int k){
    if(k<=1)return;
   // cerr << "SOLVING " << k << "\n";
    mov(var[k-1]);
    mov(var[k-2]-1);
    mov(var[k-2]+1);
    mov(var[k-1]);
    mov(k-1);
    solve(k-2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;

    rep(c4,0,T){
        cin >> n;
        A.clear();
        ANS.clear();
        bool fail = 0;
        rep(c1,0,n){
            cin >> a;
            a--;
            if(a%2 != c1%2)fail = 1;
            var[a] = c1;
            A.push_back(a);
        }
        if(fail){
            cout << "-1\n";
        }
        else{
            solve(n);
            cout << sz(ANS) << "\n";
            trav(y, ANS){
                cout << y << " ";
            }cout << "\n";

           // prnt();
        }
    }

    return 0;
}