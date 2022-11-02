/*
 * Author: RainAir
 * Time: 2019-11-06 20:54:44
 */
#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 500+5;
const int MAXM = MAXN*MAXN;

int ch[MAXM][26],fail[MAXM],val[MAXM],tot = 1,rt = 1;
char str[MAXN];
int a[MAXN];

inline void insert(int now){
    int len = strlen(str+1);
    int v = rt;
    FOR(i,1,len){
        int x = str[i]-'a';
        if(!ch[v][x]) ch[v][x] = ++tot;
        v = ch[v][x];
    }
    val[v] += a[now];
}

int b[MAXN][MAXN];

inline void build(){
    std::queue<int> q;
    FOR(i,0,25){
        if(ch[1][i]){
            fail[ch[1][i]] = rt;
            q.push(ch[1][i]);
        }
        else ch[1][i] = 1;
    }
    while(!q.empty()){
        int v = q.front();q.pop();
        FOR(i,0,25){
            if(!ch[v][i]) ch[v][i] = ch[fail[v]][i];
            else{
                fail[ch[v][i]] = ch[fail[v]][i];
                val[ch[v][i]] += val[fail[ch[v][i]]];
                q.push(ch[v][i]);
            }
        }
    }
}

struct Matrix{
    int a[MAXN][MAXN];
    Matrix(){CLR(a,0);}

    Matrix operator * (const Matrix &t) const {
        Matrix res;
        FOR(i,1,tot) FOR(j,1,tot) res.a[i][j] = -1e18;
        FOR(i,1,tot){
            FOR(j,1,tot){
                FOR(k,1,tot){
                    res.a[i][j] = std::max(res.a[i][j],a[i][k]+t.a[k][j]);
                }
            }
        }
        return res;
    }
}base;

inline Matrix qpow(Matrix a,int n){
    Matrix res;
    FOR(i,1,tot) FOR(j,1,tot) res.a[i][j] = -1e18;
    FOR(i,1,tot) res.a[i][i] = 0;
    while(n){
        if(n & 1) res = res*a;
        a = a*a;
        n >>= 1;
    }
    return res;
}

signed main(){
//    freopen("a.out","w",stdout);
    int n,m;
    scanf("%lld%lld",&n,&m);
    FOR(i,1,n) scanf("%lld",a+i);
    FOR(i,1,n){
        scanf("%s",str+1);
        insert(i);
    }
    build();
    FOR(i,1,tot) FOR(j,1,tot) b[i][j] = -1e18;
    FOR(i,1,tot){
        FOR(j,0,25){
            if(ch[i][j]) b[i][ch[i][j]] = val[ch[i][j]];
        }
    }
    FOR(i,1,tot) FOR(j,1,tot) base.a[i][j] = b[i][j];
//    FOR(i,1,tot) FOR(j,1,tot) printf("%lld%c",b[i][j]," \n"[j==tot]);
    Matrix res = qpow(base,m);
/*    Matrix tt;
    FOR(i,1,tot) FOR(j,1,tot) tt.a[i][j] = -1e9;
    FOR(i,1,tot) tt.a[i][i] = 0;
    FOR(i,1,m) tt = tt*base;
    FOR(i,1,tot){
        FOR(j,1,tot) printf("%d%c",res.a[i][j]," \n"[j==tot]);
    }*/
    int ans = 0;
    FOR(i,1,tot) ans = std::max(ans,res.a[1][i]);
    printf("%lld\n",ans);
    return 0;
}