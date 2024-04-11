#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MOD = (int)1e9 + 7;
const int N = 2005;

int x[N], y[N], c[N];
int f[N];
int cu[N];
int cnt[N];
int q[N];
int has;
multiset<int> cxx[N];
int l;

struct Node{
    int sum;
    int low;
    int setv;
    int csum;
};

Node T[N * 4 + 512];

void push(int node, int cl, int cr){
    if(T[node].setv == -1)
        return;
    T[node].low = T[node].setv;
    T[node].sum = (T[node].csum * 1ll * T[node].low) % MOD;
    if(cl != cr){
        T[node * 2].setv = T[node].setv;
        T[node * 2 + 1].setv = T[node].setv;
    }
    T[node].setv = -1;
}

int get(int node, int cl, int cr, int v){
    if(T[node].low > v) return 0;
    if(cl == cr)
        return cl;
    int mid = (cl + cr) / 2;
    push(node * 2, cl, mid);
    push(node * 2 + 1, mid + 1, cr);
    if(T[node * 2 + 1].low <= v)
        return get(node * 2 + 1, mid + 1, cr, v);
    else
        return get(node * 2, cl, mid, v);
}

void update(int node, int cl, int cr, int tl, int tr, int v){
    push(node, cl, cr);
    if(cr < tl || cl > tr)
        return;
    if(cl >= tl && cr <= tr){
        T[node].setv = v;
        push(node, cl, cr);
        return;
    }
    int mid = (cl + cr) / 2;
    update(node * 2, cl, mid, tl, tr, v);
    update(node * 2 + 1, mid + 1, cr, tl, tr, v);
    T[node].sum = (T[node * 2].sum + T[node * 2 + 1].sum) % MOD;
    T[node].low = T[node * 2].low;
}


void innit(int node, int cl, int cr){
    if(cl == cr){
        T[node] = {(f[cl] * 1ll * cu[cl]) % MOD, f[cl], -1, cu[cl]};
        return;
    }
    int mid = (cl + cr) / 2;
    innit(node * 2, cl, mid);
    innit(node * 2 + 1, mid + 1, cr);
    T[node].low = T[node*2].low;
    T[node].sum = (T[node * 2].sum + T[node * 2 + 1].sum) % MOD;
    T[node].setv = -1;
    T[node].csum = (T[node * 2].csum + T[node * 2 + 1].csum) % MOD;
}

int main(){
    fastIO;
    int n, k;
    cin >> n >> k >> l;
    vector<int> cy = {-1, l}, cx = {-1,l};
    for(int i = 1; i <= n; i ++ ){
        cin >> x[i] >> y[i] >> c[i];
        cy.push_back(y[i]);
        cx.push_back(x[i]);
    }
    sort(cx.begin(), cx.end());
    sort(cy.begin(), cy.end());
    cx.resize(unique(cx.begin(), cx.end()) - cx.begin());
    cy.resize(unique(cy.begin(), cy.end()) - cy.begin());
    for(int i = 1; i <= n; i ++ ){
        x[i] = lower_bound(cx.begin(), cx.end(), x[i]) - cx.begin();
        y[i] = lower_bound(cy.begin(), cy.end(), y[i]) - cy.begin();
    }
    int h = cy.size();
    int w = cx.size();
    vector<pii> yh;
    for(int i = 1; i <= n; i ++ ){
        yh.push_back(mp(y[i], i));
    }
    sort(yh.begin(), yh.end());
    reverse(yh.begin(), yh.end());
    int r;
    int del;
    int idx;
    int lef, rig;
    int sol;
    int up, down;
    int srr;
    int outp = 0;
    for(int cut = 1; cut + 1 < h; cut ++ ){
        while(!yh.empty() && yh.back().fi < cut)
            yh.pop_back();
        vector<pii> xx;
        for(int i = 1; i <= k ; i ++ )
            cnt[i] = 0;
        for(auto p : yh){
            xx.push_back(mp(x[p.se], p.se));
        }
        for(int i = 0 ; i < w; i ++ ){
            f[i]=l;
        }
        sort(xx.begin(), xx.end());
        has = 0;
        int p = xx.size() - 1;
        int q = xx.size() - 1;
        for(int i = w - 2; i >= 1 ; i -- ){
            while(p >= 0 && xx[p].fi >= i){
                if(cnt[c[xx[p].se]] == 0) has ++ ;
                cnt[c[xx[p].se]] ++ ;
                p -- ;
            }
            if(has == k){
                while(cnt[c[xx[q].se]] > 1){
                    cnt[c[xx[q].se]] -- ;
                    q -- ;
                }
                f[i]=cx[xx[q].fi];
            }
            else{
                f[i]=l;
            }
        }
        for(int i = 1; i <= w - 2; i ++ ){
            cu[i] = cx[i] - cx[i - 1];
        }
        del = 0;
        for(int i = 1; i <= k ; i ++ ){
            cxx[i].clear();
            cxx[i].insert(0);
            cxx[i].insert(w-1);
        }
        for(auto p : yh){
            cxx[c[p.se]].insert(x[p.se]);
        }
        innit(1, 1, w-2);
        for(int ycut = h-2; ycut >= cut ; ycut -- ){
            vector<int> ids;
            while(yh[del].fi > ycut){
                idx = yh[del].se;
                ids.push_back(idx);
                cxx[c[idx]].erase(cxx[c[idx]].find(x[idx]));
                del ++ ;
            }
            for(auto q : ids){
                auto it = cxx[c[q]].lower_bound(x[q]);
                rig = *it;
                it = cxx[c[q]].lower_bound(x[q]+1);
                it -- ;
                lef = (*it);
                for(int j = lef + 1; j <= x[q]; j ++ ){
                    f[j]=max(f[j],cx[rig]);
                }
                idx = get(1, 1, w - 2, cx[rig]);
                idx = min(idx, x[q]);
                update(1, 1, w-2, lef+1, idx, cx[rig]);

            }
            up = cy[cut]-cy[cut-1];
            down = cy[ycut+1]-cy[ycut];
            srr = 0;

            for(int j = 1; j <= w-2; j ++ ){
                srr = (srr + cu[j] * 1ll * (l - f[j]) % MOD) % MOD;
            }

            srr = (T[1].csum * 1ll * l) % MOD;
            srr = (srr - T[1].sum + MOD) % MOD;
            srr = (srr * 1ll * up) % MOD;
            srr = (srr * 1ll * down) % MOD;
            outp = (outp + srr) % MOD;
        }
    }
    cout << outp << "\n";
    return 0;
}