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

const int MAXN = 5e5 + 5;
int n,k;
LL a[MAXN];
std::vector<int> S;
std::vector<LL> SS;

struct BIT{
    #define lowbit(x) ((x)&(-(x)))
    int tree[MAXN],ts[MAXN],now;

    inline void reset(){
        ++now;
    }

    inline void add(int pos,int x){
        while(pos < MAXN){
            if(ts[pos] != now) tree[pos] = 0,ts[pos] = now;
            tree[pos] = std::max(tree[pos],x);
            pos += lowbit(pos);
        }
    }

    inline int query(int pos){
        int res = 0;if(!pos) return 0;
        while(pos){
            if(ts[pos] != now) tree[pos] = 0,ts[pos] = now;
            res = std::max(res,tree[pos]);
            pos -= lowbit(pos);
        }
        return res;
    }
}bit;

int b[MAXN];

int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    a[0] = -1e18;a[n+1] = 1e18;
    FOR(i,0,n+1) SS.pb(a[i]-i);
    std::sort(all(SS));SS.erase(std::unique(all(SS)),SS.end());
    FOR(i,0,n+1) b[i] = std::lower_bound(all(SS),a[i]-i)-SS.begin()+1;
    S.pb(0);
    FOR(i,1,k){
        int x;scanf("%d",&x);
        S.pb(x);
    }
    S.pb(n+1);
    FOR(i,1,(int)S.size()-1){
        if(a[S[i]]-a[S[i-1]] < S[i]-S[i-1]){
            puts("-1");
            return 0;
        }
    }
    int ans = 0;
    FOR(i,1,(int)S.size()-1){
        auto work = [&](int l,int r){
            bit.reset();
            int res = 0;
            FOR(i,l,r){
                if(b[i] < b[l]) continue;
                res = bit.query(b[i])+1;
                bit.add(b[i],res);
            }
            return r-l+1-res;
        };
        ans += work(S[i-1],S[i]);
    }
    printf("%d\n",ans);
    return 0;
}