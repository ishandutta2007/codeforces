#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
ll A[N];
int typ[N];
ll F[N];

int m;

struct Node{
    int cnt;
    ll sum;
    ll csum;
};

const int M = N * 2;
Node T[M * 4 + 512];
vector<ll> cc;

void check(int node, int cl, int cr, int id){
    if(cl == cr){
        if(T[node].cnt == 0){
            T[node].cnt = 1;
            T[node].sum = cc[id];
            T[node].csum = cc[id];
        }
        else{
            T[node].cnt=0;
            T[node].sum=0;
            T[node].csum=0;
        }
        return;
    }
    int mid = (cl + cr) / 2;
    if(mid >= id)
        check(node * 2, cl, mid, id);
    else
        check(node * 2 + 1, mid + 1, cr, id);
    T[node].cnt = T[node * 2].cnt + T[node * 2 + 1].cnt;
    T[node].sum = T[node * 2].sum + T[node * 2 + 1].sum;
    T[node].csum = T[node * 2].csum + T[node * 2 + 1].csum + T[node * 2 + 1].sum * 1ll * T[node * 2].cnt;
}

ll get(int node, int cl, int cr, int iq){
    if(cl == cr) return T[node].sum;
    int mid = (cl + cr) / 2;
    if(T[node * 2].cnt >= iq)
        return get(node * 2, cl, mid, iq);
    else
        return get(node * 2 + 1, mid + 1, cr, iq - T[node * 2].cnt) + T[node * 2].sum;
}


int getid(int node, int cl, int cr, int iq){
    if(cl == cr) return cl;
    int mid = (cl + cr) / 2;
    if(T[node * 2].cnt >= iq)
        return getid(node * 2, cl, mid, iq);
    else
        return getid(node * 2 + 1, mid + 1, cr, iq - T[node * 2].cnt);
}

Node getsum(int node, int cl, int cr, int tl, int tr){
    if(cr < tl || cl > tr)
        return {0, 0, 0};
    if(cl >= tl && cr <= tr)
        return T[node];
    int mid = (cl + cr) / 2;
    Node aa = getsum(node * 2, cl, mid, tl, tr);
    Node bb = getsum(node * 2 + 1, mid + 1, cr, tl, tr);
    aa.csum += bb.csum + bb.sum * 1ll * aa.cnt;
    aa.cnt += bb.cnt;
    aa.sum += bb.sum;
    return aa;
}

ll getsum(int k){
    if(k == 0) return 0ll;
    return get(1, 0, m - 1, k);
}

int sz;

ll g(int k){
    return getsum(k + 1) - (T[1].sum - getsum(sz - k));
}

int main(){
    fastIO;
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        cc.push_back(A[i]);
    }
    for(int i = 1; i <= q; i ++ ){
        cin >> typ[i] >> F[i];
        cc.push_back(F[i]);
    }
    sort(cc.begin(), cc.end());
    cc.resize(unique(cc.begin(), cc.end()) - cc.begin());
    m = cc.size();
    int iq;
    for(int i = 1; i <= n; i ++ ){
        iq = lower_bound(cc.begin(), cc.end(), A[i]) - cc.begin();
        check(1, 0, m - 1, iq);
    }
    int li, ri, md;
    sz = n;
    ll S1,S2;
    int id;
    for(int i = 0; i <= q; i ++ ){

        if(i){
            iq = lower_bound(cc.begin(), cc.end(), F[i]) - cc.begin();
            check(1, 0, m - 1, iq);
        }

        li = 0;
        sz = T[1].cnt;
        ri = (sz - 1) / 2ll + 1;
        while(li + 1 < ri){
            md = (li + ri) / 2;
            if(g(md) > 0)
                li = md;
            else
                ri = md;
        }
        id = getid(1, 0, m - 1, li + 1);
        Node cur = getsum(1, 0, m - 1, 0, id);
        S1 = (li + 2) * 1ll * cur.sum - cur.csum;
        id = getid(1, 0, m - 1, sz - li + 1);
        if(li == 0){
            S2 = 0;
        }
        else{
            cur = getsum(1, 0, m - 1, id, m - 1);
            S2 = cur.csum;
        }
        S1 -= S2;
        S1 *= 2ll;
        if(li == (sz - 1) / 2 && (sz % 2 == 1)){
            S1 -= g(li); // double counted
        }
        cout << T[1].sum - S1 << "\n";
    }

    return 0;
}