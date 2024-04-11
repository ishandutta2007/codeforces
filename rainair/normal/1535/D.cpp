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

const int MAXN = 1e6 + 5;

int k,n;
char str[MAXN];

std::vector<P<int,int> > G[MAXN];
int sm[MAXN],tsm[MAXN];

inline void pushup(int v){
    if((v<<1) >= n){
        sm[v] = 1+(str[v]=='?');
        return;
    }
    if(str[v] == '0') sm[v] = sm[v<<1|1];
    else if(str[v] == '1') sm[v] = sm[v<<1];
    else sm[v] = sm[v<<1]+sm[v<<1|1];
}

inline void dfs(int v){
    if((v<<1) < n){
        dfs(v<<1);
        dfs(v<<1|1);
    }
    pushup(v);
}

int main(){
    scanf("%d",&k);n = (1<<k);
    scanf("%s",str+1);
    std::reverse(str+1,str+n);
    dfs(1);
    int q;scanf("%d",&q);
    while(q--){
        int p;char ss[5],c;scanf("%d%s",&p,ss);c = ss[0];
        p = n-p;str[p] = c;
        while(p){
            pushup(p);
            p >>= 1;
        }
        printf("%d\n",sm[1]);
    }
    return 0;
}