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

vi A;
vector<vi> C(500001, vi());

set<ll> S;
vi Q;

ll ans = 0;


ll mi(){
    return (*S.begin())/n;
}

ll mi2(){
    ll a = 1;
    ll mii = big*big;
    for(int t = 1; sz(Q)-t >= 0; t *= 2){
        mii = min(mii,a*A[Q[sz(Q)-t]]);
        a++;
    }
    mii = min(mii,a*A[Q[0]]);
    return mii;
}

void ins(ll i, ll j){
    S.insert(i*n+j);
}

void rms(ll i, ll j){
    S.erase(i*n+j);
}

void add(ll i){
    Q.push_back(i);

}

void rm(){

    Q.pop_back();
}

void dfs(ll i, ll par){

    if(par != -1){
        //cerr << (*S.begin()).second+1 << " " << i+1 << "\n";

        ans += mi2();
    }

    add(i);
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        ll a = C[i][c1];
        if(a != par){
            dfs(a,i);
        }
    }
    rm();
    /*
    cerr << i+1 << "\n";
    for(auto i : S){
        cerr << i.first << " - " << i.second+1 << "\n\n";
    }*/
}

int main() {
    //ios_base::sync_with_stdio(0);
   // cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,e;
    scanf("%d",&n);
    int root = 0;
    int best = big;
    for(int c1 = 0; c1 < n; c1++){
        scanf("%d",&a);
        A.push_back(a);
        if(a < best){
            best = a;
            root = c1;
        }
        ans += a;
    }

    for(int c1 = 0; c1 < n-1; c1++){
        scanf("%d",&a);
        scanf("%d",&b);
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    dfs(root,-1);
    cout << ans-best << "\n";

    return 0;
}