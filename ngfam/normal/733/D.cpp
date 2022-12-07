/* Riven is not just my life :) */

#include <bits/stdc++.h>
#define prob "test"
typedef long long llint;
using namespace std;
void MAIN();
int main(){
    #ifndef ONLINE_JUDGE
        freopen(prob".inp","r",stdin);
      //  freopen(prob".out","w",stdout);
    #endif
    MAIN();
    return 0;
}
const llint N = 1e6 + 1, mod = 1e9 + 7;

struct data{
    llint hei;
    llint min_;
    llint S;
    int id;
}Hei[N], Wid[N], Len[N];

int n, nHei, nWid, nLen, sl = 1, big[N];

bool cmp(data u, data v){
    if(u.S == v.S) return u.min_ < v.min_;
    return u.S < v.S;
}

data solve(data a[N]){
    memset(big, 0, sizeof big);
    a[nHei + 1].S = -1;
    for(int i = nHei; i >= 1; --i){
        if(a[i].S != a[i + 1].S){
            big[i] = i;
        }
        else{
            big[i] = big[i + 1];
            if(a[i].hei > a[big[i]].hei)
                big[i] = i;
        }
    }

    data inf = {0, 0, 0, 0};
    for(int i = 1; i <= nHei; ++i){
        int ginz = big[i];
        if(a[i].S != a[i + 1].S) continue;
        if(big[i] == i){
            ginz = big[i + 1];
        }
        if(inf.hei < min(a[i].min_, a[i].hei + a[ginz].hei)){
            inf.hei = min(a[i].min_, a[i].hei + a[ginz].hei);
            inf.min_ = a[i].id;
            inf.S = a[ginz].id;
        }
    }
    return inf;
}

data ans;

data maximize(data u, data v){
    if(u.hei < v.hei) return v;
    return u;
}

void MAIN(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        llint u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);

        Hei[++nHei] = {u, min(v, w), v * w, i};
        if(u != v){
            Hei[++nHei] = {v, min(u, w), u * w, i};
            if(w != u && w != v) Hei[++nHei] = {w, min(u, v), u * v, i};
        }
        else{
            if(w != u) Hei[++nHei] = {w, min(u, v), u * v, i};
        }
        if(ans.hei < min(min(u, v), w)){
            ans.hei = min(min(u, v), w);
            ans.min_ = i;
        }
    }

    sort(Hei + 1, Hei + nHei + 1, cmp);
    ans = maximize(ans, solve(Hei));

    if(ans.S != 0) puts("2");
    else puts("1");

    printf("%lld ", ans.min_);
    if(ans.S != 0) printf("%lld", ans.S);
}