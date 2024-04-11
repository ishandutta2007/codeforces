#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

#define X first
#define Y second
#define PB push_back

using namespace std;

struct node{
    node *L, *R;
    int ky, pri, prop, ind, ans, prop_ans;
    node(int ky, int ind,int ans) : ky(ky), prop(0), L(0), R(0), ind(ind), pri(rand() * rand()), ans(ans), prop_ans(0) {}
};

typedef node* pnode;

const int N = 2e5 + 500;

pnode root = 0;
int n, q, ans[N];
vector < pair < int, int > > v;

void push(pnode X){
    if(!X) return;
    X -> ky -= X -> prop;
    X -> ans += X -> prop_ans;
    if(X -> L)
        X -> L -> prop += X -> prop,
        X -> L -> prop_ans +=  X -> prop_ans;
    if(X -> R)
        X -> R -> prop += X -> prop,
        X -> R -> prop_ans +=  X -> prop_ans;
    X -> prop = 0;
    X -> prop_ans = 0;
}

void split(pnode T, int k, pnode &l, pnode &r){
    push(T);
    if(!T)
        l = r = 0;
    else if((T -> ky) <= k)
        l = T, split(T -> R, k, T -> R, r);
    else
        r = T, split(T -> L, k, l, T -> L);
}

void mrg(pnode &T, pnode l, pnode r){
    push(l), push(r);
    if(!l || !r)
        T = l ? l : r;
    else if((l -> pri) > (r -> pri))
        T = l, mrg(T -> R, T -> R, r);
    else
        T = r, mrg(T -> L, l, T -> L);
}

void insrt(pnode &T, pnode X){
    //printf("insertiram %d %d\n", X -> ky, X -> ind);
    push(T);
    if(!T)
        T = X;
    else if((T -> pri) < (X -> pri))
        split(T, X -> ky, X -> L, X -> R), T = X;
    else
        insrt((X -> ky) < (T -> ky) ? T -> L : T -> R, X);
}

pnode nadi(pnode T, int l, int r){
    push(T);
    if(!T) return NULL;
    if((T -> ky) >= l && (T -> ky) <= r)
        return T;
    if((T -> ky) >= r)
        return nadi(T -> L, l, r);
    return nadi(T -> R, l, r);
}

void remv(pnode &T, pnode X){
    if(T -> ind == X -> ind && T -> ky == X -> ky){
        mrg(T, T -> L, T -> R);
    }
    else if(X -> ky < T -> ky)
        remv(T -> L, X);
    else
        remv(T -> R, X);
}

void rijesi(pnode T){
    if(!T) return;
    push(T);
    //printf("%d %d %d\n", T  -> ind, T -> ky, T -> ans);
    ans[T -> ind] = T -> ans;
    rijesi(T -> L), rijesi(T -> R);
}

int odradi(int c){
    pnode nw = nadi(root, c, 2 * c - 1);
    if(nw == NULL) return 0;
    //printf("%d\n", nw -> ky);
    insrt(root, new node(nw -> ky - c, nw -> ind, nw -> ans + 1));
    remv(root, nw);
    //printf("odradio\n");
    return 1;
}

int main(){
    scanf("%d", &n);
    for(int i = 0;i < n;i++){
        int x, y; scanf("%d%d", &x, &y);
        v.PB({y, -x});
    }
    sort(v.rbegin(), v.rend());
    scanf("%d", &q);
    for(int i = 0;i < q;i++){
        int x; scanf("%d", &x);
        insrt(root, new node(x, i, 0));
       // printf("root = %d %d %d\n", root, root -> L, root -> R);
    }
    for(int i = 0;i < n;i++){
        int c = -v[i].Y;
        //printf("c = %d\n", c);
        while(odradi(c));
        pnode tmp;
        split(root, 2 * c - 1, root, tmp);
        if(tmp) tmp -> prop_ans++, tmp -> prop += c;
        mrg(root, root, tmp);
        if(0){
            rijesi(root);
            //for(int i = 0;i < q;i++)
            //    printf("%d ", ans[i]);
            //printf("\n");
        }
    }
    rijesi(root);
    for(int i = 0;i < q;i++)
        printf("%d ", ans[i]);
    printf("\n");
}