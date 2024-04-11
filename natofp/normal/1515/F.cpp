#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

const int nax = 3e5 + 5;
ll n,m,x;

ll a[nax];
ll val[nax];

set<pii> adj[nax];

int par[nax];
int sz[nax];

int f(int y){
    if(par[y] == y) return y;
    return par[y] = f(par[y]);
}

set<int> kto[nax];

int u(int a, int b){
    a = f(a);
    b = f(b);
    if(a == b) return -1;
    if(sz[a] > sz[b]) swap(a, b);
    val[b] += val[a];
    val[b] -= x;
    sz[b] += sz[a];
    par[a] = b;

    for(int x : kto[a]){
        kto[b].insert(x);
    }

    return b;
}

vector<int> ans;

void solve(){
    for(int i=0;i<nax;i++) par[i] = i;
    for(int i=0;i<nax;i++) sz[i] = 1;
    cin >> n >> m >> x;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) val[i] = a[i];
    for(int i=1;i<=m;i++){
        int y, z; cin >> y >> z;
        adj[y].insert(mp(z, i));
        adj[z].insert(mp(y, i));
    }
    ll sum = 0;
    for(int i=1;i<=n;i++){
        sum += a[i];
    }
    if(sum < x * (n - 1)){
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";
    set<pair<ll, int> > xd;
    for(int i=1;i<=n;i++){
        xd.insert(mp(val[i], i));
    }
    for(int i=1;i<=n;i++) kto[i].insert(i);
    set<pll> kurwa;
    for(int i=1;i<=n;i++) kurwa.insert(mp(val[i], i));

    int done = 0;
    while(done < n - 1){
        auto war = ((*kurwa.rbegin()));
        if(war.st < x) break;
        int COOM = war.nd;

        while(kto[COOM].size()){
            int one = (*kto[COOM].begin());
            int comp1 = f(one);
            bool siema = false;
            while(adj[one].size()){
                //cout << "A" << endl;
                pii to = (*adj[one].begin());
                int two = to.st;
                int comp2 = f(two);
                if(comp1 == comp2){
                    int w = to.nd;
                    adj[one].erase(to);
                    adj[two].erase(mp(one, w));
                    continue;
                }
                //cout << "B" << endl;
                // else we can merge :D
                xd.erase(mp(val[comp1], one));
                xd.erase(mp(val[comp2], two));
                kurwa.erase(war);
                kurwa.erase(mp(val[comp2], comp2));
                int ac = u(one, two);

                xd.insert(mp(val[ac], one));
                xd.insert(mp(val[ac], two));
                kurwa.insert(mp(val[ac], ac));
                done++;
                ans.pb(to.nd);
                //cout << "AC "<< one << " "<<two<<endl;
                siema = true;
                break;
            }
            if(siema) break;
            kto[COOM].erase(one);
        }




    }
    // finish so connect componenets BUT ALWAYS COST OF ONE IS GOING DOWN

    // we can do it greedily -> if someone cant connect to lipa :)

    for(int i=1;i<=n;i++){
        while(adj[i].size()){
            pii to = ((*adj[i].begin()));
            int one = i;
            int two = to.st;
            int comp1 = f(one);
            int comp2 = f(two);
            if(comp1 == comp2){
                adj[i].erase(to);
                adj[to.st].erase(mp(i, to.nd));
                continue;
            }
            if(val[comp1] + val[comp2] < x){
                adj[i].erase(to);
                adj[to.st].erase(mp(i, to.nd));
                continue;
            }
            else{
                ans.pb(to.nd);
                u(one, two);
            }
        }
    }



    for(int x : ans) cout << x << "\n";
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}