#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 100;

set<int> L[N], R[N];

int bad;
int sz;

struct segtree{
    bool f;
    int val[N * 2 + 512];
    void init(){
        for(int i = 0 ; i < N * 2 + 512; i ++ ){
            if(!f){
                val[i] = (int)1e9;
            }
            else{
                val[i] = -1;
            }
        }
    }
    void upd(int idx){
        int nw;
        if(!f){
            nw = (int)1e9;
            if(!L[idx].empty()) nw = *L[idx].begin();
        }
        else{
            nw = -1;
            if(!R[idx].empty()){
                auto it = R[idx].end();
                -- it;
                nw = *it;
            }
        }
        idx += sz;
        val[idx] = nw;
        idx /= 2;
        while(idx > 0){
            if(!f) val[idx] = min(val[idx*2],val[idx*2+1]);
            else val[idx] = max(val[idx*2],val[idx*2+1]);
            idx /= 2;
        }
    }
    int get(int l, int r){
        l += sz;
        r += sz;
        int sol;
        if(!f) sol = (int)1e9;
        else sol = -1;
        while(l <= r){
            if(l % 2 == 1){
                if(!f) sol = min(sol, val[l]);
                else sol = max(sol, val[l]);
                l ++ ;
            }
            if(r % 2 == 0){
                if(!f) sol = min(sol, val[r]);
                else sol = max(sol, val[r]);
                r -- ;
            }
            l /= 2;
            r /= 2;
        }
        return sol;
    }
};

segtree lefc, rigc;

int main(){
    fastIO;
    lefc.f = false;
    rigc.f = true;
    lefc.init();
    rigc.init();
    int n, m, qr;
    cin >> n >> m >> qr;
    sz = n + 1;
    int x, y;
    int cor;
    int p, q;
    for(int t = 1; t <= qr; t ++ ){
        cin >> x >> y;
        x --;
        y --;
        p = x/2;
        q = y/2;
        if(x % 2 == 0){
            if(L[p].count(q)){
                if(rigc.get(p, n-1) >= q) bad -- ;
                L[p].erase(q);
            }
            else{
                if(rigc.get(p, n-1) >= q) bad ++ ;
                L[p].insert(q);
            }
            lefc.upd(p);
        }
        else{
            if(R[p].count(q)){
                if(lefc.get(0, p) <= q) bad -- ;
                R[p].erase(q);
            }
            else{
                if(lefc.get(0, p) <= q) bad ++ ;
                R[p].insert(q);
            }
            rigc.upd(p);
        }
        if(bad > 0){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
    return 0;
}