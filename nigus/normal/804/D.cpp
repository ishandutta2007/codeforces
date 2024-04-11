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
ll n,m,q,T,k;

vector<vector<ll> > C(100001 , vector<ll>());
unordered_map<ll,ll> M;
vector<ll> D;
vector<ld> ex;
vector<ll> diam;

vector<vector<ll> > CS(100001 , vector<ll>());

vector<vector<ll> > D2(100001 , vector<ll>());
vector<ll> temp;

ll sum = 0;
ll nodes = 0;
ll bel[100001] = {0};
ll now = 0;
ll longest = 0;


ll has(ll i, ll par){
    return (par+1)*200000 + i;
}

ll dp(ll i, ll par){
ll h = has(i,par);
if(M.find(h) != M.end())return M[h];
ll ans = 0;

for(ll c1 = 0; c1 < C[i].size(); c1++){
    ll a = C[i][c1];
    if(a != par){
        ans = max(ans , 1+dp(a,i));
    }
}
M[h] = ans;
return ans;
}

void dfs(ll i, ll par){
    bel[i] = now;
    sum += D[i];
    temp.push_back(D[i]);
    longest = max(longest , D[i]);
    nodes++;
    for(ll c1 = 0; c1 < C[i].size(); c1++){
        ll a = C[i][c1];
        if(a != par){
            dfs(a,i);
        }
    }
}

ll has2(ll i, ll j){
ll i2 = min(i,j);
ll j2 = max(i,j);
return 100001 * i2 + j2;
}

ll bs(ll ind , ll k){


ll l = 0;
ll r = D2[ind].size();

if(D2[ind][l] >= k)return -1;

while(l < r-1){

    ll mid = (l+r)/2;
    if(D2[ind][mid] < k){
        l = mid;
    }
    else{
        r = mid;
    }
}

return l;

}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n >> m >> q;

    for(ll c1 = 0; c1 < m; c1++){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    for(ll c1 = 0; c1 < n; c1++){
        D.push_back(dp(c1,-1));
        bel[c1] = -1;
    }

    for(ll c1 = 0; c1 < n; c1++){
        if(bel[c1] == -1){
            sum = 0;
            nodes = 0;
            longest = 0;
            temp.clear();
            dfs(c1,-1);
            now++;
            sort(all(temp));
            for(ll c2 = 0; c2 < temp.size(); c2++){
                D2[now-1].push_back(temp[c2]);
            }
            diam.push_back(longest);
            ex.push_back(ld(sum) / ld(nodes));
            CS[now-1].push_back(0);
            for(ll c2 = 0; c2 < temp.size(); c2++){
                CS[now-1].push_back(CS[now-1][c2] + D2[now-1][c2]);
            }
            //cout << sum << " " << nodes << "  gf\n";
        }
    }


    unordered_map<ll,ld> M2;

    for(ll c1 = 0; c1 < q; c1++){
        cin >> a >> b;
        a--;
        b--;

       // cout << bel[a] << " " << bel[b] <<  "\n";

        if(bel[a] == bel[b]){
            cout << "-1\n";
        }
        else{

            a = bel[a];
            b = bel[b];

            ll h = has2(a,b);
            if(M2.find(h) != M2.end()){
                cout << setprecision(18) << M2[h] << "\n";
            }
            else{
                  ll a2,b2;
                  if(D2[a].size() < D2[b].size()){
                    a2 = a;
                    b2 = b;
                  }
                  else{
                    a2 = b;
                    b2 = a;
                  }
                  ll ans = 0;
                  ll dia = max(diam[a],diam[b]);

                  for(ll c2 = 0; c2 < D2[a2].size(); c2++){
                    ll a3 = D2[a2][c2];
                    ll i2 = bs(b2 , dia - 1 - a3);
                    ans += CS[b2][D2[b2].size()] - CS[b2][i2+1] + (a3+1) * (D2[b2].size() - i2 - 1);
                    ans += (i2+1) * dia;
                   // cout << i2 << " " << CS[b2][D2[b2].size()] - CS[b2][i2+1] + a + D2[b2].size() - i2 - 1 << "  fd\n";  //
                  }




                  ld ans2 = ld(ans) / ld(D2[a2].size() * D2[b2].size());
                  M2[h] = ans2;


                cout << setprecision(18) << M2[h] << "\n";

            }
        }
    }

    return 0;
}