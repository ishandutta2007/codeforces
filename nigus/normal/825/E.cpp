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

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,T,k,q;

vector<vector<ll> > C(100001, vector<ll>());
vector<vector<ll> > C2(100001, vector<ll>());

ll indeg[100001];
ll deg[100001];

ll indeg2[100001];
ll deg2[100001];

ll ANS[100001] = {0};

ll DP[100001] = {0};

ll FDP[100001] = {0};

ll dp(ll i){
    if(DP[i] != big)return DP[i];
    DP[i] = i;
    for(ll c1 = 0; c1 < deg[i]; c1++){
        ll a = C[i][c1];
        DP[i] = min(DP[i], dp(a));
    }
    return DP[i];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> m;
    for(ll c1 = 0; c1 < m; c1++){
        cin >> a >> b;
        a--;
        b--;
        deg[a]++;
        indeg[b]++;
        C[a].push_back(b);
    }

    for(ll c1 = 0; c1 < n; c1++){
        DP[c1] = big;
    }

    for(ll c1 = 0; c1 < n; c1++){
        FDP[dp(c1)]++;
    }

    for(ll c1 = 0; c1 < n; c1++){

        for(ll c2 = 0; c2 < deg[c1]; c2++){
            ll a = C[c1][c2];
            if(dp(c1) == dp(a)){
                deg2[a]++;
                indeg2[c1]++;
                C2[a].push_back(c1);
            }
        }
    }

    ll now = 0;

    for(ll c1 = 0; c1 < n; c1++){
        if(dp(c1) == c1){
            now += FDP[c1];
            ll now2 = now;
            priority_queue<ll> pq;
            pq.push(c1);
            while(!pq.empty()){
                a = pq.top();
                pq.pop();
                ANS[a] = now2;
                now2--;
                for(ll c2 = 0; c2 < deg2[a]; c2++){
                    ll b = C2[a][c2];
                    indeg2[b]--;
                    if(indeg2[b] == 0){
                        pq.push(b);
                    }
                }
            }
        }
    }

    for(ll c1 = 0; c1 < n; c1++){
        cout << ANS[c1] << " ";
    }

    return 0;
}