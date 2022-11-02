#include <bits/stdc++.h>

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

const int ha = 1e9 + 7;
const int MAXN = 5e5 + 5;

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

int n,m;
int c[MAXN][3];
std::vector<int> ps[MAXN];

#define abs(x) ((x) > 0 ? (x) : (-(x)))
std::vector<int> G[MAXN];
bool vis[MAXN];
int g[MAXN][2],tot;
std::vector<int> S;

inline void dfs(int v){
    vis[v] = 1;S.pb(v);
    for(auto x:G[v]){
        if(vis[x]) continue;
        dfs(x);
    }
}

int f[MAXN][2][2];

inline void work(int v){
    ++tot;S.clear();dfs(v);
    if(S.size() == 1){
        if(G[v].empty()){
            if(c[v][0] == 1) g[tot][0] = g[tot][1] = 1;
            else g[tot][0] = 1,g[tot][1] = 3;
        }
        else{
            assert(G[v].size() == 2 && G[v][0] == v);
            assert(c[v][0] == 2);
            if(c[v][1] == c[v][2]){
                g[tot][0] = g[tot][1] = 1;
            }
            else{
                g[tot][1] = 2;
            }
        }
        return;
    }
    for(auto x:S){
        if(G[x].size() == 1) v = x;
    }
    for(auto x:S) vis[x] = 0;
    S.clear();dfs(v);
    if(c[v][0] == 1) c[v][0] = 2,c[v][2] = c[v][1];
    if(abs(c[v][2]) != abs(c[S[1]][1]) && abs(c[v][2]) != abs(c[S[1]][2])){
        assert(c[v][0] == 2);
        std::swap(c[v][1],c[v][2]);
        assert(abs(c[v][2]) == abs(c[S[1]][1]) || abs(c[v][2]) == abs(c[S[1]][2]));
    }
    FOR(i,1,(int)S.size()-1){
        if(abs(c[S[i]][1]) != abs(c[S[i-1]][2])) std::swap(c[S[i]][1],c[S[i]][2]);
    }
    bool circle = abs(c[S.back()][2]) == abs(c[v][1]);
    // c[S[i-1]] 
    //  i  
    int sz = (int)S.size()-1;
    auto reset = [&](){
        FOR(i,0,sz) FOR(j,0,1) FOR(k,0,1) f[i][j][k] = 0;
    };

    auto dp = [&](){
        FOR(i,0,sz-1){
            FOR(j,0,1){
                FOR(x,0,1){
                    if(!f[i][j][x]) continue;
                    if(c[S[i+1]][0] == 1){
                        assert(i+1==sz);
                        add(f[i+1][j^(x^(c[S[i+1]][1]<0))][x],f[i][j][x]);
                        continue;
                    }
                    FOR(y,0,1){
                        add(f[i+1][j^((x^(c[S[i+1]][1]<0))|(y^(c[S[i+1]][2]<0)))][y],f[i][j][x]);
                    }
                }
            }
        }
    };
    
    int o = c[v][2] < 0;
    if(!circle){
        reset();
        if(c[v][1] == c[v][2]) f[0][0][o] = f[0][1][!o] = 1;
        else{
            f[0][0][o] = 1;
            f[0][1][o] = 1;
            f[0][1][!o] = 2;
        }
        dp();
        FOR(i,0,1) FOR(j,0,1) add(g[tot][i],f[sz][i][j]);
//        DEBUG(g[1][0]);DEBUG(g[1][1]);
    }
    else{
        reset();
        // c[v][1]: 0
        if(c[v][1] == c[v][2]) f[0][o][0] = 1;
        else{
            if(c[v][1] > 0) f[0][0][o] = f[0][1][!o] = 1;
            else f[0][1][0] = f[0][1][1] = 1;
        }
        dp();
        FOR(i,0,1) add(g[tot][i],f[sz][i][0]);
        reset();
        // c[v][1]:1
        if(c[v][1] == c[v][2]) f[0][!o][1] = 1;
        else{
            if(c[v][1] < 0) f[0][0][o] = f[0][1][!o] = 1;
            else f[0][1][0] = f[0][1][1] = 1;
        }
        dp();
        FOR(i,0,1) add(g[tot][i],f[sz][i][1]);
    }
}

int main(){
    scanf("%d%d",&m,&n);
    FOR(i,1,m){
        scanf("%d",&c[i][0]);
        FOR(j,1,c[i][0]) scanf("%d",&c[i][j]),ps[abs(c[i][j])].pb(i);
    }
    int coe = 1;
    FOR(i,1,n) if(ps[i].size() == 2) G[ps[i][0]].pb(ps[i][1]),G[ps[i][1]].pb(ps[i][0]);
    FOR(i,1,n) if(ps[i].empty()) coe = 2ll*coe%ha;
    // g[i][0/1]:  0/1
    FOR(i,1,m){
        if(!vis[i]){
            work(i);
        }
    }
    int ans0=g[1][0],ans1=g[1][1];
    FOR(i,2,tot){
        int new_ans0=0,new_ans1=0;
        add(new_ans0,1ll*ans0*g[i][0]%ha);
        add(new_ans0,1ll*ans1*g[i][1]%ha);
        add(new_ans1,1ll*ans0*g[i][1]%ha);
        add(new_ans1,1ll*ans1*g[i][0]%ha);
        ans0 = new_ans0;
        ans1 = new_ans1;
    }
    ans1 = 1ll*ans1*coe%ha;
    printf("%d\n",ans1);
    return 0;
}