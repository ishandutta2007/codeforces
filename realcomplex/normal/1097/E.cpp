#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
bool ban[N];

void solve(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0 ; i < n; i ++ ){
        cin >> p[i];
        ban[p[i]]=false;
    }
    vector<vector<int>> res;
    int k;
    int id;
    int mm;
    int y;
    int g;
    while(!p.empty()){
        k = 0;
        while((k + 1) * 1ll * (k + 2) / 2ll <= p.size()) k ++ ;
        vector<pii> seq;
        vector<int> las;
        vector<int> f;
        mm = 0;
        for(int i = 0 ; i < p.size(); i ++ ){
            id = lower_bound(seq.begin(), seq.end(), mp(p[i], -1)) - seq.begin();
            if(id == seq.size()){
                seq.push_back(mp(p[i], i));
            }
            else{
                seq[id] = mp(p[i], i);
            }
            f.push_back(id + 1);
            if(f[i] > f[mm]){
                mm = i;
            }
            if(id == 0)
                las.push_back(i);
            else
                las.push_back(seq[id - 1].se);
        }
        if(f[mm] > k){
            vector<int> qq;
            while(1){
                qq.push_back(p[mm]);
                ban[p[mm]]=true;
                if(las[mm] == mm) break;
                mm=las[mm];
            }
            reverse(qq.begin(), qq.end());
            res.push_back(qq);
            vector<int> nw;
            for(auto x : p){
                if(!ban[x]) nw.push_back(x);
            }
            p = nw;
        }
        else{
            y = res.size();
            for(int i = 0 ; i < p.size(); i ++ ){
                if(y + f[i] - 1 < res.size()){
                    res[y + f[i] - 1].push_back(p[i]);
                }
                else{
                    res.push_back({p[i]});
                }
            }
            p.clear();
        }
    }
    cout << res.size() << "\n";
    for(auto i : res){
        cout << i.size() << " ";
        for(auto j : i){
            cout << j << " ";
        }
        cout << "\n";
    }

}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}