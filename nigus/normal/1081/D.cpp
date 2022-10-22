#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
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

ll n,m,T,k,d;
const ll big = 1000000007;
const ll mod = 998244353;

ll deg[100001] = {0};
ll pek[100001] = {0};
ll special[100001] = {0};

vl A;
vl B;
vl W;
vl ind;

ll par(ll i){
ll i2 = i;
while(i2 != pek[i2]){i2 = pek[i2];}
return i2;
}

void merg(ll i, ll j){
    ll i2 = par(i);
    ll j2 = par(j);
    if(i2 != j2){
        if(deg[i2] < deg[j2])swap(i2,j2);
        deg[i2] += deg[j2];
        pek[j2] = i2;
        special[i2] += special[j2];
    }
}

bool comp(ll i, ll j){
    return W[i] < W[j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n >> m >> k;
    for(int c1 = 0; c1 < k; c1++){
        cin >> a;
        a--;
        special[a] = 1;
    }
    for(int c1 = 0; c1 < n; c1++){
        deg[c1] = 1;
        pek[c1] = c1;
    }
    for(int c1 = 0; c1 < m; c1++){
        cin >> a >> b >> c;
        a--;
        b--;
        A.push_back(a);
        B.push_back(b);
        W.push_back(c);
        ind.push_back(c1);
    }
    sort(all(ind),comp);

    ll w = -1;
    for(int c1 = 0; c1 < m ;c1++){
        a = ind[c1];
        merg(A[a],B[a]);
        ll i = par(A[a]);
        if(special[i] == k){
            w = W[a];
            break;
        }
    }

    for(int c1 = 0; c1 < k; c1++){
        cout << w << " ";
    }

    return 0;
}