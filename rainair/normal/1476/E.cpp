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

const int MAXN = 1e5 + 5;
int n,m,k;
std::map<std::string,int> S;
int p[MAXN],deg[MAXN];
std::vector<int> G[MAXN];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    FOR(i,1,n){
        std::string str;std::cin >> str;
        S[str] = i;
    }
    FOR(i,1,m){
        std::string str;int x;
        std::cin >> str >> x;
        bool flag = 0;
        FOR(_,0,(1<<k)-1){
            std::string tmp = str;
            FOR(i,0,k-1){
                if((_>>i)&1) tmp[i] = '_';
            }
            if(S.find(tmp) != S.end()){
                int id = S[tmp];
                if(id == x) flag = 1;
                else G[x].pb(id),++deg[id];
            }
        }
        if(!flag){
            puts("NO");
            return 0;
        }
    }
    std::queue<int> q;FOR(i,1,n) if(!deg[i]) q.push(i);
    int now = 0;
    while(!q.empty()){
        int v = q.front();q.pop();p[++now] = v;
        for(auto x:G[v]){
            if(!--deg[x]) q.push(x);
        }
    }
    if(now != n){
        puts("NO");
        return 0;
    }
    puts("YES");
    FOR(i,1,n) printf("%d%c",p[i]," \n"[i==n]);
    return 0;
}