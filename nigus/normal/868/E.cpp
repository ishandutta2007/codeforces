#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll big = 1000000007ll;
const ll big2 = 1000000009ll;
ll n,m,k,q,w,h,T;
ll start;
vector<vector<ll> > C(51, vector<ll>());
vector<vector<ll> > CW(51, vector<ll>());

ll D[51][51] = {0};

ll X[51] = {0};

void dfs(ll i, ll j, ll par){
    D[i][i] = 0;
    for(ll c1 = 0; c1 < sz(C[j]); c1++){
        ll a = C[j][c1];
        ll w = CW[j][c1];
        if(a != par){
            D[i][a] = D[i][j] + w;
            dfs(i,a,j);
        }
    }
}

ll DP[51][51] = {0};
bool DPC[51][51] = {0};

ll ST[51] = {0};

ll F[51] = {0};

ll nst = 0;

vector<ll> L;
ll nl;

ll dp(ll i, ll j){
    //cout << i << " " << j << "\n";
    if(j == 0)return 0;
    if(DPC[i][j])return DP[i][j];
    ll ans = 0;
    for(ll c1 = 0; c1 < nl; c1++){

        if(c1 != i){
            //bool done = 0;
            for(ll c2 = 1; c2 <= j; c2++){

                ll left = j-c2;
                ll ext = D[L[i]][L[c1]] + dp(c1,left);
                ll sum = 0;
                if(ext <= ans)continue;
               // if(left == 0)continue;
                for(ll c3 = 0; c3 < nl; c3++){
                    if(c3 != i && c3 != c1 && left != 0){

                        ll l = j-left;
                        ll r = j;
                        ll bsans = l;
                       // cout << l << " -  " << i << " " << j << "  " << left << "\n";
                        if(D[L[i]][L[c3]] + dp(c3,l) < ext){
                            while(l < r-1){
                                ll mid = (l+r)/2;
                                if(D[L[i]][L[c3]] + dp(c3,mid) >= ext){
                                    r = mid;
                                }
                                else{
                                    l = mid;
                                }
                            }
                            bsans = r;
                        }
                        sum += j-bsans;
                        /*
                        for(ll c4 = left; c4 > 0; c4--){
                            if(D[L[i]][L[c3]] + dp(c3,j-c4) >= ext){sum += c4; break;}
                        }
                        */
                    }
                    if(sum >= left)break;
                }

                if(sum >= left){
                    ans = max(ans,ext);
                    break;
                }

            }

        }

    }

    DPC[i][j] = 1;
    DP[i][j] = ans;
    return ans;
}

ll solve(){
    ll ans = 0;
    for(ll c1 = 0; c1 < nl; c1++){
        if(L[c1] != start){
            for(ll c2 = 1; c2 <= m; c2++){

                ll left = m-c2;
                ll ext = D[start][L[c1]] + dp(c1,left);
                if(ext <= ans)continue;
                ll sum = 0;


                ll F2[51] = {0};

                F2[ST[L[c1]]] += c2;

                for(ll c3 = 0; c3 < nl; c3++){
                    if(L[c3] != start && c3 != c1){
                        for(ll c4 = left; c4 > 0; c4--){

                            if(D[start][L[c3]] + dp(c3,m-c4) >= ext){F2[ST[L[c3]]] += c4; break;}
                        }

                    }
                }

                bool yes = 1;
                for(ll c3 = 0; c3 < nst; c3++){
                    //cout << F2[c3] << " " << F[c3] << "  -  " << ext << "   c2: " << c2 << "  L[c1]+1: " << L[c1]+1 << "  ST[c1]: " << ST[L[c1]] << "\n";
                    if(F2[c3] < F[c3])yes = 0;
                }//cout << "\n";
                if(yes){
                    ans = max(ans,ext);
                }

            }
        }
    }
return ans;
}

ll dfs2(ll i, ll par){
    for(ll c1 = 0; c1 < sz(C[i]); c1++){
        ll a = C[i][c1];
        if(a != par){
            //cout << a+1 << " " << i+1 << "\n";
            if(par == -1){
                ST[a] = nst;
                nst++;
            }
            else{
                ST[a] = ST[i];
            }
            F[ST[a]] += X[a];
            dfs2(a,i);
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;
    for(ll c1 = 0; c1 < n-1; c1++){
        cin >> a >> b >> c;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
        CW[a].push_back(c);
        CW[b].push_back(c);
    }
    cin >> start;start--;
    cin >> m;
    for(ll c1 = 0; c1 < m; c1++){
        cin >> a;
        X[a-1]++;
    }
    for(ll c1 = 0; c1 < n; c1++){
        dfs(c1,c1,-1);
        if(sz(C[c1]) == 1){
            L.push_back(c1);
        }
    }
    nl = sz(L);
    dfs2(start,-1);
   // for(ll c1 = 0; c1 < n; c1++){
       // cout << c1+1 << "  " << ST[c1] << "\n";
   // }

    cout << solve() << "\n";


    return 0;
}