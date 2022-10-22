#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll big = 1000000007ll;
const ll big2 = 1000000009ll;
int n,m,k,q,w,h;

vector<vector<ll> > C(1000001, vector<ll>());
vector<vector<ll> > C2(1000001, vector<ll>());

vector<ll> W;
ll DP[1000001] = {0};

ll CO[1000001] = {0};
ll co = 0;

ll dfs(ll i, ll par){
    ll b = 0;
    CO[i] = co;
    W.push_back(i);
    for(ll c1 = 0; c1 < sz(C2[i]); c1++){
        ll a = C2[i][c1];
        if(a != par){
            b += dfs(a,i);
        }
    }
    return b+1;
}

ll dp(ll i, ll par){

    if(DP[i] != -1)return DP[i];
    ll ans = 0;
    for(ll c1 = 0; c1 < sz(C2[i]); c1++){
        ll a = C2[i][c1];
        if(a != par){
            ans += dp(a,i);
        }
    }
    DP[i] = ans+1;
    return ans+1;

}

ll tree(ll i){
    W.clear();
    ll siz = dfs(i,-1);
    for(ll c1 = 0; c1 < siz; c1++){
        DP[W[c1]] = -1;
    }
    return dp(i,-1);
}

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,d,e;

    scanf("%d", &n);
    for(ll c1 = 0; c1 < n; c1++){
        scanf("%d", &a);
        scanf("%d", &b);
        a--;
        b--;
        C[a].push_back(b);
        C2[a].push_back(b);
        C2[b].push_back(a);
    }

    ll ans = 1;
    for(ll c1 = 0; c1 < 2*n; c1++){

        if(CO[c1] == 0){
            co++;
            a = c1;
            while(1 == 1){
                if(CO[a] != 0 && CO[a] != co){
                    break;
                }
                if(sz(C[a]) == 0){
                    ans *= tree(a);
                    ans %= big;
                    break;
                }
                if(CO[a] == co){
                    ans *= 2 - (C[a][0] == a);
                    ans %= big;
                    break;
                }
                CO[a] = co;
                a = C[a][0];
            }
           // cout << c1+1 << " " << ans << "\n";
        }

    }
    cout << ans << "\n";
    return 0;
}