#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
const int mod = 998244353;

ll n,m,k,q,p;
ll T;

vi ind;
vi X;
vi A;
vector<bool> kind;

int H[10001] = {0};
bool YES[10001] = {0};

vi ANS;

void add(int x){
    for(int c1 = n; c1 >= x; c1--){
        H[c1] += H[c1-x];
        if(H[c1] > mod)H[c1] -= mod;
        YES[c1] |= (H[c1] != 0);
    }
}

void sub(int x){
    for(int c1 = x; c1 <= n; c1++){
        H[c1] -= H[c1-x];
        if(H[c1] < 0)H[c1] += mod;
    }
}

bool comp(int i, int j){
    return A[i] < A[j];
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    H[0] = 1;
    YES[0] = 1;
    cin >> n >> q;
    //n = 10000;
    //q = 10000;
    for(int c1 = 0; c1 < q; c1++){
        cin >> a >> b >> c;

        b++;
        if(b <= n){
            kind.push_back(1);
            X.push_back(c);
            ind.push_back(sz(ind));
            A.push_back(b);
        }
        kind.push_back(0);
        X.push_back(c);
        ind.push_back(sz(ind));
        A.push_back(a);
    }
    sort(all(ind),comp);

    for(int c1 = 0; c1 < sz(ind); c1++){
        a = ind[c1];
        if(kind[a] == 0){
            add(X[a]);
        }
        else{
            sub(X[a]);
        }
    }

    for(int c1 = 1; c1 <= n; c1++){
        if(YES[c1])ANS.push_back(c1);
    }

    cout << sz(ANS) << "\n";
    for(int c1 = 0; c1 < sz(ANS); c1++){
        cout << ANS[c1] << " ";
    }

    return 0;
}