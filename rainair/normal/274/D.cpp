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
#define P std::pair<int,int>
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5+5;

std::vector<int> G[MAXN];
int n,m;
std::map<P,int> S;//<<,>,>
int cnt;
std::vector<int> a[MAXN];
int in[MAXN];

inline void add(int u,int v){
    G[u].pb(v);in[v]++;
}

std::vector<int> ans;
std::queue<int> q;

int main(){
    scanf("%d%d",&n,&m);cnt = m+1;
    FOR(i,1,n){
        FOR(j,1,m){
            int x;scanf("%d",&x);if(x == -1) continue;
            if(!S[MP(i,x)]){
                a[i].pb(x);
                S[MP(i,x)] = cnt;cnt += 2;
            }
            add(S[MP(i,x)],j);add(j,S[MP(i,x)]+1);
        }
    }
    FOR(i,1,n){
        std::sort(all(a[i]));
        FOR(j,1,(int)a[i].size()-1){
            add(S[MP(i,a[i][j-1])]+1,S[MP(i,a[i][j])]);
        }
    }
    FOR(i,1,cnt) if(!in[i]) q.push(i);
    while(!q.empty()){
        int v = q.front();q.pop();ans.pb(v);
        for(auto x:G[v]){
            if(!--in[x]){
                q.push(x);
            }
        }
    }
    if(ans.size() != cnt) puts("-1");
    else for(auto x:ans) if(x <= m) printf("%d ",x);
    return 0;
}