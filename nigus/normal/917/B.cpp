#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;

ll n,m,k,T;

vector<vl> C(101, vl());
vector<vl> CW(101, vl());

bool DP[101][101][26] = {0};
bool DPC[101][101][26] = {0};

bool dp(ll i, ll j, ll c){
    if(DPC[i][j][c])return DP[i][j][c];
    bool ans = 0;
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        ll a = C[i][c1];
        ll w = CW[i][c1];
        if(w >= c)ans |= (!dp(j,a,w));
    }
    DPC[i][j][c] = 1;
    DP[i][j][c] = ans;
    return ans;
}

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n >> m;
    char ch;
    for(int c1 = 0; c1 < m; c1++){
        cin >> a >> b >> ch;
        a--;
        b--;
        c = ch-'a';
        C[a].push_back(b);
        CW[a].push_back(c);
    }
    for(ll c1 = 0; c1 < n; c1++){
        for(ll c2 = 0; c2 < n; c2++){
            if(dp(c1,c2,0)){
                cout << "A";
            }
            else{
                cout << "B";
            }
        }
        cout << "\n";
    }

    return 0;
}