#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5 + 5;

ll hp[MAXN + 1], dmg[MAXN + 1];

struct Treap {
    Treap *left, *right;
    int val, prio;
    int sz;
    ll sum;
    Treap(int _val) {
        left = right = NULL;
        val = _val;
        prio = rand();
        sum = _val;
        sz = 1;
    }

}*root = NULL;

Treap *balance(Treap *nod);
inline void refresh(Treap *);

Treap *rot_left(Treap *nod) {
    Treap *aux = nod -> right;
    nod -> right = aux -> left;
    aux -> left = nod;
    refresh(nod);
    refresh(aux);
    return aux;
}


Treap *rot_right(Treap *nod) {
    Treap *aux = nod -> left;
    nod -> left = aux -> right;
    aux -> right = nod;
    refresh(nod);
    refresh(aux);
    return aux;
}

Treap *insert(Treap *nod, int val) {
    if(nod == NULL) {
        nod = new Treap(val);
        return nod;
    }
    if(nod -> val > val) {
        nod -> right = insert(nod -> right, val);
    }
    else {
        nod -> left = insert(nod -> left, val);
    }
    return balance(nod);
}

Treap *balance(Treap *nod) {
    if(nod -> left != NULL && nod -> left -> prio > nod -> prio)
        return rot_right(nod);
    if(nod -> right != NULL && nod -> right -> prio > nod -> prio)
        return rot_left(nod);
    refresh(nod);
    return nod;
}

inline void refresh(Treap *nod) {
    nod -> sz = 1;
    nod -> sum = nod -> val;
    if(nod -> left != NULL) {
        nod -> sz += nod -> left -> sz;
        nod -> sum += nod -> left -> sum;
    }
    if(nod -> right != NULL) {
        nod -> sz += nod -> right -> sz;
        nod -> sum += nod -> right -> sum;
    }
}

Treap *erase(Treap *nod, int val) {
    if(nod -> val == val) {
        Treap *aux;
        if(nod -> left == NULL && nod -> right == NULL) {
            delete nod;
            return NULL;
        }
        else if(nod -> left == NULL) {
            aux = rot_left(nod);
            aux -> left = erase(aux -> left, val);
        }
        else if(nod -> right == NULL) {
            aux = rot_right(nod);
            aux -> right = erase(aux -> right, val);
        }
        else if(nod -> left -> prio > nod -> right -> prio) {
            aux = rot_right(nod);
            aux -> right = erase(aux -> right, val);
        }
        else {
            aux = rot_left(nod);
            aux -> left = erase(aux -> left, val);
        }
        return balance(aux);
    }
    else {
        if(nod -> val > val) {
            nod -> right = erase(nod -> right, val);
        }
        else {
            nod -> left = erase(nod -> left, val);
        }
        return balance(nod);
    }
}

ll query(Treap *nod, int sz) {
    if(sz == nod -> sz) {
        return nod -> sum;
    }
    if(sz == 1 && nod -> left == NULL) {
        return nod -> val;
    }
    if(nod -> left != NULL && sz == nod -> left -> sz + 1) {
        return nod -> left -> sum + nod -> val;
    }
    if(nod -> left == NULL) {
        return query(nod -> right, sz - 1) + nod -> val;
    }
    else {
        if(nod -> left -> sz >= sz) {
            return query(nod -> left, sz);
        }
        else {
            return nod -> left -> sum + nod -> val + query(nod -> right, sz - nod -> left -> sz - 1);
        }
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, a, b;
    ios::sync_with_stdio(false);
    srand(time(NULL));
    cin >> n >> a >> b;
    ll sum = 0;
    int cnt = 0;
    for(i = 1; i <= n; i++) {
        cin >> hp[i] >> dmg[i];
        sum += dmg[i];
        if(hp[i] - dmg[i] > 0) {
            root = insert(root, hp[i] - dmg[i]);
            cnt++;
        }
    }
    if(b == 0) {
        cout << sum;
        return 0;
    }
    ll ans = sum;
    for(i = 1; i <= n; i++) {
        ll val = (1LL << a) * hp[i] - dmg[i];
        if(hp[i] - dmg[i] > 0) {
            root = erase(root, hp[i] - dmg[i]);
            cnt--;
        }
        if(min(b - 1, cnt) > 0)
            val += query(root, min(b - 1, cnt));
        if(hp[i] - dmg[i] > 0) {
            root = insert(root, hp[i] - dmg[i]);
            cnt++;
        }
        ans = max(ans, val + sum);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}