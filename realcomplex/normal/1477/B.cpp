#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Node{
    int cnt[3];
    int lzy;
};

const int N = (int)2e5 + 100;
Node T[N * 4 + 512];

void push(int node, int cl, int cr){
    if(T[node].lzy == -1) return;
    for(int j = 0 ; j < 3; j ++ ){
        T[node].cnt[j]=0;
    }
    if(cl != cr){
        T[node*2].lzy = T[node].lzy;
        T[node*2+1].lzy=T[node].lzy;
    }
    T[node].cnt[T[node].lzy] = cr - cl + 1;
    T[node].lzy = -1;
}

void update(int node, int cl, int cr, int tl, int tr, int v){
    push(node, cl, cr);
    if(cr < tl || cl > tr) return;
    if(cl >= tl && cr <= tr){
        T[node].lzy = v;
        push(node, cl, cr);
        return;
    }
    int mid = (cl + cr) / 2;
    update(node * 2, cl, mid, tl, tr, v);
    update(node * 2 + 1, mid + 1, cr, tl, tr, v);
    for(int t = 0; t < 3; t ++ ){
        T[node].cnt[t] = T[node * 2].cnt[t] + T[node * 2 + 1].cnt[t];
    }
}


int get(int node, int cl, int cr, int tl, int tr, int v){
    push(node, cl, cr);
    if(cr < tl || cl > tr) return 0;
    if(cl >= tl && cr <= tr) return T[node].cnt[v];
    int mid = (cl + cr) / 2;
    return get(node * 2, cl, mid, tl, tr, v) + get(node * 2 + 1, mid + 1, cr, tl, tr, v);
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        int n, q;
        cin >> n >> q;
        string s, f;
        cin >> s >> f;
        for(int i = 0 ;i < 4 * n + 12; i ++ ){
            T[i].cnt[0] = T[i].cnt[1] = T[i].cnt[2] = 0;
            T[i].lzy = -1;
        }
        int l, r;
        int sz;
        int c0, c1, c2;
        for(int i = 0 ; i < n; i ++ ){
            if(f[i] == '0')
                update(1, 0, n - 1, i, i, 0);
            else
                update(1, 0, n - 1, i, i, 1);
        }
        vector<pii> qq;
        for(int i = 0 ; i < q; i ++) {
            cin >> l >> r;
            l--;
            r--;
            qq.push_back(mp(l,r));
        }
        reverse(qq.begin(), qq.end());
        bool soln = true;
        for(auto x : qq){
            l = x.fi;
            r = x.se;
            sz = (r - l + 1);
            c0 = get(1, 0, n - 1, l, r, 0);
            c1 = get(1, 0, n - 1, l, r, 1);
            c2 = get(1, 0, n - 1, l, r, 2);
            if(c0 < (sz+1) / 2 && c1 < (sz+1) / 2){
                update(1, 0, n - 1, l, r, 2);
            }
            else{
                if(c1 < (sz+1) / 2){
                    update(1, 0, n - 1, l, r, 0);
                }
                else if(c0 < (sz+1)/2){
                    update(1, 0, n - 1, l, r, 1);
                }
                else{
                    soln = false;
                }
            }
        }
        for(int i = 0; i < n; i ++ ){
            if(s[i] == '0'){
                if(get(1, 0, n - 1, i, i, 0) + get(1, 0, n - 1, i, i, 2) == 0){
                    soln = false;
                }
            }
            else{
                if(get(1, 0, n - 1, i, i, 1) + get(1, 0, n - 1, i, i, 2) == 0){
                    soln = false;
                }
            }
        }
        if(soln)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}