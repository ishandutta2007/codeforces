#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 9;

ll res[N];

void update(int cl, int cr, ll w){
    if(cl > cr)
        return;
    res[cl] += w;
    res[cr + 1] -= w;
}

set<pii> segm;

void add(int l, int r, ll w){
    auto it = segm.lower_bound(mp(l,-1));
    if(it != segm.begin()){
        -- it;
    }
    int tl = l, tr = r;
    int cl, cr;
    int las = l;
    while(1){
        if(it == segm.end()) break;
        if(it->fi > r){
            break;
        }
        if(it->se < l){
            ++it;
            continue;
        }
        cl = it->fi;
        cr = it->se;
        update(las, cl - 1, w);
        las = cr + 1;
        
        tl = min(tl, cl);
        tr = max(tr, cr);
        
        auto nx = it;
        ++nx;
        segm.erase(it);
        it=nx;
    }
    if(las <= r)
        update(las, r, w);
        
        
    segm.insert(mp(tl, tr));
}

int main(){
    fastIO;
    int n, w;
    cin >> n >> w;
    int k;
    int d;
    int l, r;
    bool has;
    for(int i = 1; i <= n; i ++ ){
        cin >> k;
        d = w - k;
        vector<int> y(k);
        for(int j = 0 ; j < k ; j ++ ){
            cin >> y[j];
        }
        vector<pii> cc;
        for(int j = 0 ; j < k ; j ++ ){
            cc.push_back(mp(y[j], j));
        }
        sort(cc.begin(), cc.end());
        segm.clear();
        has = false;
        for(int j = k-1 ; j >= 0 ; j -- ){
            if(cc[j].fi < 0 && !has && d > 0){
                add(0, d - 1, 0);
                add(w - d, w - 1, 0);
                has =  true;
            }
            add(cc[j].se, cc[j].se + d, cc[j].fi);
        }
    }
    for(int i = 0 ; i < w; i ++ ){
        if(i)
            res[i] += res[i-1];
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}