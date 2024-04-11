#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

const int N = 1e5 + 500;

int kreni = 0;

struct node{
    node *L[2], *R[2], *par[2];
    int siz[2], prop, ind, pri[2], vr;
    node(int _ind, int _vr){
        ind = _ind; vr = _vr;
        siz[0] = 1, siz[1] = 1;
        L[0] = 0, L[1] = 0;
        R[0] = 0, R[1] = 0;
        par[0] = 0, par[1] = 0;
        pri[0] = rand() * rand();
        pri[1] = rand() * rand();
        prop = 0;
    }
};

typedef node* pnode;

pnode root[N], vel_root;
int n, q;

void update(pnode X,int k){
    if(!X) return;
    X -> siz[k] = 1;
    if(X -> L[k]){
        X -> siz[k] += X -> L[k] -> siz[k];
        X -> L[k] -> par[k] = X;
    }
    if(X -> R[k]){
        X -> siz[k] += X -> R[k] -> siz[k];
        X -> R[k] -> par[k] = X;
    }
}

void update_ind(pnode X){
    if(!X) return;
    update(X, 0);
    update_ind(X -> par[0]);
    if(!(X -> par[0])){
        X -> ind = 1;
        if(X -> L[0])
            X -> ind += X -> L[0] -> siz[0];
    }
    else if((X -> par[0] -> R[0]) == X){
        X -> ind = X -> par[0] -> ind + 1;
        if(X -> L[0])
            X -> ind += X -> L[0] -> siz[0];
    }
    else{
        X -> ind = X -> par[0] -> ind - 1;
        if(X -> R[0])
            X -> ind -= X -> R[0] -> siz[0];
    }
}

void split(pnode T, int ky, pnode &L, pnode &R, int k,int fl = 0){
    update_ind(T);
    if(kreni){
        printf("DIJELIM PO %d\n", ky);
        if(!T) printf("T = NULA\n");
        else printf("T(%d %d) T:%d T_L:%d T_R:%d\n", T -> ind, T -> vr, T, T -> L[k], T -> R[k]);
    }
    if(!T)
        L = 0, R = 0;
    else if(T -> ind <= ky)
        split(T -> R[k], ky, T -> R[k], R, k), L = T;
    else
        split(T -> L[k], ky, L, T -> L[k], k), R = T;
    update(T, k);
    if(fl){
        if(L) L -> par[k] = 0;
        if(R) R -> par[k] = 0;
    }
}

void mrg(pnode &T, pnode L, pnode R,int k){
    if(!L || !R)
        T = (L ? L : R);
    else if((L -> pri[k]) > (R -> pri[k]))
        T = L, mrg(T -> R[k], T -> R[k], R, k);
    else
        T = R, mrg(T -> L[k], L, T -> L[k], k);
    update(T, k);
}

void insrt(pnode &T, pnode nov, int k){
    update_ind(T); // OVO NE MICATI
    if(!T)
        T = nov;
    else if((nov -> pri[k]) > (T -> pri[k]))
        split(T, nov -> ind, nov -> L[k], nov -> R[k], k), T = nov;
    else
        insrt((nov -> ind <= T -> ind) ? (T -> L[k]) : (T -> R[k]), nov, k);
    update(T, k);
}

void delt(pnode &T, int koji, int k){
    update_ind(T);
    if(T -> ind == koji)
        mrg(T, T -> L[k], T -> R[k], k);
    else
        delt((T -> ind < koji) ? T -> R[k] : T -> L[k], koji, k);
    update(T, k);
}

int bio[N];

void provjeri(node* X,int dep = 0){
    if(!X) return;
    update(X, 0);
    provjeri(X -> L[0], dep + 1);
    update_ind(X);
    bio[X -> ind]++;
    //printf("%d {%d, %d}  ", X -> ind, X -> vr, dep);
    provjeri(X -> R[0], dep + 1);
}

int vrije(pnode X, int k){
    update_ind(X);
    if(X -> ind == k) return X -> vr;
    if(X -> ind > k)
        return vrije(X -> L[0], k);
    return vrije(X -> R[0], k);
}

int main(){
    scanf("%d", &n);
    for(int i = 1;i <= n;i++){
        int x; scanf("%d", &x);
        pnode nw = new node(i, x);
        insrt(vel_root, nw, 0);
        insrt(root[x], nw, 1);
    }
    scanf("%d", &q);
    int lst_out = 0;
    for(int i = 0;i < q;i++){
        int ty; scanf("%d", &ty);
        if(ty == 1){
            int l, r; scanf("%d%d", &l, &r);
            l = ((l + lst_out) - 1 + n) % n + 1;
            r = ((r + lst_out) - 1 + n) % n + 1;
            if(l > r) swap(l, r);
            int vr = vrije(vel_root, r);
            delt(root[vr], r , 1);
            pnode N1, N2, N3;
            split(vel_root, r, vel_root, N2, 0, 1);
            split(vel_root, r - 1, vel_root, N3, 0, 1);
            split(vel_root, l - 1, vel_root, N1, 0, 1);
            mrg(vel_root, vel_root, N3, 0);
            mrg(vel_root, vel_root, N1, 0);
            mrg(vel_root, vel_root, N2, 0);
            update_ind(N3); N3 -> L[1] = 0, N3 -> R[1] = 0;
            insrt(root[vr], N3, 1);
        }
        else{
            int l, r, k; scanf("%d%d%d", &l, &r, &k);
          //  if(l == 15 && r == 28){
          //      provjeri(vel_root); kreni = 1;
          //  }
            l = ((l + lst_out) - 1 + n) % n + 1;
            r = ((r + lst_out) - 1 + n) % n + 1;
            k = ((k + lst_out) - 1 + n) % n + 1;
            if(l > r) swap(l, r);
            if(!root[k]){
                lst_out = 0;
                printf("0\n");
            }
            else{
                pnode N1 = 0, N2 = 0;
              //  printf("tu sam\n");
                split(root[k], l - 1, root[k], N1, 1, 1);
                split(N1, r, N1, N2, 1, 1);
                lst_out = 0;
                if(N1) lst_out = N1 -> siz[1];
                printf("%d\n", lst_out);
                mrg(root[k], root[k], N1, 1);
                mrg(root[k], root[k], N2, 1);

            }
        }
    }
}