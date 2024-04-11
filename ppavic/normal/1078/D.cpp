#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 50;
const int LOG = 18;
const int OFF = (1 << LOG);
const int INF = 0x3f3f3f3f;

int l[LOG][2 * OFF], r[LOG][2 * OFF], ll[N], rr[N], rad[N], n;
int lo, hi, k;

int query_l(int lo, int hi,int k) {
    int ret = INF;hi++;
    for (lo += OFF, hi += OFF; lo < hi; lo >>= 1, hi >>= 1) {
        if(lo&1) ret = min(ret, l[k][lo++]);
        if(hi&1) ret = min(ret, l[k][--hi]);
    }
    return ret;
}

int query_r(int lo, int hi,int k) {
    int ret = -INF;hi++;
    for (lo += OFF, hi += OFF; lo < hi; lo >>= 1, hi >>= 1) {
        if(lo&1) ret = max(ret, r[k][lo++]);
        if(hi&1) ret = max(ret, r[k][--hi]);
    }
    return ret;
}


void build(int k){
    for(int i = OFF - 1;i >= 0;i--){
        l[k][i] = min(l[k][2 * i], l[k][2 * i + 1]);
        r[k][i] = max(r[k][2 * i], r[k][2 * i + 1]);
    }
}

void lifting(){
    for(int i = 0;i<2 * n;i++){
        l[0][i + OFF] = max(i - rad[i], 0);
        r[0][i + OFF] = min(i + rad[i], 2 * n - 1);
    }
    build(0);
    for(int k = 1;k<LOG;k++){
        for(int i = 0;i<2 * n;i++){
            l[k][i + OFF] = query_l(l[k - 1][i + OFF], r[k - 1][i + OFF],  k - 1);
            r[k][i + OFF] = query_r(l[k - 1][i + OFF], r[k - 1][i + OFF], k - 1);
        }
        build(k);
    }
}

int get_ans(int i){
    int curl = i, curr = i, ret = 0;
    for(int k = LOG - 1; k >= 0; k--){
        int newl = query_l(curl, curr, k);
        int newr = query_r(curl, curr, k);
        if(newr - newl >= n - 1) continue;
        curl = newl;
        curr = newr;
        ret += (1 << k);
    }
    return ret + 1;
}

int main(){
    scanf("%d", &n);
    if(n == 1){printf("0\n");return 0;}
    for(int i = 0;i<n;i++){
        scanf("%d", rad + i);
        rad[n + i] = rad[i];
    }
    lifting();
    for(int i = 0;i<n;i++){
        printf("%d ", min(get_ans(i), get_ans(i + n)));
    }
    printf("\n");

}