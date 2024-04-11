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

const int MAXN = 1e5 + 5;

int n,x,y;
int a[MAXN],b[MAXN];
int cnt[MAXN];
std::vector<int> G[MAXN];

inline void chk(){
    int xx=0,yy=0;
    FOR(i,1,n) if(a[i] == b[i]) ++xx;
    FOR(i,1,n+1) cnt[i] = 0;
    FOR(i,1,n) cnt[a[i]]++;
    FOR(i,1,n) if(cnt[b[i]]) ++yy,cnt[b[i]]--;
    if(xx == x && yy == y){
        puts("YES");
        FOR(i,1,n) printf("%d ",b[i]);
        puts("");
    }
    else puts("NO");
}

inline void Solve(){
    scanf("%d%d%d",&n,&x,&y);
    FOR(i,1,n+1) cnt[i] = b[i] = 0,G[i].clear();
    FOR(i,1,n) scanf("%d",a+i),++cnt[a[i]],G[a[i]].pb(i);
    int ext = 0;FOR(i,1,n+1) if(!cnt[i]){ext = i;break;}
    std::priority_queue<P> q;FOR(i,1,n+1) if(cnt[i]) q.push(MP(cnt[i],i));
    FOR(i,1,x){
        P v = q.top();q.pop();
        v.fi--;b[G[v.se].back()] = v.se;G[v.se].pop_back();
        if(v.fi) q.push(v);
    }
    std::vector<int> A;
    std::vector<P> B;
    FOR(i,1,n) if(!b[i]) A.pb(a[i]),B.pb(MP(a[i],i));std::sort(all(A));std::sort(all(B));
    int m = A.size(),t1 = A.size()/2;int ty = y-x;
    for(auto x:B){
        if(a[x.se] == A[t1] || !ty){
            b[x.se] = ext;
        }
        else{
            ty--;b[x.se] = A[t1];
        }
        ++t1;t1 %= m;
    }
    chk();
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}