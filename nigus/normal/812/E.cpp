#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll big = 1000000007ll;
ll big2 = 1000000009ll;

ll n,m,T,k,q;
vector<vector<ll> > C(200001 , vector<ll>());
vector<ll> A;
bool parity[100001] = {0};
unordered_map<ll,ll> M;
ll nm = 0;
ll F[100001][2] = {0};
ll l = 0;
ll xo = 0;

void dfs(ll i, ll par){
    parity[i] = 0;
    for(ll c1 = 0; c1 < sz(C[i]); c1++){
        ll a = C[i][c1];
        if(a != par){
            dfs(a,i);
            parity[i] = 1^parity[a];
        }
    }
    if(parity[i] == 0)l++,xo^=A[i];
    F[M[A[i]]][parity[i]]++;
}

int main()
{
   //freopen("input.txt","r",stdin);
   //freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    vector<ll> B;
    cin >> n;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
        if(M.find(a) == M.end())M[a] = nm, nm++, B.push_back(a);
    }
    for(ll c1 = 0; c1 < n-1; c1++){
        cin >> a;
        C[a-1].push_back(c1+1);
    }
    dfs(0,-1);
    k = n-l;
    ll ans = (l*(l-1))/2 + (k*(k-1))/2;
    if(xo != 0)ans = 0;
    for(ll c1 = 0; c1 < nm; c1++){
        a = B[c1]^xo;
        if(M.find(a) != M.end()){
            ans += F[c1][0]*F[M[a]][1];
        }
    }
    cout << ans << "\n";

    return 0;
}