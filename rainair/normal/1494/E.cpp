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
int n,m;
std::map<P<int,int>,char> S;
std::map<P<char,char>,int> G[MAXN];
int cnt[MAXN];
int c1 = 0,c2 = 0;
bool can[MAXN];

inline void recalc(int v){
    c2 -= can[v];
    can[v] = cnt[v]>0;
    c2 += can[v];
}

int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        char s[23];scanf("%s",s);
        if(s[0] == '+'){
            int u,v;char t[23];scanf("%d%d%s",&u,&v,t);
            char c = t[0];
            S[MP(u,v)] = c;
            if(S.count(MP(v,u))){
                char tmp = S[MP(v,u)];
                int x = ++G[u][MP(c,tmp)],y = ++G[v][MP(tmp,c)];
                if(x == 2) ++cnt[u];
                if(y == 2) ++cnt[v];
                ++c1;
                if(tmp == c) ++c2;
            }
//            recalc(u);recalc(v);
        }
        if(s[0] == '-'){
            int u,v;scanf("%d%d",&u,&v);
            char c = S[MP(u,v)];
            if(S.count(MP(v,u))){
                char tmp = S[MP(v,u)];
                int x = --G[u][MP(c,tmp)],y = --G[v][MP(tmp,c)];
                if(!x) G[u].erase(MP(c,tmp));
                if(!y) G[v].erase(MP(tmp,c));
                if(x == 1) --cnt[u];
                if(y == 1) --cnt[v];
                --c1;
                if(tmp == c) --c2;
            }
            S.erase(MP(u,v));
//            recalc(u);recalc(v);
        }
        if(s[0] == '?'){
            int k;scanf("%d",&k);
            if(k&1) puts(c1?"YES":"NO");
            else puts(c2?"YES":"NO");
        }
    }
    return 0;
}