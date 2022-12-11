#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 100;
const int SZ = (int)1e7 + 10;

struct Node{
    ll full;
    ll cur;
    int lef_node;
    int rig_node;
};

Node T[SZ];

int id;

ll R[N], C[N];
ll V[N];


int build(int cl, int cr){
    id ++ ;
    int node = id;
    T[node].full = 0;
    if(cl == cr){
        T[node].cur = R[cl];
        T[node].lef_node = T[node].rig_node = -1;
        return node;
    }
    int mid = (cl + cr) / 2;
    int X = build(cl, mid);
    int Y = build(mid + 1, cr);
    T[node].lef_node = X;
    T[node].rig_node = Y;
    T[node].cur = T[X].cur + T[Y].cur;
    return node;
}

void print_tree(int node, int cl, int cr){
    cout << T[node].cur << " " << T[node].full << "| " << cl << " " << cr << "\n";
    if(cl == cr){
        return;
    }
    int mid = (cl + cr) / 2;
    print_tree(T[node].lef_node, cl, mid);
    print_tree(T[node].rig_node, mid + 1, cr);

}

int match(int fir){
    id ++ ;
    T[id] = T[fir];
    return id;
}

int enable(int node, int cl, int cr, int pos){
    node = match(node);
    T[node].cur -= R[pos];
    T[node].full += C[pos];
    if(cl == cr){
        return node;
    }
    int mid = (cl + cr) / 2;
    if(mid >= pos){
        int X = enable(T[node].lef_node, cl, mid, pos);
        T[node].lef_node = X;
    }
    else{
        int X = enable(T[node].rig_node, mid + 1, cr, pos);
        T[node].rig_node = X;
    }
    return node;
}

pll get(int node, int cl, int cr, int tl, int tr){
    if(cr < tl || cl > tr) return mp(0ll, 0ll);
    if(cl >= tl && cr <= tr){
        return mp(T[node].cur, T[node].full);
    }
    int mid = (cl + cr) / 2;
    pll A = get(T[node].lef_node, cl, mid, tl, tr);
    pll B = get(T[node].rig_node, mid + 1, cr, tl, tr);
    return mp(A.fi + B.fi, A.se + B.se);
}


int n;

vector<ll> fil;
int root[N];

ll compute_sum(ll delta, int li, int ri){
    if(li > ri) return 0;
    int id = upper_bound(fil.begin(), fil.end(), delta) - fil.begin();
    id -- ;
    pll Q = get(root[id], 1, n, li, ri);
    ll res = Q.fi * 1ll * delta + Q.se;
    return res;
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    cin >> n;
    fil.push_back(0ll);
    vector<pii> idi;
    ll F;
    for(int i = 1; i <= n; i ++ ){
        cin >> C[i] >> R[i];
        V[i] = C[i];
        F = (C[i] + R[i] - 1) / R[i];
        fil.push_back(F);
        idi.push_back(mp(F, i));
        //cout << F << "\n";
    }
    sort(fil.begin(), fil.end());
    fil.resize(unique(fil.begin(), fil.end()) - fil.begin());
    sort(idi.begin(), idi.end());
    root[0] = build(1, n);
    //print_tree(root[0], 1, n);
    int nw;
    int p = 0;
    for(int i = 1; i < fil.size(); i ++){
        root[i] = root[i - 1];
        while(p < idi.size() && idi[p].fi <= fil[i]){
            nw = enable(root[i], 1, n, idi[p].se);
            root[i] = nw;
            p ++ ;
        }
    }
    int q;
    cin >> q;
    int T;
    set<pair<int,pii>> events;
    for(int i = 1; i <= n; i ++ ){
        events.insert(mp(i, mp(0, 0)));
    }
    ll CC = 0;
    ll res = 0;
    int las;
    pair<int, pii> cur;
    int id;
    int type;
    int delta;
    ll curr;
    int cut;
    int go;
    int nex;
    for(int i = 1; i <= q; i ++ ){
        cin >> T;
        cin >> CC;
        las = 1;
        while(!events.empty()){
            auto it = events.begin();
            cur = *it;
            events.erase(it);
            id = cur.fi;
            type = cur.se.fi;
            delta = T - cur.se.se;
            if(type == 0){
                curr = min(C[id], V[id] + R[id] * 1ll * delta);
                if(curr <= CC){
                    CC -= curr;
                    cut = id;
                }
                else{
                    curr -= CC;
                    V[id] = curr;
                    CC = 0;
                    events.insert(mp(id, mp(0, T)));
                    cut = id - 1;
                    break;
                }
            }
            else{
                go = las - 1;

                for(int lg = 19; lg >= 0 ; lg -- ){
                    nex = go + (1 << lg);
                    if(nex > id) continue;
                    if(compute_sum(delta, las, nex) <= CC){
                        go = nex;
                    }
                }
                if(go == id){
                    CC -= compute_sum(delta, las, go);
                    cut = go;
                }
                else{
                    CC -= compute_sum(delta, las, go);
                    curr = min(R[go + 1] * 1ll * delta, C[go + 1]);
                    curr -= CC;
                    CC = 0;
                    V[go + 1] = curr;
                    events.insert(mp(go + 1, mp(0, T)));
                    events.insert(mp(id, mp(1, T - delta)));
                    cut = go;
                    break;
                }

            }
            las = id + 1;
        }

        if(cut > 0)
            events.insert(mp(cut, mp(1, T)));
        res += CC;
    }
    cout << res << "\n";
    return 0;
}