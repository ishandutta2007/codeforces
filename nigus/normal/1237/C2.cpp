#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 300001;

struct pt{
    ll x,y,z;
};

vi ind;
vector<pt> P;

ll A[MAXN][3] = {0};
ll B[MAXN] = {0};

ll ig = 0;
bool comp(ll i, ll j){
    if(ig == 1){
        if(A[i][ig] == A[j][ig]){
            return A[i][ig+1] < A[j][ig+1];
        }
    }
    return A[i][ig] < A[j][ig];
}

vector<pii> ANS;

bool mark[MAXN] = {0};


bool same(ll i, ll j, ll dim){
    rep(c1,dim,3){
        if(A[i][c1] != A[j][c1])return 0;
    }
    return 1;
}

int solve(vi & I, int dim){
    if(dim == 3){
    /*
        trav(i,I){
        cerr << i+1 << " ";
        }cerr << "\n";
*/
        for(int c1 = 0; c1 < sz(I)-1; c1+=2){
            cout << I[c1]+1 << " " << I[c1+1]+1 << "\n";
            B[I[c1]] = I[c1+1];
            B[I[c1+1]] = I[c1];
            ANS.push_back({I[c1]+1, I[c1+1]+1});
        }//cerr << "\n";
        if(sz(I)%2 == 0)return -1;
        return I.back();
    }
    if(sz(I) == 0)return -1;
    ig = dim;
    sort(all(I), comp);

    /*
    cerr << dim << ": \n";
    trav(i,I){
        cerr << i+1 << " ";
    }cerr << "\n";
*/
    vi blocked(sz(I));
    blocked[0] = 0;
    rep(c1,1,sz(I)){
        blocked[c1] = 0;
        if(same(I[c1-1],I[c1],dim)){
            cout << I[c1-1]+1 << " " << I[c1]+1 << "\n";
            blocked[c1] = 1;
            blocked[c1-1] = 1;
        }
    }
    ll prev = A[I[0]][dim];

    vi J;
    rep(c1,0,sz(I)){
        ll i = I[c1];
        if(blocked[c1])continue;
        if(A[i][dim] != prev){
            int extra = solve(J, dim+1);
            J.clear();
            if(extra != -1){
                J.push_back(extra);
            }
        }
        J.push_back(i);
        prev = A[i][dim];
    }
    int extra = solve(J,dim+1);
    return extra;
}

vl X,Y,Z;

bool comp2(ll i, ll j){
    if(X[i] == X[j] && Y[i] == Y[j]){
        return Z[i] < Z[j];
    }
    if(X[i] == X[j]){
        return Y[i] < Y[j];
    }
    return X[i] < X[j];
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    vi ind2;
    rep(c1,0,n){
        cin >> a >> b >> c;
        ind.push_back(c1);
        A[c1][0] = a;
        A[c1][1] = b;
        A[c1][2] = c;
        X.push_back(a);Y.push_back(b);Z.push_back(c);
        P.push_back({a,b,c});
        ind2.push_back(c1);
    }
    solve(ind,0);
    sort(all(ind2),comp2);
    reverse(all(ind2));
    vector<pll> ANS2;


    rep(c1,0,n){
        a = ind2[c1];
        if(!mark[a] && !mark[B[a]]){
         //   cout << a+1 << " " << B[a]+1 << "\n";
            ANS2.push_back({a+1,B[a]+1});
            mark[a] = 1;
            mark[B[a]] = 1;
        }
    }
    reverse(all(ANS2));

    /*
    trav(p,ANS2){
        cout << p.first << " " << p.second << "\n";
    }
    */

    return 0;
}