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

vector<vl> C(300001, vl());
vector<vl> CW(300001, vl());
vl W;


ll DP2[300001] ={0};
bool DPC2[300001] = {0};


ll dp2(ll i, ll par){
    if(DPC2[i])return DP2[i];
    ll ans = W[i];
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        ll a = C[i][c1];
        if(a != par){
            ans = max(dp2(a,i)-CW[i][c1]+W[i],ans);
        }
    }
    DPC2[i] = 1;
    DP2[i] = ans;
    return ans;
}

ll DP[300001] = {0};
bool DPC[300001] = {0};

vl B;

ll dp(ll i, ll par){
    if(DPC[i])return DP[i];
    ll ans = W[i];
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        ll a = C[i][c1];
        if(a != par){
            ans = max(dp(a,i),ans);
        }
    }
    B.clear();
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        ll a = C[i][c1];
        if(a != par){
            B.push_back(dp2(a,i)-CW[i][c1]);
        }
    }
    B.push_back(0);
    B.push_back(0);
    sort(all(B));
    reverse(all(B));

    ll temp = B[0]+B[1]+W[i];
    ans = max(temp,ans);
    DPC[i] = 1;
    DP[i] = ans;
    return ans;

}

int main() {
   // ios_base::sync_with_stdio(0);
   // cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,e;


   scanf("%d",&n);
    //n = 300001;
    for(int c1 = 0; c1 < n; c1++){

        scanf("%d",&a);
       // a = 1e9;
        W.push_back(ll(a));
    }
    for(int c1 = 0; c1 < n-1; c1++){

       scanf("%d",&a);
       scanf("%d",&b);
       scanf("%d",&c);
        //a = c1+1+1;
        //b = (RAND_MAX*rand()+rand())%(c1+1)+1;
        //c = rand();
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
        CW[a].push_back(c);
        CW[b].push_back(c);
    }
    ll an = dp(0,-1);

    cout << an << "\n";
    return 0;
}