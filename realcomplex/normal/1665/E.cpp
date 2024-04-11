#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 1;
const int T = (int)3e6 + 10;
int a[N];
int nex[T][2];
int id;
vector<int> ids[T];

int cnt(int id, int lf, int rf){
    int ra = lower_bound(ids[id].begin(), ids[id].end(), rf + 1) - ids[id].begin();
    int la = lower_bound(ids[id].begin(), ids[id].end(), lf) - ids[id].begin();
    return ra-la;
}

void solve(){
    for(int iq = 0; iq <= id; iq ++ ){
        nex[iq][0] = nex[iq][1] = 0;
        ids[iq].clear();
    }
    id = 0;
    int n;
    cin >> n;
    int b;
    int go;
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i];
        go = 0;
        for(int lg = 29; lg >= 0 ; lg -- ){
            if((a[i] & (1 << lg))){
                b = 1;
            }
            else{
                b = 0;
            }
            if(nex[go][b] == 0){
                id ++ ;
                nex[go][b] = id;
            }
            go = nex[go][b];
            ids[go].push_back(i);
        }
    }
    int q;
    cin >> q;
    int lef, rig;
    int res;
    int ii;
    int sum;
    int cc;
    for(int iq = 1; iq <= q; iq ++ ){
        cin >> lef >> rig;
        go = 0;
        res = 0;
        vector<pii> cur, nx;
        cur.push_back(mp(0, -1));
        for(int iter = 29 ; iter >= 0 ; iter -- ){
            cc = 0;
            for(auto x : cur){
                if(x.se == -1){
                    if(nex[x.fi][0] != 0){
                        cc += cnt(nex[x.fi][0], lef, rig);
                    }
                }
                else{
                    if((a[x.se] & (1 << iter)) == 0){
                        cc ++ ;
                    }
                }
                if(cc >= 2) break;
            }
            if(cc >= 2){
                for(auto x : cur){
                    if(x.se == -1){
                        if(nex[x.fi][0] != 0){
                            nx.push_back(mp(nex[x.fi][0], -1));
                        }
                    }
                    else{
                        if((a[x.se] & (1 << iter)) == 0){
                            nx.push_back(x);
                        }
                    }
                }
            }
            else{
                res |= (1 << iter);
                for(auto x : cur){
                    if(x.se != -1){
                        nx.push_back(x);
                    }
                    else{
                        if(nex[x.fi][0] != 0){
                            ii = lower_bound(ids[nex[x.fi][0]].begin(), ids[nex[x.fi][0]].end(), lef) - ids[nex[x.fi][0]].begin();
                            if(ii < ids[nex[x.fi][0]].size() && ids[nex[x.fi][0]][ii] <= rig){
                                nx.push_back(mp(-1, ids[nex[x.fi][0]][ii]));
                            }
                        }
                        if(nex[x.fi][1] != 0){
                            nx.push_back(mp(nex[x.fi][1], -1));
                        }
                    }
                }
            }

            swap(cur, nx);
            nx.clear();
        }
        cout << res << "\n";
    }
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}