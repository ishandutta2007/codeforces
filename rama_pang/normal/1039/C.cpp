#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
const ll MOD=1e9 +7;
ll pow2[500015],N,M,K;
class DisjointSet{
private:
    ll num, ori;
    vi p, res;
public:
    DisjointSet(ll n){
        p.resize(N+5);
        iota(p.begin(), p.end(), 0ll);
        num=n;
        ori=n;
    }
    ll par (ll n){
        return (p[n]==n)? n: p[n]=par(p[n]);
    }
    void join (ll a, ll b){
        ll p1=par(a); ll p2=par(b);
        if (p1!=p2){
            res.pb(p1);
            p[p1]=p2;
            num--;
        }
    }
    void reset (){
        for (ll i=0; i<res.size(); i++){
            p[res[i]]=res[i];
        }
        num=ori;
        res.clear();
    }
    ll size(){
        return num;
    }
};
vector<iii> G;
vi ver;
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    pow2[0]=1;
    for (ll i=1; i<=500005; i++){
        pow2[i]=pow2[i-1]*2;
        pow2[i]%=MOD;
    }
    cin >> N >> M >> K;
    ll kombin= 1ll<<K;
    ver.resize(N+3);
    for (ll i=1; i<=N; i++){
        cin >> ver[i];
    }
    for (ll i=1; i<=M; i++){
        ll u,v; cin >> u >> v;
        G.pb({ver[u]^ver[v], {u,v}});
    }
    sort(G.begin(), G.end());
    DisjointSet dsu(N);
    ll ans=0;
    for (ll i=0; i<G.size(); i++){
        kombin--;
        ll ori=G[i].fi;
        dsu.join(G[i].se.fi, G[i].se.se);
        while (G[i+1].fi==ori){
            i++;
            dsu.join(G[i].se.fi, G[i].se.se);
        }
        ans+= pow2[dsu.size()]%MOD;
        ans%=MOD;
        dsu.reset();
    }
    ans+= (kombin%MOD)*(pow2[N]%MOD)%MOD;
    ans%=MOD;
    cout << ans << endl;
}