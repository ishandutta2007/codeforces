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

const int MAXN = 1e5 + 5;
int n,deg[MAXN],s[MAXN];
std::queue<int> q;

int main(){
    scanf("%d",&n);int sm = 0;
    FOR(i,0,n-1) scanf("%d%d",deg+i,s+i),sm += deg[i];
    FOR(i,0,n-1) if(deg[i] == 1) q.push(i);
    sm >>= 1;printf("%d\n",sm);
    while(!q.empty()){
        int v = q.front();q.pop();
        if(!deg[v]) continue;
        printf("%d %d\n",v,s[v]);
        s[s[v]] ^= v;--deg[s[v]];
        if(deg[s[v]] == 1) q.push(s[v]);
    }
    return 0;
}