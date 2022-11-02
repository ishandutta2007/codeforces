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
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e6 + 5;
int n;

struct PAM{
    int ch[MAXN][26],fail[MAXN];
    int las,tot,rt0,rt1;
    int len[MAXN],sz[MAXN];
    char str[MAXN];

    inline void init(){
        FOR(i,1,tot) {fail[i] = 0;str[i] = 0;FOR(j,0,25) ch[i][j] = 0;}
        tot = 0;
        rt0 = ++tot;rt1 = ++tot;
        len[rt0] = 0;len[rt1] = -1;
        fail[rt0] = fail[rt1] = rt1;las = rt1;
    }
    PAM(){tot = 0;init();}

    inline int insert(int p,int lim){
        int v = las,c = str[p]-'a';
        while(str[p-len[v]-1] != str[p]) v = fail[v];
        if(!ch[v][c]){
            ++tot;len[tot] = len[v]+2;int t = fail[v];
            while(str[p-len[t]-1] != str[p]) t = fail[t];
            fail[tot] = ch[t][c];if(!fail[tot]) fail[tot] = rt0;
            ch[v][c] = tot;sz[tot] = sz[fail[tot]]+1;
        }
        las = ch[v][c];
        int ans = las;
        while(ans > 2 && len[ans] > lim) ans = fail[ans];
        return len[ans];
    }
}pam;

int pre[MAXN],suf[MAXN];
char str[MAXN];

inline void Solve(){
    pam.init();
    scanf("%s",str+1);n = strlen(str+1);
    if(n == 1){
        printf("%s\n",str+1);
        return;
    }
    int ans = 0,ps = -1;
    FOR(i,1,n){
        if(str[i] != str[n-i+1]) break;
        int gx = 2*i;
        if(2*i > n) break;
        if(ans < gx){
            ans = gx;
            ps = i;
        }
    }
    FOR(i,1,n) pam.str[i] = str[i];
    FOR(i,1,n){
        suf[i] = pam.insert(i,(i==n-ps) ? n-2*(n-i) : 1e9);
    }
    pam.init();
    FOR(i,1,n) pam.str[i] = str[i];std::reverse(pam.str+1,pam.str+n+1);
    FOR(i,1,n) pre[i] = pam.insert(i,(n-i+1 == ps+1) ? n-2*(n-i) : 1e9);
    std::reverse(pre+1,pre+n+1);
    if(ps != -1) ans += std::max(pre[ps+1],suf[n-ps]);
    if(ans < pre[1]) ans = pre[1],ps = -2;
    if(ans < suf[n]) ans = suf[n],ps = -3;
    if(ps == -2){
        FOR(i,1,pre[1]) putchar(str[i]);puts("");
        return;
    }
    if(ps == -3){
        ROF(i,n,n-suf[n]+1) putchar(str[i]);puts("");
        return;
    }
    FOR(i,1,ps) putchar(str[i]);
    if(pre[ps+1] > suf[n-ps]){
        FOR(i,ps+1,ps+pre[ps+1]) putchar(str[i]);
    }
    else{
        ROF(i,n-ps,n-ps-suf[n-ps]+1) putchar(str[i]);
    }
    ROF(i,ps,1) putchar(str[i]);puts("");
    FOR(i,0,n+1) pre[i] = suf[i] = 0;
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}