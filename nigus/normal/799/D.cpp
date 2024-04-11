#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,T,k;
ll ar,br;
ll h,w;
vector<ll> A;

vector<ll> use;

ll prod = 1;

ll DP[60][100001] = {0};

ll act;

ll dp(ll i, ll j){
    if(h*j >= act)return j;
    if(i == use.size())return big*big;
    if(DP[i][j] != -1)return DP[i][j];

    ll ans = big*big;

    ans = min(ans , dp(i+1,j));
    ans = min(ans , dp(i+1,j*use[i]));
    DP[i][j] = ans;
    return ans;
}

bool test(ll a, ll b){


for(ll c1 = 0; c1 < 60; c1++){
    for(ll c2 = 0; c2 < 100001; c2++){
        DP[c1][c2] = -1;
    }
}
act = a;
ll d = dp(0ll,1ll);

//cout << h*prod << " " << a << " " << d << "\n";

if(h*prod < a)return 0;
if(w*(prod/d) >= b)return 1;
return 0;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c;

    cin >> ar >> br >> h >> w >> n;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }
    sort(all(A));
    reverse(all(A));

    ll ans = -1;

    if((h >= ar && w >= br) || (h >= br && w >= ar)){
        ans = 0;
    }
    else{
        for(ll c1 = 0; c1 < n; c1++){
            prod *= A[c1];
            use.push_back(A[c1]);
            if(test(ar,br) || test(br,ar)){
                ans = c1+1;
                break;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}