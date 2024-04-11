#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 100010;

set<pii> segm[N * 4 + 512];

vector<int> add[N];
int lf[N], rf[N];

void adds(int idi, pii X){
    auto it = segm[idi].lower_bound(mp(X.fi, -1));
    if(it != segm[idi].end() && it->se <= X.se){
        return;
    }
    while(1){
        it = segm[idi].lower_bound(mp(X.fi + 1, -1));
        if(it == segm[idi].begin()) break;
        it -- ;
        if(it->fi <= X.fi && it->se >= X.se) {
            it = segm[idi].erase(it);
        }
        else{
            break;
        }
    }
    segm[idi].insert(X);
}

void ins(int node, int cl, int cr, int pos, pii yy){
    adds(node, yy);
    if(cl == cr) return ;
    int mid = (cl + cr) / 2;
    if(mid >= pos)
        ins(node * 2, cl, mid, pos, yy);
    else
        ins(node * 2 + 1, mid + 1, cr, pos, yy);
}

int get(int node, int cl, int cr, int tl, int tr){
    auto it = segm[node].lower_bound(mp(tl, -1));
    if(it == segm[node].end() || it->se > tr) return -1;
    if(cl == cr)
        return cl;
    int mid = (cl + cr) / 2;
    int hf = get(node * 2, cl, mid, tl, tr);
    if(hf != -1) return hf;
    return get(node * 2 + 1, mid + 1, cr, tl, tr);
}

int n, m;
int solve(int li, int ri){
    if(li > ri) return 0;
    int id = get(1, 1, m, li, ri);
    if(id == -1) return 0;
    return rf[id] - lf[id] + 1 + solve(li, lf[id] - 1) + solve(rf[id] + 1, ri);
}

int res[N];

int main(){
    fastIO;
    cin >> n >> m;
    for(int iq = 1; iq <= m ; iq ++ ){
        cin >> lf[iq] >> rf[iq];
        add[rf[iq] - lf[iq] + 1].push_back(iq);
    }
    for(int chk = n; chk >= 1; chk -- ){
        for(auto x : add[chk]){
            ins(1, 1, m, x, mp(lf[x], rf[x]));
        }
        res[chk] = solve(1, n);
    }
    for(int i = 1; i <= n; i ++ ){
        cout << res[i] << "\n";
    }
    return 0;
}