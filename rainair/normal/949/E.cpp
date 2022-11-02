#include<bits/stdc++.h>

#define fi first
#define se second
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

const int MAXN = 1e5 + 5;

int n;
std::vector<int> S,ans,now;

inline void dfs(std::vector<int> S,int step=0){
    if(step > 20) return;
    S.erase(std::unique(all(S)),S.end());
    if(S.size() == 1 && !S[0]){
        if(!ans.size() || ans.size() > now.size()) ans = now;
        return;
    }
    bool fg = 1,po = 1,ne = 1;
    for(auto x:S) if(x&1){fg = 0;break;}
    std::vector<int> t = S;
    if(fg){
        for(auto &x:S) x >>= 1;
        dfs(S,step+1);
    }
    else{
        if(po){
            S = t;
            for(auto &x:S){
                if(x&1) --x;
                x >>= 1;
            }
            now.pb(1<<step);
            dfs(S,step+1);
            now.pop_back();
        }
        if(ne){
            S = t;
            for(auto &x:S){
                if(x&1) ++x;
                x >>= 1;
            }
            now.pb(-(1<<step));
            dfs(S,step+1);
            now.pop_back();
        }
    }
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n){
        int x;scanf("%d",&x);S.pb(x);
    }
    std::sort(all(S));
    dfs(S);
    printf("%ld\n",ans.size());
    for(auto x:ans) printf("%d ",x);puts("");
    return 0;
}