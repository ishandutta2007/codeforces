#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

struct R{   
    int i1;
    int j1;
    int i2;
    int j2;
};


vector<pii> IP[27];
vector<pii> JP[27];

int main(){
    fastIO;
    int test_cases;
    cin >> test_cases;
    int n, m;
    int li, lj, ri, rj;
    int mi, mj;
    int mx;
    vector<R> answ;
    char g;
    int id;
    bool ok;
    for(int t = 0 ; t < test_cases ; t ++ ){
        cin >> n >> m;
        mx = 0;
        answ.clear();
        for(int i = 0 ;i <= 26; i ++ )
            IP[i].clear(), JP[i].clear();
        for(int i = 0 ; i < n ; i ++ ){
            for(int j = 0 ; j < m ; j ++ ){
                cin >> g;
                if(g == '.'){
                    IP[0].push_back(mp(i,j));
                    JP[0].push_back(mp(j,i));
                }
                else{
                    IP[g - 'a' + 1].push_back(mp(i,j));
                    JP[g - 'a' + 1].push_back(mp(j,i));
                    mx = max(mx, g - 'a' + 1);
                }
                
            }
        }
        for(int i = 0 ; i <= 26; i ++ )
            sort(IP[i].begin(), IP[i].end());
        for(int j = 0 ; j <= 26; j ++ )
            sort(JP[j].begin(), JP[j].end());
        mi = IP[mx][0].fi;
        mj = IP[mx][0].se;
        answ.clear();
        ok = true;
        for(int i = 1; i <= mx; i ++ ){
            if(IP[i].empty()){
                answ.push_back({mi,mj,mi,mj});
                continue;
            }
            li = 124142;
            lj = 213124;
            ri = 0;
            rj = 0;
            for(auto p : IP[i]){
                li = min(li, p.fi),lj = min(lj, p.se), ri = max(ri, p.fi), rj = max(rj, p.se);
            }
            answ.push_back({li,lj,ri,rj});
            if(li != ri && lj != rj){
                ok = false;
            }
            else{
                if(li == ri){
                    for(int v = 0 ; v < i ; v ++ ){
                        id = lower_bound(IP[v].begin(), IP[v].end(),mp(li,lj)) - IP[v].begin();
                        if(id != IP[v].size() && IP[v][id].fi == li && IP[v][id].se <= rj){
                            ok = false;
                        }
                    }
                }
                else{
                    for(int v = 0 ; v < i; v ++ ){
                        id = lower_bound(JP[v].begin(), JP[v].end(),mp(lj,li)) - JP[v].begin();
                        if(id != JP[v].size() && JP[v][id].fi == lj && JP[v][id].se <= ri){
                            ok = false;
                        }
                    }
                }
            }
        }
        if(!ok)
            cout << "NO\n";
        else{
            cout << "YES\n";
            cout << mx << "\n";
            for(auto x : answ){
                cout << x.i1 + 1<< " " << x.j1 + 1 << " " << x.i2 + 1 << " " << x.j2 + 1 << "\n";
            }
        }
    }
    return 0;
}