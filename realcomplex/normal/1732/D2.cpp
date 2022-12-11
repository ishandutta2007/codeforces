#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
char typ[N];
ll x[N];

struct seg_tree{
    vector<ll> cnt;
    void init(int m){
        cnt.resize(4 * m + 32);
    }
    void flip(int node, int xi, int yi, int pos){
        if(xi == yi){
            cnt[node]^=1;
            return;
        }
        int mid = (xi + yi) / 2;
        if(mid >= pos){
            flip(node * 2, xi, mid, pos);
        }
        else{
            flip(node * 2 + 1, mid + 1, yi, pos);
        }
        cnt[node] = cnt[node * 2] + cnt[node * 2 + 1];
    }
    int zero(int node, int xi, int yi){
        if(xi == yi) return xi;
        int mid = (xi + yi) / 2;
        if(cnt[node * 2] < mid - xi + 1){
            return zero(node * 2, xi, mid);
        }
        else{
            return zero(node * 2 + 1, mid + 1, yi);
        }
    }
};

vector<pii> id[N];
ll F[N];
int sz[N];
seg_tree C[N];


int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int q;
    cin >> q;
    vector<ll> fin;
    for(int i = 1; i <= q; i ++ ){
        cin >> typ[i] >> x[i];
        if(typ[i] == '+') fin.push_back(x[i]);
    }
    sort(fin.begin(), fin.end());
    fin.resize(unique(fin.begin(), fin.end()) - fin.begin());
    int m;
    ll D;
    int idx;
    int cnt;
    for(int i = 0 ; i < fin.size(); i ++){
        D = fin[i];
        F[i] = fin[i];
        while(1){
            idx = lower_bound(fin.begin(), fin.end(), D) - fin.begin();
            if(idx == fin.size() || fin[idx] != D) break;
            id[idx].push_back(mp(i, sz[i]));
            sz[i] ++ ;
            D += fin[i];
        }
        sz[i] ++ ;
        C[i].init(sz[i]);
    }
    int zz;
    for(int i = 1; i <= q; i ++ ){
        if(typ[i] == '+' || typ[i] == '-'){
            idx = lower_bound(fin.begin(), fin.end(), x[i]) - fin.begin();
            for(auto p : id[idx]){
                C[p.fi].flip(1, 0, sz[p.fi] - 1, p.se);
            }
        }
        else{
            idx = lower_bound(fin.begin(), fin.end(), x[i]) - fin.begin();
            if(idx >= fin.size() || fin[idx] != x[i]){
                cout << x[i] << "\n";
            }
            else{
                zz = C[idx].zero(1, 0, sz[idx] - 1);
                cout << (zz + 1) * 1ll * x[i] << "\n";
            }
        }
    }
    return 0;
}