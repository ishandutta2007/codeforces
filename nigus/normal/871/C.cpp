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

vector<ll> X;
vector<ll> Y;
vector<ll> ind;

vector<vector<ll> > C(100001, vector<ll>());

unordered_set<ll> SX;
unordered_set<ll> SY;

ll nxy = 0;
bool mark[100001] = {0};
bool cyc = 0;

ll TWO[400001] = {0};

bool comp1(ll i, ll j){
    return X[i] < X[j];
}

bool comp2(ll i, ll j){
    return Y[i] < Y[j];
}

void dfs(ll i, ll par){
    mark[i] = 1;
    ll x = X[i];
    ll y = Y[i];
    if(SX.find(x) == SX.end()){
        SX.insert(x);
        nxy++;
    }
    if(SY.find(y) == SY.end()){
        SY.insert(y);
        nxy++;
    }
    for(ll c1 = 0; c1 < sz(C[i]); c1++){
        ll a = C[i][c1];
        if(a != par){
            if(mark[a]){
                cyc = 1;
            }
            else{
                dfs(a,i);
            }
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a >> b;
        X.push_back(a);
        Y.push_back(b);
        ind.push_back(c1);
    }

    ll t = 1;
    for(ll c1 = 0; c1 < 400001; c1++){
        TWO[c1] = t;
        t *= 2;
        t %= big;
    }

    vector<ll> ind2;

    sort(all(ind),comp1);
    ll prev = X[ind[0]];
    for(ll c1 = 0; c1 < n; c1++){
        a = ind[c1];
        if(X[a] != prev){
            sort(all(ind2),comp2);
            for(ll c2 = 1; c2 < sz(ind2); c2++){
                b = ind2[c2-1];
                c = ind2[c2];
                C[b].push_back(c);
                C[c].push_back(b);
            }
            ind2.clear();
        }
        ind2.push_back(a);
        prev = X[a];
    }

    sort(all(ind2),comp2);
    for(ll c2 = 1; c2 < sz(ind2); c2++){
        b = ind2[c2-1];
        c = ind2[c2];
        C[b].push_back(c);
        C[c].push_back(b);
    }
    ind2.clear();
    sort(all(ind),comp2);

    prev = Y[ind[0]];
    for(ll c1 = 0; c1 < n; c1++){
        a = ind[c1];
        if(Y[a] != prev){
            sort(all(ind2),comp1);
            for(ll c2 = 1; c2 < sz(ind2); c2++){
                b = ind2[c2-1];
                c = ind2[c2];
                C[b].push_back(c);
                C[c].push_back(b);
            }
            ind2.clear();
        }
        ind2.push_back(a);
        prev = Y[a];
    }

    sort(all(ind2),comp1);
    for(ll c2 = 1; c2 < sz(ind2); c2++){
        b = ind2[c2-1];
        c = ind2[c2];
        C[b].push_back(c);
        C[c].push_back(b);
    }

/*
    for(ll c1 = 0; c1 < n; c1++){
        cout << c1+1 << "  sz: " << sz(C[c1]) << "\n";
        for(ll c2 = 0; c2 < sz(C[c1]); c2++){
            cout << C[c1][c2]+1 << " ";
        }cout << "\n";
    }
*/
    ll ans = 1;
    for(ll c1 = 0; c1 < n; c1++){
        if(!mark[c1]){
            cyc = 0;
            nxy = 0;
            SX.clear();
            SY.clear();
            dfs(c1,-1);
            if(!cyc){
                ans *= TWO[nxy]-1;
                ans %= big;
            }
            else{
                ans *= TWO[nxy];
                ans %= big;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}