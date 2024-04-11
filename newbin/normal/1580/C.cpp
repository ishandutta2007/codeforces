#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define pb push_back
#define all(a) a.begin(),a.end()
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 2e5+5;
const int B = 450;
int n, m;
int x[maxn], y[maxn];
int a[maxn];
int b[B][B];
int cur = 0;
int pre[maxn];
void add(int id){
    int len = x[id]+y[id];
    pre[id] = cur;
    if(len < B){
        int p = (cur+x[id])%len;
        for(int i = 0; i < y[id]; ++i){
            b[len][p]++; p++;
            if(p >= len) p -= len;
        }
    }else{
        int l = cur+x[id], r = cur+len;
        while(l <= m){
            a[l]++; a[ min(r,m+1) ]--;
            l += len; r += len;
        }
    }
    return;
}
void del(int id){
    int len = x[id]+y[id];
    if(len < B){
        int p = (pre[id]+x[id])%len;
        for(int i = 0; i < y[id]; ++i){
            b[len][p]--; p++;
            if(p >= len) p -= len;
        }
    }else{
        int l = pre[id]+x[id], r = pre[id]+len;
        while(l <= m){
            if(r >= cur){
                a[max(l,cur)]--;
                a[ min(r,m+1) ]++;
            }
            l += len; r += len;
        }
    }
    return;
}
int main(){
    scanf("%d%d", &n, &m);
    fors(i,0,n) scanf("%d%d", &x[i], &y[i]);
    for(int i = 0; i < m; ++i){
        int op, x;
        scanf("%d%d", &op, &x);
        x--;
        if(op == 1) add(x);
        else del(x);
//        cout<<"a:"<<a[cur]<<" pre:"<<a[cur-1]<<endl;
        a[cur] += a[cur-1];

        int ans = a[cur];
        for(int j = 1; j < B; ++j) ans += b[j][i%j];
        printf("%d\n", ans);
        cur++;
    }
    return 0;
}
/*
2 100
2 3
10000 1

1 1
1 2
2 2
1 2
2 2
1 2
2 2
1 2
2 2
*/