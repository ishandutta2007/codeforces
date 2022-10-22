#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<double,double> pdd;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,T,q;

vector<vi> C(701, vi());
vl A;

bool E[701][701] = {0};

ll gcd(ll i, ll j){
    if(j == 0)return i;
    return gcd(j,i%j);
}

bool mark[701] = {0};
ll marked = 0;

void dfs(ll i){
    mark[i] = 1;
    marked++;
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        ll a = C[i][c1];
        if(!mark[a]){
            dfs(a);
        }
    }
}

ll DP[701][701] = {0};
bool DPC[701][701] = {0};

bool dp(ll i, ll to){
    if(to == i)return 1;
    if(DPC[i][to])return DP[i][to];
    bool ans = 0;
    if(to < i){
        for(int c1 = i-1; c1 >= to; c1--){
            if(E[i][c1]){
                bool temp = (dp(c1,to)&dp(c1,i-1));
                if(temp)ans = 1;
            }
            if(ans)break;
        }
    }
    else{
        for(int c1 = i+1; c1 <= to; c1++){
            if(E[i][c1]){
                bool temp = (dp(c1,to)&dp(c1,i+1));
                if(temp)ans = 1;
            }
            if(ans)break;
        }
    }
    DPC[i][to] = 1;
    DP[i][to] = ans;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c;

    cin >> n;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }

    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = c1+1; c2 < n; c2++){
            if(gcd(A[c1],A[c2]) > 1){
                C[c1].push_back(c2);
                C[c2].push_back(c1);
                E[c1][c2] = 1;
                E[c2][c1] = 1;
            }
        }
    }

    dfs(0);
    if(marked != n){
        cout << "No\n";
    }
    else{
        bool ans = 0;
        for(int c1 = 0; c1 < n; c1++){
            ans |= (dp(c1,0)&dp(c1,n-1));
        }
        if(ans){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }

    }

    return 0;
}