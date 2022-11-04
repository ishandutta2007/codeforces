#include <bits/stdc++.h>
#define INF 1000000000

using namespace std;

struct Treap {
    Treap *left, *right;
    int sz, prio;
    int val;
    int mn;
    Treap(int _val, int _prio) {
        left = right = NULL;
        prio = _prio;
        sz = 1;
        val = _val;
        mn = _val;
    }
};
Treap *T = NULL;

Treap *insert(Treap *, int , int , int );
Treap *balance(Treap *);
Treap *rot_left(Treap *);
Treap *rot_right(Treap *);
Treap *erase(Treap *, int );
std::pair <Treap *, Treap *> split(Treap *, int );
Treap *join(Treap *, Treap *);
inline void refresh(Treap *);
void print(Treap *);

Treap *insert(Treap *nod, int pos, int val, int prio) {
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
     else if(nod -> left -> sz >= pos)
        nod -> left = insert(nod -> left, pos, val, prio);
     else
        nod -> right = insert(nod -> right, pos - nod -> left -> sz - 1, val, prio);
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

Treap *erase(Treap *nod, int pos, bool flag) {
     if((nod -> left == NULL && pos == 1) || (nod -> left != NULL && pos == nod -> left -> sz + 1) || flag) {
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
        if(nod -> left == NULL)
            nod -> right = erase(nod -> right, pos - 1, 0);
        else if(nod -> left -> sz >= pos)
            nod -> left = erase(nod -> left, pos, 0);
        else
            nod -> right = erase(nod -> right, pos - nod -> left -> sz - 1, 0);
        return balance(nod);
     }
}

std::pair <Treap *, Treap *> split(Treap *nod, int pos) {
     nod = insert(nod, pos, -1, INF);
     std::pair <Treap *, Treap *> aux = {nod -> left, nod -> right};
     delete nod;
     nod = NULL;
     return aux;
}

Treap *join(Treap *nod1, Treap *nod2) {
    Treap *aux = new Treap(-1, 0);
    aux -> left = nod1;
    aux -> right = nod2;
    if(aux -> left == NULL)
        aux = erase(aux, 1, 0);
    else
        aux = erase(aux, aux -> left -> sz + 1, 0);
    return aux;
}

long long ans = 0;
int x = 0;

inline void myfind(Treap *nod) {
   if(nod -> left == NULL) {
       if(nod -> val == nod -> mn) {
           x++;
           return ;
       }
       else {
           x++;
           myfind(nod -> right);
       }
   }
   else {
       if(nod -> left -> mn == nod -> mn)
            myfind(nod -> left);
       else if(nod -> mn == nod -> val){
            x += nod -> left -> sz + 1;
            return ;
       }
       else {
           x += nod -> left -> sz + 1;
           myfind(nod -> right);
       }
   }
}

inline Treap *solve(Treap *nod) {
    pair <Treap *, Treap *> aux = split(nod, x - 1);
    if(aux.first != NULL)
       ans += aux.first -> sz;
    ans++;
    return join(aux.second, aux.first);
}

inline void refresh(Treap *nod) {
    nod -> sz = 1;
    nod -> mn = nod -> val;
    if(nod -> left != NULL) {
        nod -> sz += nod -> left -> sz;
        nod -> mn = min(nod -> mn, nod -> left -> mn);
    }
    if(nod -> right != NULL) {
        nod -> sz += nod -> right -> sz;
        nod -> mn = min(nod -> mn, nod -> right -> mn);
    }
}

void print(Treap *nod) {
    if(nod == NULL)
        return ;
    print(nod -> left);
    printf("%d " ,nod -> val);
    print(nod -> right);
}

int main() {
    //fstream cin("B.in");
    //ofstream cout("B.out");
    int i,n,a;
    ios::sync_with_stdio(false);
    srand(time(NULL));
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a;
        T = insert(T, i - 1, a, rand());
    }
    //print(T);
    //printf("1\n");
    while(n > 0) {
        n--;
        x = 0;
        myfind(T);
        T = solve(T);
        T = erase(T, 1, 0);
      //  print(T);
      //  printf("\n");
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}