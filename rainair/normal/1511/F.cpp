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

const int MAXN = 8 + 5;
const int MAXM = 168 + 5;
const int ha = 998244353;

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

int N;
struct Matrix{
    int a[MAXM][MAXM];
    Matrix(){CLR(a,0);}
    inline int* operator [] (const int &n){return a[n];}
    inline const int* operator [] (const int &n) const {return a[n];}
    
    Matrix operator * (const Matrix &t) const {
        Matrix res;
        FOR(i,0,N-1) FOR(j,0,N-1) FOR(k,0,N-1) add(res.a[i][j],1ll*a[i][k]*t.a[k][j]%ha);
        return res;
    }
}A;

Matrix qpow(Matrix a,int n){
    Matrix res;FOR(i,0,N-1) res.a[i][i] = 1;
    while(n){
        if(n&1) res = res*a;
        a = a*a;
        n >>= 1;
    }
    return res;
}

int n,m;
int ch[MAXM][26],tot=1;
int id[MAXM][MAXM];
char str[MAXN];
bool vis[MAXM];

inline void insert(char str[]){
    int len = strlen(str+1),v = 1;
    FOR(i,1,len){
        int o = str[i]-'a';
        if(!ch[v][o]) ch[v][o] = ++tot;
        v = ch[v][o];
    }
    vis[v] = 1;
}

inline void upd(int x,int y){// x -> y
    add(A[y][x],1);
}

inline int gao(int x,int y){
    if(x > y) std::swap(x,y);
    if(id[x][y] != -1) return id[x][y];
    id[x][y] = N++;int v = id[x][y];
    FOR(i,0,25){
        if(ch[x][i] && ch[y][i]){
            int xx = ch[x][i],yy = ch[y][i];
            upd(v,gao(xx,yy));
            if(vis[xx]) upd(v,gao(1,yy));
            if(vis[yy]) upd(v,gao(xx,1));
            if(vis[xx] && vis[yy]) upd(v,gao(1,1));
        }
    }
    return v;
}

int main(){
    scanf("%d%d",&n,&m);
    CLR(id,-1);
    FOR(i,1,n){
        scanf("%s",str+1);
        insert(str);
    }
    gao(1,1);
    A = qpow(A,m);
    printf("%d\n",A[0][0]);
    return 0;
}