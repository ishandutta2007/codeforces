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

const int MAXN = 2e5 + 5;
const int MAXM = 19;

std::set<int> S[MAXM+1];
int pc[(1<<20)+3],a[MAXN],n;
#define lowbit(x) ((x)&(-(x)))

inline void add(int x){
    FOR(i,0,MAXM) if((a[x]>>i)&1) S[i].insert(x);
}
 
inline void del(int x){
    FOR(i,0,MAXM) if((a[x]>>i)&1) S[i].erase(x);
}

int main(){
    FOR(i,0,19) pc[1<<i] = i;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),add(i);
    ROF(i,n,1){
        del(i);
        ROF(j,MAXM,0){
            if((a[i]>>j)&1) continue;
            if(S[j].empty()) continue;
            int p = *S[j].begin();
            int t1 = a[p],t2 = a[i];
            a[p] = t1&t2;a[i] = t1|t2;
            int t = (t1^t2)&t1;
            while(t){
                int bit = pc[lowbit(t)];t -= lowbit(t);
                S[bit].erase(p);
            }
        }
    }
    LL ans = 0;
    FOR(i,1,n) ans += 1ll*a[i]*a[i];
    printf("%lld\n",ans);
    return 0;
}