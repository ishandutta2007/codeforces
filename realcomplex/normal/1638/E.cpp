#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1e6 + 10;

struct Node{
    ll val;
    ll lzy;
};

Node T[N * 4 + 512];

void push(int node, int cl, int cr){
    T[node].val += T[node].lzy;
    if(cl != cr){
        T[node * 2].lzy += T[node].lzy;
        T[node * 2 + 1].lzy += T[node].lzy;
    }
    T[node].lzy = 0;
}

void update(int node, int cl, int cr, int tl, int tr, ll v){
    push(node, cl, cr);
    if(cr < tl || cl > tr) return;
    if(cl >= tl && cr <= tr){
        T[node].lzy += v;
        push(node, cl, cr);
        return;
    }
    int mid = (cl + cr) / 2;
    update(node * 2, cl, mid, tl, tr, v);
    update(node * 2 + 1, mid + 1, cr, tl, tr, v);
}

ll get(int node, int cl, int cr, int id){
    push(node, cl, cr);
    if(cl == cr) return T[node].val;
    int mid = (cl + cr) / 2;
    if(mid >= id)
        return get(node * 2, cl, mid, id);
    else
        return get(node * 2 + 1, mid + 1, cr, id);
}

ll S[N];

struct color{
    int lef;
    int rig;
    int colr;
    bool operator< (color C) const {
        return lef < C.lef;
    }
};

set<color> segm;
int n;

void setcolor(int lef, int rig, int ii){
    auto it = segm.lower_bound({lef, rig, -1});
    if(it != segm.begin()){
        it -- ;
    }
    int cl, cr;
    int cc;
    while(it != segm.end()){
        cl = it->lef;
        cr = it->rig;
        cc = it->colr;
        if(cl > rig) break;
        auto nx = it;
        nx ++ ;
        if(cr >= lef){
            segm.erase(it);
            update(1, 1, n, max(lef, cl), min(rig, cr), S[cc]-S[ii]);
            if(cl <= lef - 1){
                segm.insert({cl, lef - 1, cc});
            }
            if(rig + 1 <= cr){
                segm.insert({rig + 1, cr, cc});
            }
        }
        it = nx;
    }
    segm.insert({lef, rig, ii});
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int q;
    cin >> n >> q;
    segm.insert({1, n, 1});
    string type;
    int id, x;
    int li, ri;
    for(int iq = 1; iq <= q; iq ++ ){
        cin >> type;
        if(type == "Color"){
            cin >> li >> ri >> x;
            setcolor(li, ri, x);
        }
        else if(type == "Add"){
            cin >> id >> x;
            S[id] += x;
        }
        else{
            cin >> id;
            auto it = segm.lower_bound({id + 1, -1, -1});
            it -- ;
            cout << get(1, 1, n, id) + S[it->colr] << "\n";
        }
    }
    return 0;
}