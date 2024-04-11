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

ll n,m,T,k,q;
const ll big = 1000000007;
const ll big2 = 998244353;

const ll MAXN = 300000;

vector<vl> C(MAXN, vl());

vector<vl> CB(MAXN, vl());


ll DEPTH[MAXN] = {0};
ll PAR[MAXN] = {0};
bool leaf[MAXN] = {0};

vl leaves;

bool mark[MAXN] = {0};

ll best = 0;
ll bd = 0;

void dfs(ll i, ll d){
    DEPTH[i] = d;
    if(d > bd){
        bd = d;
        best = i;
    }
    mark[i] = 1;
    leaf[i] = 1;
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        ll a = C[i][c1];
        if(!mark[a]){
            leaf[i] = 0;
            PAR[a] = i;
            dfs(a,d+1);
        }
        else{
            if(a != PAR[i])CB[i].push_back(a);
        }
    }
    if(leaf[i])leaves.push_back(i);
    return;
}

vector<vl> cyc;
vl cc;

void fix(ll i){
    cc.clear();
    ll ai = CB[i][0];
    ll bi = CB[i][1];
    ll a = DEPTH[i]-DEPTH[ai];
    ll b = DEPTH[i]-DEPTH[bi];
    if(a > b){
        swap(a,b);
        swap(ai,bi);
    }
    b = b-a;
    if((a+1)%3 != 0){

        cc.push_back(i);
        ll i2 = i;
        while(i2 != ai){
            cc.push_back(PAR[i2]);
            i2 = PAR[i2];
        }cyc.push_back(cc);
        return;
    }

    if((a+b+1)%3 != 0){
        cc.push_back(i);
        ll i2 = i;
        while(i2 != bi){
            cc.push_back(PAR[i2]);
            i2 = PAR[i2];
        }cyc.push_back(cc);
        return;
    }
    cc.push_back(i);
    cc.push_back(ai);
    ll i2 = ai;
    while(i2 != bi){
        cc.push_back(PAR[i2]);
        i2 = PAR[i2];
    }

    cyc.push_back(cc);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n >> m >> k;
    for(int c1 = 0; c1 < m; c1++){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }

    PAR[0] = -1;
    dfs(0,0);

    if((bd+1)*k >= n){
        cout << "PATH\n";
        cout << bd+1 << "\n";
        a = best;
        while(a != -1){
            cout << a+1 << " ";
            a = PAR[a];
        }
        return 0;
    }

    cout << "CYCLES\n";

    for(int c1 = 0; c1 < k; c1++){
        fix(leaves[c1]);
        cout << sz(cyc[c1]) << "\n";
        for(int c2 = 0; c2 < sz(cyc[c1]); c2++){
            cout << cyc[c1][c2]+1 << " ";
        }cout << "\n";
    }

    return 0;
}