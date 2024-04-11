#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double du;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)
const int MAXN = 1<<17;
const int INF = 7<<28;

struct T{
    int maxa, minr;
    
    T():maxa(0), minr(INF){}
    T(int a, int b):maxa(a), minr(b){}
    T operator+ (T t)const {
        return T(max(maxa, t.maxa), min(minr, t.minr));
    }
};

T a[MAXN*2];
int del[MAXN*2];
int l[MAXN], r[MAXN], t[MAXN];

void setDel(int i, int d){
    del[i] += d;
    a[i].minr -= d;
}

void push(int i){
    setDel(i*2, del[i]);
    setDel(i*2+1, del[i]);
    del[i] = 0;
}

void com(int i){
    push(i);
    a[i] = a[i*2] + a[i*2+1];
}

void clear(int i){
    int j;
    for(j = 0; (1<<j) < MAXN; j++);
    for(; j; j--)
        push(i>>j);
}

T get(int i){
    clear(i);
    T ret = T();
    while(i){
        if(~i&1)
            ret = a[i+1] + ret;
        i >>= 1;
    }
    return ret;
}

void modify(int i, T t){
    i += MAXN;
    clear(i);
    a[i] = t;
    del[i] = 0;
    i >>= 1;
    while(i){
        com(i);
        i >>= 1;
    }
}

void init(){
    fill(a, a+MAXN*2, T());
}

void put(int t){
    printf("%d ", t);
}

int main()
{
    int n;
    int i, j, k;
    int ans = 0;
    init();
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d%d%d", &l[i], &r[i], &t[i]);
        r[i]++;
    }
    for(i = 1; i <= n; i++){
        if(max(ans, l[i]) + t[i] <= r[i]){
            put(0);
            modify(i, T(t[i], max(ans, l[i])-l[i]));
            ans = max(ans, l[i]) + t[i];
        }
        else{
            int ra, rr;
            j = 1;
            ra = 0;
            rr = INF;
            while(j < MAXN){
                push(j);
                j = j*2+1;
                if(max(a[j].maxa, ra) < min(rr, a[j].minr)){
                    ra = max(a[j].maxa, ra);
                    rr = min(a[j].minr, rr);
                    j--;
                }
            }
            T temp = get(j);
            int move = max(temp.maxa, min(temp.minr, a[j].maxa));
            if(max(ans - move, l[i])+t[i] > r[i] || max(ans - move, l[i])+t[i] >= ans){
                put(-1);
                continue;
            }
            move = min(move, ans - l[i]);
            j = 1;
            while(j < MAXN){
                j = j*2+1;
                if(a[j].maxa < move)
                    j--;
            }
            put(j-MAXN);
            temp = get(j);
            move = min(temp.minr, a[j].maxa);
            ans -= move;
            modify(j-MAXN, T(0, INF));
            while(j != 1){
                if(~j&1)
                    setDel(j+1, move);
                j >>= 1;
                com(j);
            }
            modify(i, T(t[i], max(ans, l[i])-l[i]));
            ans = max(ans, l[i]) + t[i];
        }
    }
    printf("\n");
    return 0;
}