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

const int MAXN = 2e5 + 5;
const int MAXM = 17;
int n,m,q,a[MAXN];
int sm[MAXM+1][MAXN],cnt[MAXM+1][MAXN],pre[MAXN];

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        int x;scanf("%d",&x);
        a[x] ^= 1;
    }
    FOR(i,1,m) cnt[0][i] = a[i],pre[i] = pre[i-1]^a[i];
    FOR(i,1,MAXM){
        for(int j = 1;j+(1<<(i-1)) <= m;++j){
            cnt[i][j] = cnt[i-1][j]+cnt[i-1][j+(1<<(i-1))];
            sm[i][j] = sm[i-1][j]^sm[i-1][j+(1<<(i-1))];
            if(cnt[i-1][j+(1<<(i-1))]&1) sm[i][j] ^= (1<<(i-1));
        }
    }
    int q;scanf("%d",&q);
    while(q--){
        int l,r;scanf("%d%d",&l,&r);
        int ans = 0;
        ROF(i,MAXM,0){
            if(l+(1<<i)-1 <= r){
                ans ^= sm[i][l];
                if(pre[r]^pre[l+(1<<i)-1]) ans ^= (1<<i);
                l += (1<<i);
            }
        }
        putchar(ans?'A':'B');
    }
    puts("");
    return 0;
}