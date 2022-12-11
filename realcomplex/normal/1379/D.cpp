#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<pii> sweep;

int best = (int)1e9;
vector<int> soln;
int opt = 0;
int q;

void go(bool mode){
    set<int> active;
    int sum = 0;
    for(int i = 0 ; i < sweep.size(); i ++ ){
        if(sweep[i].se > 0) {
            active.insert(sweep[i].se);
            sum ++ ;
        }
        else if(sweep[i].se < 0){
            active.erase(-sweep[i].se);
            sum -- ;
        }
        if(sweep[i].fi < q && sweep[i].fi != sweep[i + 1].fi){
            if(mode == false){
                if(sum < best){
                    best = sum;
                }
            }
            else{
                if(sum == best){
                    opt = sweep[i].fi;
                    for(auto x : active)
                        soln.push_back(x);
                    return;
                }
            }
        }
    }
}

int main(){
    fastIO;
    int n, h, m, k;
    cin >> n >> h >> m >> k;
    if(k == 1){
        cout << "0 0\n";
        return 0;
    }
    int mn;
    q = m / 2;
    int lef, rig;
    for(int i = 1 ; i <= n; i ++ ){
        cin >> h >> mn;
        mn %= q;
        lef = (mn + 1);
        rig = (mn + k - 1);
        lef %= q;
        rig %= q;
        if(lef <= rig){
            sweep.push_back(mp(lef, +i));
            sweep.push_back(mp(rig+1, -i));
        }
        else{
            sweep.push_back(mp(0, +i));
            sweep.push_back(mp(rig+1, -i));
            sweep.push_back(mp(lef, +i));
            sweep.push_back(mp(q, -i));
        }
    }
    sweep.push_back(mp(0, 0));
    sweep.push_back(mp(q , 0));
    sort(sweep.begin(), sweep.end());
    go(false);
    go(true);
    cout << soln.size() << " " << opt << "\n";
    for(auto q : soln)
        cout << q << " ";
    return 0;
}