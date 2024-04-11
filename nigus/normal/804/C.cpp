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
int n,m,q,T,k;

vector<vector<ll> > C(300001 , vector<ll>());
vector<vector<ll> > CCOL(300001 , vector<ll>());
int mc = 1;

bool tak[500001] = {0};
ll ANS[300001] = {0};

ll mex(ll i, ll start){
ll ans = 0;
for(ll c1 = start; c1 < start+i; c1++){
    if(tak[c1] == 0)return c1;
}
return i+1;
}

void dfs(ll i, ll par){

for(ll c1 = 0; c1 < CCOL[i].size(); c1++){
    ll a = CCOL[i][c1];
    if(ANS[a] != -1){
        tak[ANS[a]] = 1;
    }
}
ll st = 0;
for(ll c1 = 0; c1 < CCOL[i].size(); c1++){
    ll a = CCOL[i][c1];
    if(ANS[a] == -1){
        ll me = mex(CCOL[i].size(), st);
        ANS[a] = me;
        tak[ANS[a]] = 1;
        st = ANS[a]+1;
    }
}
for(ll c1 = 0; c1 < CCOL[i].size(); c1++){
    ll a = CCOL[i][c1];
    tak[ANS[a]] = 0;
}

for(ll c1 = 0; c1 < C[i].size(); c1++){
    ll b = C[i][c1];
    if(b != par){
        dfs(b,i);
    }
}
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    int a,b,c,d;

    scanf("%d %d" , &n ,&m);
    for(ll c1 = 0; c1 < n; c1++){
        scanf("%d" , &a);
        for(ll c2 = 0; c2 < a; c2++){
            scanf("%d" , &b);
            CCOL[c1].push_back(b-1);
        }
        mc = max(mc, a);
    }
    for(ll c1 = 0; c1 < m; c1++){
        ANS[c1] = -1;
    }
    for(ll c1 = 0; c1 < n-1; c1++){
        scanf("%d" , &a);
        scanf("%d" , &b);
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    dfs(0,-1);
    cout << mc << "\n";
    for(ll c1 = 0; c1 < m; c1++){
        if(ANS[c1] == -1)ANS[c1] = 0;
        cout << ANS[c1]+1 << " ";
    }
    return 0;
}