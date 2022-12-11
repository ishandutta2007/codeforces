#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
const ll inf = (ll)2e18;

struct item{
    ll cnt;
    ll weight;
    ll value;
    int id;
    bool operator< (const item &pq) const {
        if(value != pq.value){
            return value > pq.value;
        }
        else{
            return weight < pq.weight;
        }
    }
};

vector<item> qaq;
ll cc[N];
int mean;

struct segment_tree{
    struct Node{
        ll value;
        ll lazy;
        ll wsum;
        ll dolar;
    };
    Node T[N * 4 + 512];
    void push(int node, int cl, int cr){
        T[node].value += T[node].lazy;
        if(cl != cr){
            T[node * 2].lazy += T[node].lazy;
            T[node * 2 + 1].lazy += T[node].lazy;
        }
        T[node].lazy = 0;
    }
    void update(int node, int cl, int cr, int tl, int tr, ll v){
        push(node, cl, cr);
        if(cr < tl || cl > tr) return;
        if(cl >= tl && cr <= tr){
            T[node].lazy = v;
            push(node, cl, cr);
            return;
        }
        int mid = (cl + cr) / 2;
        update(node * 2, cl, mid, tl, tr, v);
        update(node * 2 + 1, mid + 1, cr, tl, tr, v);
        T[node].value = min(T[node * 2].value, T[node * 2 + 1].value);
    }
    void incr(int node, int cl, int cr, int id, ll cc){
        T[node].wsum += cc * 1ll * qaq[id].weight;
        T[node].dolar += cc * 1ll * qaq[id].value;
        if(cl == cr){

            return;
        }
        int mid = (cl + cr) / 2;
        if(mid >= id)
            incr(node * 2, cl, mid, id, cc);
        else
            incr(node * 2 + 1, mid + 1, cr, id, cc);
    }
    ll walk(int node, int cl, int cr, int id){
        push(node, cl, cr);
        if(cl == cr){
            return T[node].value;
        }
        int mid = (cl + cr) / 2;
        if(mid >= id)
            return walk(node * 2, cl, mid, id);
        else
            return walk(node * 2 + 1, mid + 1, cr, id);
    }
    int get(int node, int cl, int cr, int tl, int tr, ll lim){
        if(cr < tl || cl > tr) return -1;
        if(T[node].value > lim){
            return -1;
        }
        if(cl == cr) return cl;
        int mid = (cl + cr) / 2;
        push(node * 2, cl, mid);
        push(node * 2 + 1, mid + 1, cr);
        if(cl >= tl && cr <= tr){
            if(T[node * 2].value <= lim)
                return get(node * 2, cl, mid, tl, tr, lim);
            else
                return get(node * 2 + 1, mid + 1, cr, tl, tr, lim);
        }
        int pi = get(node * 2, cl, mid, tl, tr, lim);
        if(pi != -1) return pi;
        return get(node * 2 + 1, mid + 1, cr, tl, tr, lim);
    }
    bool can_take;
    ll current;
    int last_id;
    void best(int node, int cl, int cr, int tl, int tr, ll lim){
        if(node == 1){
            can_take = true;
            current = 0ll;
            last_id = tl;
        }
        if(cr < tl || cl > tr) return;
        if(cl >= tl && cr <= tr){
            if(!can_take) return;
            if(current + T[node].wsum <= lim){
                current += T[node].wsum;
                last_id = cr;
                return;
            }
            else{
                if(cl == cr){
                    can_take = false;
                    last_id = cl; // the first one who breaks
                    return;
                }
                int mid = (cl + cr) / 2;
                best(node * 2, cl, mid, tl, tr, lim);
                best(node * 2 + 1, mid + 1, cr, tl, tr, lim);
                return;
            }
        }
        int mid = (cl + cr) / 2;
        best(node * 2, cl, mid, tl, tr, lim);
        best(node * 2 + 1, mid + 1, cr, tl, tr, lim);
    }
    ll calc(int node, int cl, int cr, int tl, int tr, int typ){
        if(cr < tl || cl > tr) return 0ll;
        if(cl >= tl && cr <= tr){
            if(typ == 0){
                return T[node].wsum;
            }
            else{
                return T[node].dolar;
            }
        }
        int mid = (cl + cr) / 2;
        return calc(node * 2, cl, mid, tl, tr, typ) + calc(node * 2 + 1, mid + 1, cr, tl, tr, typ);
    }
};

const int LOG = 22;
segment_tree F[LOG];

int go[N];
int n;


int main(){
    fastIO;
    int q;
    cin >> n >> q;
    qaq.resize(n);
    for(int i = 0 ; i < n; i ++ ){
        cin >> qaq[i].cnt >> qaq[i].weight >> qaq[i].value;
        qaq[i].id = i + 1;
    }
    sort(qaq.begin(), qaq.end());
    for(int i = 0 ; i < n; i ++ ){
        go[qaq[i].id] = i;
        for(int j = 0 ; j < LOG; j ++ ){
            mean = j;
            if(qaq[i].weight < (1ll << j)){
                F[j].update(1, 0, n - 1, i, n - 1, qaq[i].cnt * 1ll * qaq[i].weight);
                F[j].incr(1, 0, n - 1, i, qaq[i].cnt);
            }
            if(qaq[i].weight >= (1ll << j) && qaq[i].weight < (1ll << (j + 1))){
                if(qaq[i].cnt > 0)
                    F[j].update(1, 0, n - 1, i, i, qaq[i].weight);
                else
                    F[j].update(1, 0, n - 1, i, i, inf);
            }
            else{
                F[j].update(1, 0, n - 1, i, i, inf);
            }
        }
    }
    int typ;
    ll cd;
    int it;
    ll lim;
    ll take;
    ll shit;
    int cur;
    int nex;
    ll pref;
    for(int iq = 1; iq <= q; iq ++ ){
        cin >> typ;
        if(typ == 1){
            cin >> cd >> it;
            it = go[it];
            for(int j = 0 ; j < LOG; j ++ ){
                if(qaq[it].weight < (1ll << j)){
                    F[j].update(1, 0, n - 1, it, n - 1, cd * 1ll * qaq[it].weight);
                    F[j].incr(1, 0, n - 1, it, cd);
                }
                if(qaq[it].weight >= (1ll << j) && qaq[it].weight < (1ll << (j + 1))){
                    if(qaq[it].cnt == 0) F[j].update(1, 0, n - 1, it, it, qaq[it].weight-inf);
                }
            }
            qaq[it].cnt += cd;
        }
        else if(typ == 2){
            cin >> cd >> it;
            it = go[it];
            qaq[it].cnt -= cd;
            for(int j = 0 ; j < LOG; j ++ ){
                if(qaq[it].weight < (1ll << j)){
                    F[j].update(1, 0, n - 1, it, n - 1, -cd * 1ll * qaq[it].weight);
                    F[j].incr(1, 0, n - 1, it, -cd);
                }
                if(qaq[it].weight >= (1ll << j) && qaq[it].weight < (1ll << (j + 1))){
                    if(qaq[it].cnt == 0) F[j].update(1, 0, n - 1, it, it, inf-qaq[it].weight);
                }
            }
        }
        else{
            cin >> lim;
            shit = 0;
            cur = 0;
            for(int lg = LOG - 1; lg >= 0 ; lg -- ){
                if(cur >= n) break;
                pref = F[lg].calc(1, 0, n - 1, 0, cur - 1, 0);
                nex = F[lg].get(1, 0, n - 1, cur, n - 1, lim + pref);
                if(nex != -1){
                    lim -= F[lg].calc(1, 0, n - 1, cur, nex - 1, 0);
                    shit += F[lg].calc(1, 0, n - 1, cur, nex - 1, 1);
                    take = min(lim / qaq[nex].weight, qaq[nex].cnt);
                    lim -= take * 1ll * qaq[nex].weight;
                    shit += take * 1ll * qaq[nex].value;
                    cur = nex + 1;
                }
                else{
                    F[lg].best(1, 0, n - 1, cur, n - 1, lim);
                    nex = F[lg].last_id;
                    lim -= F[lg].calc(1, 0, n - 1, cur, nex - 1, 0);
                    shit += F[lg].calc(1, 0, n - 1, cur, nex - 1, 1);
                    take = min(lim / qaq[nex].weight, qaq[nex].cnt);
                    lim -= take * 1ll * qaq[nex].weight;
                    shit += take * 1ll * qaq[nex].value;
                    cur = nex + 1;
                }
            }
            cout << shit << "\n";
        }
    }
    return 0;
}