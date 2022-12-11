#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
struct S{
    int y;
    int xl;
    int xr;
    bool operator< (const S T) const{
        return y < T.y;
    }
};

const int N = (int)1e4 + 3;

int tree[N * 2 + 51];

void update(int id, int x){
    id += N;
    while(id > 0){
        tree[id] += x;
        id /= 2;
    }
}

int query(int l, int r){   
    l += N;
    r += N;
    int res = 0;
    while(l <= r){
        if(l % 2 == 1) res += tree[l ++ ];
        if(r % 2 == 0) res += tree[r -- ];
        l /= 2;
        r /= 2;
    }
    return res;
}


struct H{
    int yl;
    int yr;
    int xl;
};

int main(){
    fastIO;
    int n;
    cin >> n;
    int x1, y1, x2, y2;
    vector<S> good;
    vector<H> ff;
    for(int i = 0 ;i < n; i ++ ){
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 5000;
        x2 += 5000;
        if(y1 == y2){
            if(x1 > x2)
                swap(x1, x2);
            good.push_back({y1, x1, x2});
        }
        else{
            if(y1 > y2)
                swap(y1, y2);
            ff.push_back({y1, y2, x1});
        }
    }
    sort(good.begin(), good.end());
    ll ret = 0;
    ll k;
    int v;
    int cl, cr;
    for(int i = 0 ; i < good.size(); i ++ ){
        vector<H> iy;
        for(int j = 0 ; j < ff.size(); j ++ ){
            if(ff[j].yl <= good[i].y)iy.push_back(ff[j]);
        }
        
        vector<pii> cors;
        for(auto p : iy){
            cors.push_back(mp(p.yr, p.xl));
            update(p.xl, +1);
        }
        sort(cors.begin(), cors.end());
        v = 0;
        for(int j = i + 1; j < good.size(); j ++ ){
            while(v < cors.size()){
                if(cors[v].fi < good[j].y){
                    update(cors[v].se, -1);
                    v ++ ;
                }
                else{
                    break;
                }
            }
            cl = max(good[i].xl, good[j].xl);
            cr = min(good[i].xr, good[j].xr);
            if(cl <= cr){
                k = query(cl, cr);
                ret += (k * (k - 1)) / 2;
            }
        }
        for(int j = 0 ; j < 2 * N + 5; j ++ )
            tree[j] = 0;
    }
    cout << ret << "\n";
    return 0;
}