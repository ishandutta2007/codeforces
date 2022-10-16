#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 500;
const int LOG = 18;
const int OFF = (1 << LOG);

int n,q,a[N];

struct node{
    int mi, kol, gcd;
    node(){
        kol = 0, mi = 1,gcd = -1;
    }
};

node tour[3 * OFF], NUL;

node mrg(node A, node B){
    if(A.gcd <= 0) return B;
    if(B.gcd <= 0) return A;
    node C;
    C.mi = min(A.mi, B.mi);
    C.kol = 0;
    if(C.mi == A.mi) C.kol += A.kol;
    if(C.mi == B.mi) C.kol += B.kol;
    C.gcd = __gcd(A.gcd, B.gcd);
    return C;
}

node query(int i,int a,int b,int lo,int hi){
    if(lo <= a && b <= hi) return tour[i];
    if(a > hi || b < lo) return NUL;
    return mrg(query(2 * i, a, (a + b) / 2, lo, hi), query(2 * i + 1, (a + b) / 2  + 1, b, lo, hi));
}

void build(){
    for(int i = OFF;i<OFF + n;i++){
        tour[i].mi = a[i - OFF];
        tour[i].kol = 1;
        tour[i].gcd = a[i - OFF];
    }
    for(int i = OFF - 1;i>0;i--){
        tour[i] = mrg(tour[2 * i], tour[2 * i + 1]);
    }
}

int getans(){
    int l,r;scanf("%d%d", &l, &r);
    l--,r--;
    node res = query(1, 0, OFF - 1, l, r);
    if(res.gcd % res.mi != 0) return r - l + 1;
    return r - l - res.kol + 1;
}

int main(){
    scanf("%d", &n);
    for(int i = 0;i<n;i++){
        scanf("%d", a + i);
    }
    build();
    scanf("%d", &q);
    for(int i = 0;i<q;i++){
        printf("%d\n", getans());
    }
}