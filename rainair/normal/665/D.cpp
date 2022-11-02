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

const int MAXN = 2e6+5;
int n,a[MAXN];
int cnt[MAXN];
bool p[MAXN];
int prime[MAXN],tot;

inline void prework(){
    FOR(i,2,MAXN-1){
        if(!p[i]) prime[++tot] = i;
        for(int j = 1;j <= tot && 1ll*i*prime[j] < MAXN;++j){
            p[i*prime[j]] = 1;
            if(!(i%prime[j])) break;
        }
    }
}

int main(){
    prework();scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),++cnt[a[i]];
    int mx = cnt[1];
    FOR(i,1,n){
        if(a[i] != 1 && !p[a[i]+1]) mx = std::max(mx,1+cnt[1]);
    }
    FOR(i,1,n){
        if(a[i] == 1) continue;
        FOR(j,i+1,n){
            if(a[j] == 1) continue;
            if(!p[a[i]+a[j]]){
                mx = std::max(mx,2);
                if(!p[a[i]+1] && !p[a[j]+1]) mx = std::max(mx,2+cnt[1]);
            }
        }
    }
    if(!mx){
        printf("%d\n%d\n",1,a[1]);
        return 0;
    }
    printf("%d\n",mx);
    if(mx == cnt[1]){
        FOR(i,1,mx) printf("%d%c",1," \n"[i==mx]);
        return 0;
    }
    FOR(i,1,n){
        if(a[i] != 1 && !p[a[i]+1]){
            if(mx == 1+cnt[1]){
                FOR(i,1,cnt[1]) printf("%d ",1);
                printf("%d\n",a[i]);
                return 0;
            }
        }
    }
    FOR(i,1,n){
        if(a[i] == 1) continue;
        FOR(j,i+1,n){
            if(a[j] == 1) continue;
            if(!p[a[i]+a[j]]){
                if(mx == 2){
                    printf("%d %d\n",a[i],a[j]);
                    return 0;
                }
                if(!p[a[i]+1] && !p[a[j]+1]){
                    if(mx == 2+cnt[1]){
                        FOR(i,1,cnt[1]) printf("%d ",1);
                        printf(" %d %d\n",a[i],a[j]);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}