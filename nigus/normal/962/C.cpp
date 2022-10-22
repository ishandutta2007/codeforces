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
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
const ll mod = 998244353;
ll n,k,m,d;


ll ten[11] = {0};

unordered_set<ll> S;

ll tlog(ll i){
    ll i2 = i;
    ll ans = 0;
    while(i2 > 0){
        ans++;
        i2/=10;
    }
    return ans;
}

ll del(ll i, ll j){
    ll i2 = i%ten[j];
    ll i3 = i/ten[j+1];
    ll res = i3*ten[j]+i2;
    return res;
}

unordered_map<ll,ll> M;

ll bfs(ll i){
    queue<ll> Q;
    Q.push(i);
    M[i] = 0;
    while(!Q.empty()){
        ll a = Q.front();
        //cout << a <<"\n";
        Q.pop();
        if(S.find(a) != S.end())return M[a];
        ll tl = tlog(a);
        if(tl > 1){
            for(ll c1 = 0; c1 < tl; c1++){
                ll b = del(a,c1);
                if(b >= ten[tl-2]){
                    if(M.find(b) == M.end()){
                        M[b] = M[a]+1;
                        Q.push(b);
                    }
                }
            }
        }
    }

    return -1;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    ll t = 1;
    for(ll c1 = 0; c1 < 11; c1++){
        ten[c1] = t;
        t *= 10;
    }

    for(ll c1 = 1; c1 < 100000; c1++){
        S.insert(c1*c1);
    }

    cin >> n;
    cout << bfs(n) << "\n";


    return 0;
}