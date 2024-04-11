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

bool DEBUG = 0;
vi H;

ll Q = 0;

int MEM[2049][2049] = {0};
int CC[2049][2049] = {0};
int cc = 0;

int ask(int i, int j){

    if(i > j){
        swap(i,j);
    }
    if(MEM[i][j] != 0 && CC[i][j] == cc)return MEM[i][j];
    cout << "? " << i+1 << " " << j+1 << "\n";
    Q++;
    fflush(stdout);
    if(DEBUG){
        m = (H[i]|H[j]);
    }
    else{
        cin >> m;
    }
    MEM[i][j] = m;
    CC[i][j] = cc;
    return m;
}

vl A, I;

bool comp(ll i, ll j){
    return A[i] < A[j];
}

int select(int x){
    int mi = 21;
    int ans = 0;
    rep(c1,0,20){
        int y = random2()%n;
        while(y == x){
            y = random2()%n;
        }
        int a = ask(x,y);
        int pc = __builtin_popcount(a);
        if(pc < mi){
            mi = pc;
            ans = y;
        }
    }
    return ans;
}

int main() {
  //  ios_base::sync_with_stdio(0);
  //  cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;
//////////

    T = 1;
    cin >> n;
    rep(c4,0,T){

    cc++;
    Q = 0;
    H.clear();
    A.clear();
    I.clear();


    if(DEBUG){

        rep(c1,0,n){
           // cin >> a;
            H.push_back(c1);
        }
        random_shuffle(all(H));
    }

    ll n2 = n;
    rep(c1,0,n){
        I.push_back(c1);
        A.push_back(-1);
    }

    int i0 = -1;

    while(1){
        ll r = random2()%n2;

        if(n2 == n){
            rep(c2,0,4){
                r = select(r);
            }
        }

        rep(c1,0,n2){
            if(c1 != r){
                A[I[c1]] = (ask(I[r], I[c1]));
            }
            else{
                A[I[c1]] = 21234789;
            }
        }

        ll a0 = (1 << 15)-1;
        rep(c1,0,n2){
            if(c1 != r)a0 &= A[I[c1]];
        }

        if(a0 == 0){
            i0 = I[r];
            break;
        }

        vi J;
        trav(i, I){
            if(A[i] == a0){
                J.push_back(i);
            }
        }
        I.clear();
        trav(j,J){
            I.push_back(j);
        }
        n2 = sz(J);
        if(n2 == 1){
            i0 = J[0];
            break;
        }
    }


    vi B;
    rep(c1,0,n){
        if(c1 != i0){
            B.push_back(ask(c1, i0));
        }
        else{
            B.push_back(0);
        }
    }

    cout << "! ";
    rep(c1,0,n){
        cout << B[c1] << " ";
        if(DEBUG)assert(B[c1] == H[c1]);
    }cout << "\n";
    fflush(stdout);


    if(DEBUG){
        cerr << c4 << ": " << "QUERIES: " << Q << "\n";
        assert(Q <= 4269);
    }
    }
    return 0;
}