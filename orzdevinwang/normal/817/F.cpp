#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--) 
#define ll long long 
#define db double 
using namespace std;
const ll MAXN = 1e18 + 1;
const int M = 2e6;
const int N = 3e5;
int n, q, TOT, head;
ll mexa[M], mexb[M]; // mexa :  0; mexb :  1
int flag[M], ch[M][2];
void push(int id, ll L, ll R, int x) {
    if(x == 1) mexa[id] = 0, mexb[id] = L, flag[id] = 1;
    else if(x == 2) mexa[id] = L, mexb[id] = 0, flag[id] = 2;
    else {
        swap(mexa[id], mexb[id]);
        if(flag[id]) flag[id] = 3 - flag[id];
        else flag[id] = 3;
    }
}
void pushdown(int id, ll L, ll R) {
    ll mid = (L + R) / 2;
    if(!ch[id][0]) ch[id][0] = ++TOT, mexa[TOT] = L, mexb[TOT] = 0;
    if(!ch[id][1]) ch[id][1] = ++TOT, mexa[TOT] = mid + 1, mexb[TOT] = 0;
    if(!flag[id]) return;
    push(ch[id][0], L, mid, flag[id]), push(ch[id][1], mid + 1, R, flag[id]), flag[id] = 0;
}
void upd(int id) {
    if(mexa[ch[id][0]] == 0) mexa[id] = mexa[ch[id][1]];
    else mexa[id] = mexa[ch[id][0]];
    if(mexb[ch[id][0]] == 0) mexb[id] = mexb[ch[id][1]];
    else mexb[id] = mexb[ch[id][0]];
}
void add(int &id, ll L, ll R, ll l, ll r, int val) {
    if(!id) id = ++TOT, mexa[TOT] = L, mexb[TOT] = 0;
    if(l <= L && R <= r) return push(id, L, R, val), void();
    ll mid = (L + R) / 2;
    pushdown(id, L, R);
    if(l <= mid) add(ch[id][0], L, mid, l, r, val);
    if(r > mid) add(ch[id][1], mid + 1, R, l, r, val);
    upd(id);
}
int opt[N], tot; ll fl[N], fr[N], arr[M];
int main() {
    scanf("%d", &q);
    L(i, 1, q) scanf("%d%lld%lld", &opt[i], &fl[i], &fr[i]), arr[++tot] = fl[i], arr[++tot] = fr[i], arr[++tot] = fr[i] + 1;
    arr[++tot] = 1;
    arr[++tot] = MAXN;
    sort(arr + 1, arr + tot + 1);
    tot = unique(arr + 1, arr + tot + 1) - arr - 1;
    L(i, 1, q) fl[i] = lower_bound(arr + 1, arr + tot + 1, fl[i]) - arr, fr[i] = lower_bound(arr + 1, arr + tot + 1, fr[i]) - arr;
    L(i, 1, q) {
        add(head, 1, tot, fl[i], fr[i], opt[i]);
        printf("%lld\n", arr[mexa[head]]);
    }
    return 0;
}