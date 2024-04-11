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

int n,k;

int x[MAXN],y[MAXN];

inline LL dis2(int a,int b){
    return 1ll*(x[a]-x[b])*(x[a]-x[b])+1ll*(y[a]-y[b])*(y[a]-y[b]);
}

std::map<std::pair<int,int>,int> S;
int tot;

inline int id(P x){
    if(!S.count(x)) S[x] = ++tot;
    return S[x];
}

std::vector<int> G[MAXN];

inline bool cmp(int x,int y){
    return dis2(0,x) < dis2(0,y);
}

int main(){
    scanf("%d%d",&n,&k);tot = 2;
    FOR(i,1,n){
        scanf("%d%d",x+i,y+i);
        if(!(x[i]==0&&y[i]==0)){
            //  gcd 
            int g = std::__gcd(std::abs(x[i]),std::abs(y[i]));
            G[id(MP(x[i]/g,y[i]/g))].pb(i);
        }
    }
    std::vector<double> S;S.pb(0);
    FOR(i,1,tot){
        if(G[i].empty()) continue;
        std::sort(all(G[i]),cmp);
        int t = std::min((int)G[i].size(),(k+1)>>1);
        FOR(j,1,t){
            S.pb(std::sqrt(1.0*dis2(0,G[i].back()))*(k-2*j+1));
            G[i].pop_back();
        }
        double sm = 0;
        FOR(j,0,(int)G[i].size()-1){
            S.pb(std::sqrt(1.0*dis2(0,G[i][j]))*(k-2*(t+1)+1)-sm*2);
            sm += std::sqrt(1.0*dis2(0,G[i][j]));
        }
    }
    std::sort(all(S));std::reverse(all(S));
    double ans = 0;FOR(i,0,k-1) ans += S[i];
    printf("%.10f\n",ans);
    return 0;
}