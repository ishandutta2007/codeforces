#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int INF = (int) 2e9;

inline int next_rand() {
    return abs((rand() << 15) + rand());
}

struct Treap {
    Treap *left, *right;
    int prio, val;
    int sz;
    bool lazy;
    Treap(int _val, int _prio) {
        left = right = NULL;
        val = _val;
        prio = _prio;
        sz = 1;
        lazy = 0;
    }
};

Treap *T = NULL;

Treap *insert(Treap *, int , int , int );
Treap *balance(Treap *);
Treap *rot_left(Treap *);
Treap *rot_right(Treap *);
Treap *erase(Treap *, int , bool );
pair <Treap *, Treap *> split(Treap *, int );
Treap *join(Treap *, Treap *);
Treap *rev(Treap *, int , int );
Treap *shift(Treap *, int , int );
inline void refresh(Treap *);

inline void prop(Treap *nod) {
    if(nod -> left != NULL)
        nod -> left -> lazy ^= nod -> lazy;
    if(nod -> right != NULL)
        nod -> right -> lazy ^= nod -> lazy;
}

inline void solve_lazy(Treap *nod) {
    if(nod == NULL)
        return ;
    prop(nod);
    if(nod -> lazy)
        swap(nod -> left, nod -> right);
    nod -> lazy = 0;
}

Treap *insert(Treap *nod, int pos, int val, int prio) {
    solve_lazy(nod);
    if(nod == NULL) {
        nod = new Treap(val, prio);
        return nod;
    }
    if(nod -> left == NULL) {
        if(pos == 0)
            nod -> left = insert(nod -> left, pos, val, prio);
        else
            nod -> right = insert(nod -> right, pos - 1, val, prio);
    }
    else {
        if(nod -> left -> sz >= pos)
            nod -> left = insert(nod -> left, pos, val, prio);
        else
            nod -> right = insert(nod -> right, pos - nod -> left -> sz - 1, val, prio);
    }
    return balance(nod);
}

Treap *balance(Treap *nod) {
    solve_lazy(nod);
    if(nod -> left != NULL && nod -> left -> prio > nod -> prio)
        return rot_right(nod);
    if(nod -> right != NULL && nod -> right -> prio > nod -> prio)
        return rot_left(nod);
    refresh(nod);
    return nod;
}

Treap *rot_left(Treap *nod) {
    solve_lazy(nod);
    Treap *aux = nod -> right;
    solve_lazy(aux);
    nod -> right = aux -> left;
    aux -> left = nod;
    refresh(nod);
    refresh(aux);
    return aux;
}

Treap *rot_right(Treap *nod) {
    solve_lazy(nod);
    Treap *aux = nod -> left;
    solve_lazy(aux);
    nod -> left = aux -> right;
    aux -> right = nod;
    refresh(nod);
    refresh(aux);
    return aux;
}

Treap *erase(Treap *nod, int pos, bool flag) {
    solve_lazy(nod);
    if((nod -> left == NULL && pos == 1) || (nod -> left != NULL && nod -> left -> sz + 1 == pos) || flag) {
        Treap *aux;
        if(nod -> left == NULL && nod -> right == NULL) {
            delete nod;
            return NULL;
        }
        else if(nod -> left == NULL) {
            aux = rot_left(nod);
            aux -> left = erase(aux -> left, pos, 1);
        }
        else if(nod -> right == NULL) {
            aux = rot_right(nod);
            aux -> right = erase(aux -> right, pos, 1);
        }
        else if(nod -> left -> prio > nod -> right -> prio) {
            aux = rot_right(nod);
            aux -> right = erase(aux -> right, pos, 1);
        }
        else {
            aux = rot_left(nod);
            aux -> left = erase(aux -> left, pos, 1);
        }
        return balance(aux);
    }
    else {
        if(nod -> left -> sz > pos)
            nod -> left = erase(nod -> left, pos, 0);
        else
            nod -> right = erase(nod -> right, pos - nod -> left -> sz - 1, 0);
        return balance(nod);
    }
}

pair <Treap *, Treap *> split(Treap *nod, int pos) {
    solve_lazy(nod);
    Treap *aux = insert(nod, pos - 1, -1, INF);
    return {aux -> left, aux -> right};
}


Treap *join(Treap *nod1, Treap *nod2) {
    solve_lazy(nod1);
    solve_lazy(nod2);
    Treap *aux = new Treap(-1, 0);
    aux -> left = nod1;
    aux -> right = nod2;
    if(aux -> left == NULL)
        aux = erase(aux, 1, 0);
    else
        aux = erase(aux, aux -> left -> sz + 1, 0);
    return aux;
}

Treap *rev(Treap *nod, int l, int r) {
    solve_lazy(nod);
    pair <Treap *, Treap *> pr1 = split(nod, l);
    pair <Treap *, Treap *> pr2 = split(pr1.second, r - l + 2);
    pr2.first -> lazy ^= 1;
    return join(join(pr1.first, pr2.first), pr2.second);
}

Treap *shift(Treap *nod, int l, int r) {
    solve_lazy(nod);
    pair <Treap *, Treap *> pr1 = split(nod, l);
    pair <Treap *, Treap *> pr2 = split(pr1.second, r - l + 2);
    pair <Treap *, Treap *> pr3 = split(pr2.first, r - l + 1);
    pr2.first = join(pr3.second, pr3.first);
    return join(join(pr1.first, pr2.first), pr2.second);
}

inline void refresh(Treap *nod) {
    solve_lazy(nod);
    nod -> sz = 1;
    if(nod -> left != NULL)
        nod -> sz += nod -> left -> sz;
    if(nod -> right != NULL)
        nod -> sz += nod -> right -> sz;
}

int query(Treap *nod, int pos) {
    solve_lazy(nod);
    if((nod -> left == NULL && pos == 1) || (nod -> left != NULL && nod -> left -> sz + 1 == pos))
        return nod -> val;
    else {
        if(nod -> left == NULL)
            return query(nod -> right, pos - 1);
        else if(nod -> left -> sz >= pos)
            return query(nod -> left, pos);
        else
            return query(nod -> right, pos - nod -> left -> sz - 1);
    }
}


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, q, m, x;
    srand(time(NULL));
    ios::sync_with_stdio(false);
    cin >> n >> q >> m;
    for(i = 1; i <= n; i++) {
        cin >> x;
        T = insert(T, i - 1, x, next_rand());
    }
    while(q > 0) {
        q--;
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1)
            T = shift(T, l, r);
        else
            T = rev(T, l, r);
    }
    for(i = 1; i <= m; i++) {
        cin >> x;
        cout << query(T, x) << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}