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

const int MAXN = 2e5 + 5;
char str[MAXN];int n;

int ch[MAXN][26],fail[MAXN],len[MAXN],sz[MAXN],las=1,tot=1;

inline int work(int p,int c){
    int q = ch[p][c],nq = ++tot;
    FOR(i,0,25) ch[nq][i] = ch[q][i];fail[nq] = fail[q];len[nq] = len[p]+1;
    fail[q] = nq;for(;p&&ch[p][c]==q;p=fail[p]) ch[p][c] = nq;
    return nq;
}

inline void insert(int c){
    int p = las,np = las = ++tot;len[np] = len[p]+1;sz[np] = 1;
    for(;p&&!ch[p][c];p=fail[p]) ch[p][c] = np;
    if(!p) fail[np] = 1;
    else{
        int q = ch[p][c];
        if(len[q] == len[p]+1) fail[np] = q;
        else fail[np] = work(p,c);
    }
}

int sa[MAXN],t[MAXN];

int main(){
    scanf("%s",str+1);n = strlen(str+1);
    FOR(i,1,n) insert(str[i]-'a');
    FOR(i,1,tot) ++t[len[i]];
    FOR(i,1,n) t[i] += t[i-1];
    FOR(i,1,tot) sa[t[len[i]]--] = i;
    LL ans = 0;
    ROF(i,tot,1){
        int v = sa[i];
        ans += 1ll*sz[v]*(sz[v]+1)*(len[v]-len[fail[v]])/2;
        sz[fail[v]] += sz[v];
    }
    printf("%lld\n",ans);
    return 0;
}