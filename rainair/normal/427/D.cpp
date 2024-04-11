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

int ch[MAXN][26],fail[MAXN],len[MAXN],sz1[MAXN],sz2[MAXN],tot=1;

inline int work(int p,int c){
    int q = ch[p][c],nq = ++tot;
    FOR(i,0,25) ch[nq][i] = ch[q][i];len[nq] = len[p]+1;fail[nq] = fail[q];
    fail[q] = nq;for(;p&&ch[p][c]==q;p=fail[p]) ch[p][c] = nq;
    return nq;
}

inline int insert(int p,int c){
    int q = ch[p][c];
    if(q){
        if(len[q] == len[p]+1) return q;
        return work(p,c);
    }
    int np = ++tot;len[np] = len[p]+1;
    for(;p&&!ch[p][c];p=fail[p]) ch[p][c] = np;
    if(!p) fail[np] = 1;
    else{
        q = ch[p][c];
        if(len[q] == len[p]+1) fail[np] = q;
        else fail[np] = work(p,c);
    }
    return np;
}

char s1[MAXN],s2[MAXN];
int n,m;
int t[MAXN],sa[MAXN];

int main(){
    scanf("%s%s",s1+1,s2+1);n = strlen(s1+1);m = strlen(s2+1);
    int p = 1;
    FOR(i,1,n) p=insert(p,s1[i]-'a'),++sz1[p];
    p = 1;
    FOR(i,1,m) p=insert(p,s2[i]-'a'),++sz2[p];
    FOR(i,1,std::max(n,m)) t[i] = 0;
    FOR(i,1,tot) ++t[len[i]];
    FOR(i,1,std::max(n,m)) t[i] += t[i-1];
    FOR(i,1,tot) sa[t[len[i]]--] = i;
    int ans = 1e9;
    ROF(i,tot,1){
        int v = sa[i];if(v == 1) continue;
        if(sz1[v] == 1 && sz2[v] == 1) ans = std::min(ans,len[fail[v]]+1);
        sz1[fail[v]] += sz1[v];
        sz2[fail[v]] += sz2[v];
    }
    if(ans == 1e9) ans = -1;
    printf("%d\n",ans);
    return 0;
}
//