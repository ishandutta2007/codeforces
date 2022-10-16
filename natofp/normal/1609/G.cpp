#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long
    
using namespace std;
    
const int roz = (1 << 18);
 
bool marked[roz];
ll mi[roz];
ll sum[roz];
int sz[roz];
ll lazy[roz]; // add
 
void combine(int v){
    sum[v] = sum[v * 2] + sum[v * 2 + 1];
    mi[v] = min(mi[v * 2], mi[v * 2 + 1]);
}
 
void push(int v){
    if(!marked[v]) return;
    marked[v] = false;
    for(int i=v*2;i<=v*2+1;i++){
        marked[i] = true;
        lazy[i] += lazy[v];
        sum[i] += lazy[v] * sz[i];
        mi[i] += lazy[v];
    }
    lazy[v] = 0;
}
 
void add(int lo, int hi, int u, int a, int b, ll val){
    if(lo == a && b == hi){
        lazy[u] += val;
        sum[u] += val * (hi - lo);
        mi[u] += val;
        marked[u] = true;
        return;
    }
    if(b <= a) return;
    push(u);
    int mid = (lo + hi) / 2;
    add(lo, mid, u * 2, a, min(b,mid), val);
    add(mid, hi, u * 2 + 1, max(a,mid), b, val);
    combine(u);
}
 
pair<ll, int> ask(ll val){
    // sum after, cnt after
    ll s = 0;
    int cnt = 0;
    int u = 1;
    while(u < roz / 2){
        if(marked[u]){
            push(u);
            
        }
        if(mi[u * 2 + 1] <= val){
            u = u * 2 + 1;
        }
        else{
            s += sum[u * 2 + 1];
            cnt += sz[u * 2 + 1];
            u *= 2;
        }
    }
    if(val < mi[u]){
        cnt += 1;
        s += sum[u];
    }
    return mp(s, cnt);
}
 
ll a[105];
ll b[1000005];
int n, m, q; 
 
ll aDif[105];
ll bDif[1000005];
 
void ini(int m){
    for(int i=0;i<roz/2;i++){
        sz[i + roz / 2] = 1;
        if(i > m - 1) mi[i + roz / 2] = (ll)1e18;
    }
    for(int i=roz/2-1;i>=1;i--){
        sz[i] = sz[i * 2] + sz[i * 2 + 1];
        mi[i] = min(mi[i * 2], mi[i * 2 + 1]);
    }
}
 
ll ary(ll lo, ll hi){
    ll cnt = hi - lo + 1;
    return (lo + hi) * cnt / 2;
}
 
void solve(){
    cin >> n >> m >> q;
    ini(m - 1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++) cin >> b[i];
    ll startField = a[1] + b[1];
    ll initBonus = 0;
    for(int i=1;i<n;i++) aDif[i] = a[i + 1] - a[i];
    for(int i=1;i<m;i++) bDif[i] = b[i + 1] - b[i];
    for(int i=1;i<m;i++){
        initBonus += bDif[i] * (n + m - 1 - i);
    }
    for(int pos=1;pos<m;pos++){
        add(0, roz/2, 1, pos - 1, pos, bDif[pos]);
    }
    
    int dead = roz / 2 - (m - 1);
    while(q--){
        int tp; cin >> tp;
        int k, d; cin >> k >> d;
        if(tp == 1){
            if(k == n){
                startField += d;
                k -= 1;
            }
            int id = n - 1;
            while(k){
                aDif[id] += d;
                id -= 1;
                k -= 1;
            }
        }
        else{
            if(k == m){
                startField += d;
                k -= 1;
            }
            // n + m 
            int loID = m - 1 - (k - 1);
            int hiID = m - 1;
            loID = n + m - 1 - loID;
            hiID = n + m - 1 - hiID;
            swap(loID, hiID);
            ll s = ary(loID, hiID);
            s *= d;
            initBonus += s;
            add(0, roz / 2, 1, m - k - 1, m - 1, d);
        }
        ll answer = startField * (n + m - 1);
        answer += initBonus;
        for(int i=1;i<n;i++){
            ll val = aDif[i];
            auto res = ask(val);
            ll sumDecreased = res.st;
            answer -= sumDecreased;
            int cnt = res.nd;
            cnt -= dead;
            int beforeOurType = i - 1;
            int beforeEnemyType = (m - 1 - cnt);
            answer += val * (n + m - 2 - beforeOurType - beforeEnemyType);
        }
 
        cout << answer << "\n";
    }
    
}
    
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int tt = 1;
    // cin >> tt;
    while(tt--) solve();
    
    return 0;
}