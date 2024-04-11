#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 4e5 + 5;
int ch[MAXN][26],fail[MAXN],len[MAXN],tot=1,las=1,r[MAXN];

inline int work(int p,int c){
    int q = ch[p][c],nq = ++tot;
    FOR(i,0,25) ch[nq][i] = ch[q][i];len[nq] = len[p]+1;fail[nq] = fail[q];
    fail[q] = nq;for(;p&&ch[p][c]==q;p=fail[p]) ch[p][c] = nq;
    return nq;
}

inline int insert(int c){
    int p = las,np = las = ++tot;len[np] = len[p]+1;
    for(;p&&!ch[p][c];p=fail[p]) ch[p][c] = np;
    if(!p) fail[np] = 1;
    else{
        int q = ch[p][c];
        if(len[q] == len[p]+1) fail[np] = q;
        else fail[np] = work(p,c);
    }
    return np;
}

int n;char str[MAXN];

bool sm[MAXN<<5];int lc[MAXN<<5],rc[MAXN<<5],cnt,rt[MAXN];

inline void insert(int &x,int l,int r,int p){
    sm[x = ++cnt] = 1;
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(p <= mid) insert(lc[x],l,mid,p);
    else insert(rc[x],mid+1,r,p);
}

inline int merge(int x,int y,int l,int r){
    if(!x || !y) return x|y;
    int v = ++cnt;
    if(l == r){
        sm[v] = sm[x]|sm[y];
        return v;
    }
    int mid = (l + r) >> 1;
    lc[v] = merge(lc[x],lc[y],l,mid);
    rc[v] = merge(rc[x],rc[y],mid+1,r);
    sm[v] = sm[lc[v]]|sm[rc[v]];
    return v;
}

inline bool query(int x,int l,int r,int L,int R){
    if(!x) return 0;
    if(l == L && r == R) return sm[x];
    int mid = (l + r) >> 1;
    if(R <= mid) return query(lc[x],l,mid,L,R);
    if(L > mid) return query(rc[x],mid+1,r,L,R);
    return query(lc[x],l,mid,L,mid)|query(rc[x],mid+1,r,mid+1,R);
}

int t[MAXN],sa[MAXN];
int f[MAXN],ps[MAXN];

int main(){
    scanf("%d%s",&n,str+1);
    FOR(i,1,n){
        int v = insert(str[i]-'a');
        insert(rt[v],1,n,i);r[v] = i;
    }
    FOR(i,1,tot) ++t[len[i]];
    FOR(i,1,n) t[i] += t[i-1];
    FOR(i,1,tot) sa[t[len[i]]--] = i;
    ROF(i,tot,1){
        int v = sa[i];
        rt[fail[v]] = merge(rt[fail[v]],rt[v],1,n);
        r[fail[v]] = r[v];
    }
    FOR(i,2,tot){
        int v = sa[i];
        if(fail[v] == 1){
            f[v] = 1;
            ps[v] = v;
        }
        else{
            if(query(rt[ps[fail[v]]],1,n,r[v]-len[v]+len[ps[fail[v]]],r[v]-1)){
                f[v] = f[fail[v]]+1;
                ps[v] = v;
            }
            else{
                f[v] = f[fail[v]];
                ps[v] = ps[fail[v]];
            }
        }
    }
    printf("%d\n",*std::max_element(f+1,f+tot+1));
    return 0;
}