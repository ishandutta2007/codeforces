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
int n,a[MAXN],f[MAXN];

inline void Solve(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),f[i] = 0;
    int k = 0;
    ++f[a[1]];++f[a[n]];
    FOR(i,2,n){
        if(a[i] == a[i-1]){
            ++k;++f[a[i]];++f[a[i-1]];
        }
    }
    int mx = 0,ps = -1;
    FOR(i,1,n){
        if(mx < f[i]-k-2){
            mx = f[i]-k-2;
            ps = i;
        }
    }
    if(!mx){
        printf("%d\n",k);
        return;
    }
    int r = 0;
    FOR(i,2,n) if(a[i] != a[i-1] && a[i] != ps && a[i-1] != ps) ++r;
    if(mx <= r){
        printf("%d\n",k+mx);
    }
    else{
        puts("-1");
    }
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}