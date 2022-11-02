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

const int MAXN = 500 + 5;
int k,n,m,q;
std::string name[MAXN];
std::map<std::string,int> art;
int req[MAXN][MAXN],sz[MAXN];
std::vector<int> peo[MAXN];
int now[MAXN],sa[MAXN];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin >> k >> n >> m >> q;
    FOR(i,1,n){
        std::cin >> name[i];
        art[name[i]] = i;
    }
    FOR(i,n+1,n+m){
        std::cin >> name[i];
        name[i].pop_back();
        art[name[i]] = i;
        while(true){
            std::string a,b;
            std::cin >> a >> b;
            int x = 0;
            FOR(i,0,SZ(b)-1) if(b[i] != ',') x = x*10+b[i]-'0';
            req[i][art[a]] = x;
            ++sz[i];
            if(b.back() != ',') break;
        }
    }
    std::vector<P<std::string,int> > vec;
    FOR(i,1,n+m) vec.pb(name[i],i);
    std::sort(all(vec));
    FOR(i,1,SZ(vec)) sa[i] = vec[i-1].se;
    FOR(i,1,q){
        int x;std::string str;
        std::cin >> x >> str;
        peo[x].pb(art[str]);
    }
    FOR(i,1,k){
        FOR(j,1,n+m) now[j] = 0;
        for(auto x:peo[i]){
            ++now[x];
            FOR(j,n+1,n+m){
                bool flag = 1;
                FOR(k,1,n) flag &= (req[j][k] <= now[k]);
                if(!flag) continue;
                ++now[j];
                FOR(k,1,n) now[k] -= req[j][k];
            }
        }
        int t = 0;
        FOR(j,1,n+m) t += (now[j]>0);
        std::cout << t << '\n';
        FOR(j,1,n+m) if(now[sa[j]]) std::cout << name[sa[j]] << ' ' << now[sa[j]] << '\n';
    }
    return 0;
}