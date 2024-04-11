#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

const int nax = 18;
int dp[1 << nax];
int n, m;
vector<pii> adj[nax];

bool ok_mask_upper[1 << nax]; // can we go up with submask
int mask_outside_cost[1 << nax]; // cost of increasing submask by 1
bool is_pair_in_mask[1 << nax]; // can we leave this submask in the SAME level?
int just_took[1 << nax];

vector<pii> edges;
int cost[nax * nax];

int res[nax + 1];

void solve(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        x--; y--;
        int w; cin >> w;
        adj[x].pb(mp(y, w));
        adj[y].pb(mp(x, w));
        edges.pb(mp(x, y));
        cost[i] = w;
    }

    for(int i=0;i<(1<<n);i++){
        // ok_mask_upper -> does it violate any restrictions immiedietly?
        ok_mask_upper[i] = true;
        for(pii edge : edges){
            if((i & (1 << edge.nd)) && (!(i & (1 << edge.st)))) ok_mask_upper[i] = false;
        }
        is_pair_in_mask[i] = false;
        for(pii edge : edges){
            if(i & (1 << edge.st) && (i & (1 << edge.nd))) is_pair_in_mask[i] = true;
        }
        mask_outside_cost[i] = 0;
        int cnt = -1;
        for(pii edge : edges){
            cnt++;
            if((i & (1 << edge.st)) && (!(i & (1 << edge.nd)))) mask_outside_cost[i] += cost[cnt];
        }
    }


    for(int i=0;i<(1<<n);i++) dp[i] = 1e9;
    dp[0] = 0;
    // update forward : )
    int ful = (1 << n) - 1;

    for(int i=0;i<(1<<n);i++){
        int submask = (ful ^ i);
        int increase = ((submask - 1) & submask);
        for(increase; increase; increase = ((increase - 1) & submask)){
            int left = (submask ^ increase);
            if(is_pair_in_mask[left]) continue;
            if(!ok_mask_upper[increase]) continue;
            int to = (i ^ left);
            int money = mask_outside_cost[increase];
            if(dp[i] + money < dp[to]){
                dp[to] = dp[i] + money;
                just_took[to] = left;
            }
        }
    }
    int anss = 1e9;
    int id = -1;
    for(int i=0;i<(1<<n);i++){
        int dop = (ful ^ i);
        if(is_pair_in_mask[dop] == false){
            if(dp[i] < anss){
                anss = dp[i];
                id = i;
            }
        }
    }
    vector<vector<int> > ans;
    int cur = ful;
    just_took[ful] = (ful ^ id);
    while(cur){
        int akt = just_took[cur];
        vector<int> guys;
        for(int j=0;j<n;j++){
            if(akt & (1 << j)) guys.pb(j);
        }
        ans.pb(guys);
        cur ^= akt;
    }

    reverse(ans.begin(), ans.end());
    int done = 0;
    for(auto wek : ans){
        done++;
        for(int idx : wek){
            res[idx + 1] = done;
        }
    }
    for(int i=1;i<=n;i++) cout << res[i] << " ";
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();

    return 0;
}