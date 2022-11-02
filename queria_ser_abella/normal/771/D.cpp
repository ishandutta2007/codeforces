#include <bits/stdc++.h>
#define maxn 100
using namespace std;

int T[maxn];
void upd(int idx,int val){
    idx++;
    while(idx < maxn){
        T[idx] += val;
        idx += idx&-idx;
    }
}

int qry(int idx){
    int r = 0;
    idx++;
    while(idx){
        r += T[idx];
        idx -= idx&-idx;
    }
    return r;
}

int n;
int dp[2][maxn][maxn][maxn];
int nxt[3][maxn];
char s[maxn];

int get(int ok,int v,int k,int x){
    int &r = dp[ok][v][k][x];
    if(v == n && k == n && x == n)
        return 0;
    if(r+1)
        return r;
    r = 1e9;
    if(v != n){
        upd(v,1);
        r = min(r,get(0,nxt[0][v],k,x)+qry(n)-qry(v));
        upd(v,-1);
    }
    if(k != n && ok){
        upd(k,1);
        r = min(r,get(1,v,nxt[1][k],x)+qry(n)-qry(k));
        upd(k,-1);
    }
    if(x != n){
        upd(x,1);
        r = min(r,get(1,v,k,nxt[2][x])+qry(n)-qry(x));
        upd(x,-1);
    }
    return r;
}

int main() {
    scanf("%d %s",&n,s);
    int v = n, k = n, x = n;
    for(int i=n-1;i>=0;i--){
        nxt[0][i] = v;
        nxt[1][i] = k;
        nxt[2][i] = x;
        if(s[i] == 'V') v = i;
        else if(s[i] == 'K') k = i;
        else x = i;
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",get(1,v,k,x));
}