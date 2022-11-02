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

const int MAXN = 1e5 + 5;
const int MAXM = 4e6 + 5;
const int ha = 1e9 + 7;
const int inv2 = (ha+1)/2;

int n,q;
char s0[MAXN],t[MAXN],s[MAXM],w[MAXM];
int sm[MAXN][26],f[MAXN],pw[MAXN],ipw[MAXN];

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

inline void build(int d,int l,int r){
    assert(f[d] == r-l+1);
    if(d == 0){
        FOR(i,1,f[0]) s[i+l-1] = s0[i];
        return;
    }
    build(d-1,l,l+f[d-1]-1);
    s[l+f[d-1]] = t[d];
    FOR(i,l+f[d-1]+1,l+f[d]-1) s[i] = s[i-f[d-1]-1];
}

int nxt[MAXM];

inline void kmp(char t[],int lent){
    int j = 0;nxt[1] = 0;
    FOR(i,2,lent){
        while(j && t[i] != t[j+1]) j = nxt[j];
        if(t[i] == t[j+1]) ++j;
        nxt[i] = j;
    }
}

inline int count(char s[],char t[],int lens,int lent,int l=1,int r=1e9){// O(lens+lent)
    int j = 0;int res = 0;
    FOR(i,1,lens){
        while(j && s[i] != t[j+1]) j = nxt[j];
        if(s[i] == t[j+1]) ++j;
        if(j == lent) res += (l <= i && i <= r),j = nxt[j];
    }
    return res;
}

inline void work(){
    int n;scanf("%d",&n);
    scanf("%s",w+1);int lenw = strlen(w+1);
    int ps = 0;
    while(ps <= n && f[ps] < lenw){
        f[ps+1] = f[ps]*2+1;
        ++ps;
    }
    f[ps+1] = f[ps]*2+1;
    if(ps > n){
        puts("0");
        return;
    }
    int lens = f[ps];
    build(ps,1,lens);kmp(w,lenw);
    int ans = 1ll*count(s,w,lens,lenw)*pw[n-ps]%ha;
    if(ps != n){
        ++ps;lens = f[ps];build(ps,1,lens);
        int res = 0;
        FOR(i,0,25){
            int c = sm[n][i];add(c,ha-sm[ps-1][i]);
            if(!c) continue;
            s[f[ps-1]+1] = 'a'+i;
//            FOR(i,1,lens) putchar(s[i]);puts("");
            c = 1ll*c*count(s,w,lens,lenw,f[ps-1]+1,f[ps-1]+lenw)%ha;
            add(res,c);
        }
        res = 1ll*res*pw[n]%ha;
        add(ans,res);
    }
    printf("%d\n",ans);
}

int main(){
    pw[0] = 1;FOR(i,1,MAXN-1) pw[i] = 2ll*pw[i-1]%ha;
    ipw[0] = 1;FOR(i,1,MAXN-1) ipw[i] = 1ll*ipw[i-1]*inv2%ha;
    scanf("%d%d",&n,&q);
    scanf("%s%s",s0+1,t+1);f[0] = strlen(s0+1);
    FOR(i,1,n){
        memcpy(sm[i],sm[i-1],sizeof(sm[i]));
        add(sm[i][t[i]-'a'],ipw[i]);
    }
    while(q--) work();
    return 0;
}