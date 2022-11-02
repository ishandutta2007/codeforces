#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 5e5 + 5;
const int ha = 1e9 + 7;
int n,m;
int x[MAXN],y[MAXN],f[MAXN];

inline int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        int k;scanf("%d",&k);
        scanf("%d",x+i);
        if(k == 2) scanf("%d",y+i);
        if(x[i] < y[i]) std::swap(x[i],y[i]);
    }
    FOR(i,1,m+1) f[i] = i;
    std::vector<int> S;
    FOR(i,1,n){
        if(!y[i]){
            x[i] = find(x[i]);
            if(x[i] == m+1) continue;
            S.pb(i);f[x[i]] = m+1;
        }
        else{
            x[i] = find(x[i]);y[i] = find(y[i]);
            if(x[i] == y[i]) continue;
            if(x[i] == m+1){
                f[y[i]] = m+1;
            }
            else if(y[i] == m+1){
                f[x[i]] = m+1;
            }
            else{
                if(x[i] < y[i]) std::swap(x[i],y[i]);
                f[x[i]] = y[i];
            }
            S.pb(i);
        }
    }
    int ans = qpow(2,SZ(S));
    printf("%d %d\n",ans,SZ(S));
    for(auto x:S) printf("%d ",x);puts("");
    return 0;
}