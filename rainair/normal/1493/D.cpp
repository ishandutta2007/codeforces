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
const int ha = 1e9 + 7;

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

bool p[MAXN];int prime[MAXN],cnt,d[MAXN];

inline void prework(){
    FOR(i,2,MAXN-1){
        if(!p[i]) prime[++cnt] = i,d[i] = i;
        for(int j = 1;j <= cnt && 1ll*i*prime[j] < MAXN;++j){
            p[i*prime[j]] = 1;d[i*prime[j]] = prime[j];
            if(!(i%prime[j])) break;
        }
    }
}

int n,q,a[MAXN];
std::map<int,int> mp[MAXN];
std::multiset<int> S[MAXN];
int mn[MAXN];

inline int calc(int x){
    if(SZ(S[x]) < n) return 0;
    return *S[x].begin();
}

std::mt19937 g(time(NULL));

int main(){
    prework();
    scanf("%d%d",&n,&q);
//    n = q = 200000;
    FOR(i,1,n){
        scanf("%d",a+i);
        //a[i] = 1+g()%n;
        FOR(j,1,cnt){
            int p = prime[j];
            if(p > 500) break;
            int c = 0;
            while(!(a[i]%p)) a[i] /= p,++c;
            if(c) mp[p][i] = c;
        }
        if(a[i] != 1) ++mp[a[i]][i];
    }
    int ans = 1;
    FOR(i,1,cnt){
        int p = prime[i];
        for(auto x:mp[p]) S[p].insert(x.se);
        mn[p] = calc(p);
        ans = 1ll*ans*qpow(p,mn[p])%ha;
    }
    FOR(i,1,q){
        int ps,x;scanf("%d%d",&ps,&x);
//        ps = 1+g()%n;x = 1+g()%n;
        auto gao = [&](int p){
            int c = 0;
            if(mp[p].count(ps)){
                c = mp[p][ps];
                S[p].erase(S[p].find(c));
            }
            while(!(x%p)) x /= p,++c;
            if(c) S[p].insert(c),mp[p][ps] = c;
            int t = calc(p);
            if(mn[p] != t){
                ans = 1ll*ans*qpow(p,t-mn[p])%ha;
                mn[p] = t;
            }
        };
        while(x != 1){
            int p = d[x];
            gao(p);
        }
        printf("%d\n",ans);
    }
    return 0;
}