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

int n,m,T,k,d;
const ll big = 1000000007;

vi A;
vector<vi> C(500001, vi());

ll DP[300001] = {0};
ll DPC[300001] = {0};

ll DP2[300001] = {0};
ll DPC2[300001] = {0};

ll best = -big*big;

ll dp(ll i, ll par){
    if(DPC[i])return DP[i];
    ll ans = A[i];
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        ll a = C[i][c1];
        if(a != par){
            ans += max(0ll,dp(a,i));
        }
    }
    DPC[i] = 1;
    DP[i] = ans;
    return ans;
}

ll hej = 0;

ll dp2(ll i, ll par){
    if(DPC2[i])return DP2[i];
    ll ans = A[i];
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        ll a = C[i][c1];
        if(a != par){
            ans += max(0ll,dp2(a,i));
        }
    }
    if(ans == best){hej++;ans=-big;}
    DPC2[i] = 1;
    DP2[i] = ans;
    return ans;
}

int main() {
    //ios_base::sync_with_stdio(0);
   // cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,e;
    scanf("%d",&n);
    //n = 300001;
    int root = 0;
    for(int c1 = 0; c1 < n; c1++){
        scanf("%d",&a);
        //a = (ll(rand())*ll(RAND_MAX)*10ll+ll(rand()))%2000000000ll-1000000000ll;
       // cerr << a << "\n";
        A.push_back(a);
    }

    for(int c1 = 0; c1 < n-1; c1++){
       scanf("%d",&a);
        scanf("%d",&b);
      /*
        a = c1+1+1;
        b = rand()%(c1+1)+1;
        */
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    dp(0,-1);
    for(int c1 = 0; c1 < n; c1++){
        best = max(best,DP[c1]);
    }
    dp2(0,-1);

    cout << best*hej<< " " << hej << "\n";

    return 0;
}