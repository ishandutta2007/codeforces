#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Treap {
    Treap *left, *right;
    int val;
    int prio;
    ll sum[5];
    int sz;
    Treap(int _val) {
        left = right = NULL;
        val = _val;
        prio = std::abs((rand() << 15) + rand());
        sum[1] = val;
        sum[0] = sum[2] = sum[3] = sum[4] = 0;
        sz = 1;
    }
};
Treap *T = NULL;

Treap *insert(Treap *, int );
Treap *balance(Treap *);
Treap *rot_left(Treap *);
Treap *rot_right(Treap *);
Treap *erase(Treap *, int );
inline void refresh(Treap *);

Treap *insert(Treap *nod, int val) {
    if(nod == NULL) {
        nod = new Treap(val);
        return nod;
    }
    if(nod -> val >= val)
        nod -> left = insert(nod -> left, val);
    else
        nod -> right = insert(nod -> right, val);
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
        if(nod -> val > val)
            nod -> left = erase(nod -> left, val);
        else
            nod -> right = erase(nod -> right, val);
        return balance(nod);
    }
}

inline void refresh(Treap *nod) {
    int i;
    memset(nod -> sum, 0, sizeof(nod -> sum));
    nod -> sz = 0;
    if(nod -> left != NULL) {
        nod -> sz += nod -> left -> sz;
        for(i = 0; i < 5; i++)
           nod -> sum[i] = nod -> left -> sum[i];
    }
    nod -> sz++;
    nod -> sum[nod -> sz % 5] += nod -> val;
    if(nod -> right != NULL) {
        for(i = 0; i < 5; i++)
           nod -> sum[(nod -> sz + i) % 5] += nod -> right -> sum[i];
        nod -> sz += nod -> right -> sz;
    }
}

string str;

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int n, x;
    srand(time(NULL));
    ios::sync_with_stdio(false);
    cin >> n;
    while(n > 0) {
        n--;
        str.clear();
        cin >> str;
        if(str[0] == 'a') {
            cin >> x;
            T = insert(T, x);
        }
        if(str[0] == 'd') {
            cin >> x;
            T = erase(T, x);
        }
        if(str[0] == 's') {
            ll ans;
            if(T == NULL)
               ans = 0;
            else
               ans = T -> sum[3];
            cout << ans << endl;
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}