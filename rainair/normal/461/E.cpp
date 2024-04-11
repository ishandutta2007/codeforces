#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
const LL MAX = 4e18;
LL n;
char s[MAXN];
int ch[MAXN][4],len[MAXN],fail[MAXN],tot=1;

inline int work(int p,int c){
    int q = ch[p][c],nq = ++tot;
    memcpy(ch[nq],ch[q],sizeof(ch[q]));
    len[nq] = len[p]+1;fail[nq] = fail[q];
    fail[q] = nq;
    for(;p&&ch[p][c]==q;p=fail[p]) ch[p][c] = nq;
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

LL A[5][5];
bool vis[MAXN];
int dis[MAXN];

inline void gao(int v,int now){
    std::queue<int> q;q.push(v);vis[v] = 1;dis[v] = 1;
    while(!q.empty()){
        int v = q.front();q.pop();
        FOR(i,0,3){
            if(ch[v][i]){
                if(!vis[ch[v][i]]) q.push(ch[v][i]),vis[ch[v][i]] = 1,dis[ch[v][i]] = dis[v]+1;
            }
            else{
                A[now][i+1] = std::min(A[now][i+1],(LL)dis[v]);
            }
        }
    }
}

struct Matrix{
    LL a[5][5];
    Matrix operator * (const Matrix &t){
        Matrix res;
        FOR(i,1,4){
            FOR(j,1,4){
                res.a[i][j] = 4e18;
                FOR(k,1,4){
                    res.a[i][j] = std::min(res.a[i][j],a[i][k]+t.a[k][j]);
                    if(res.a[i][j] > 4e18) res.a[i][j] = 4e18;
                }
            }
        }
        return res;
    }
}pw[60];

inline LL calc(Matrix A){
    LL res = 4e18;
    FOR(i,1,4) FOR(j,1,4) res = std::min(res,A.a[i][j]);
    return res;
}

int main(){
    scanf("%lld%s",&n,s+1);int len = strlen(s+1);
    int p = 1;FOR(i,1,len) p = insert(p,s[i]-'A');
    FOR(i,1,4) FOR(j,1,4) A[i][j] = 4e18;
    FOR(i,0,3) if(ch[1][i]) CLR(vis,0),gao(ch[1][i],i+1);// dag
    --n;
    FOR(i,1,4) FOR(j,1,i-1) std::swap(A[i][j],A[j][i]);
    FOR(i,1,4) FOR(j,1,4) pw[0].a[i][j] = A[i][j];
    FOR(i,1,59) pw[i] = pw[i-1]*pw[i-1];

    Matrix now;LL ans = 0;
    FOR(i,1,4) FOR(j,1,4) now.a[i][j] = i==j?0:4e18;

//    FOR(i,1,4) FOR(j,1,4) printf("%lld%c",pw[0].a[i][j]," \n"[j==4]);
    ROF(i,59,0){
        Matrix tmp = now*pw[i];
        if(calc(tmp) > n) continue;
        now = tmp;ans |= (1ll<<i);
    }
    printf("%lld\n",ans+1);
    return 0;
}