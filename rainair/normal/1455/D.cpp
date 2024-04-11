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

const int MAXN = 500+5;
int n,x,a[MAXN];
bool f[MAXN];

inline void Solve(){
    scanf("%d%d",&n,&x);
    FOR(i,1,n) scanf("%d",a+i);
    int p = 1;
    ROF(i,n,2){
        if(a[i-1] > a[i]){
            p = i;break;
        }
    }
    if(p == 1){
        puts("0");
        return;
    }
    int ans = 0;
    if(x < a[1]) std::swap(x,a[1]),++ans;
    FOR(i,2,p){
        if(a[i-1] > a[i]){
            if(a[i] <= x){
                puts("-1");return;
            }
            std::swap(a[i],x);++ans;
            if(a[i-1] > a[i]){
                puts("-1");return;
            }
        }
        else if(x < a[i] && i != p){
            std::swap(a[i],x);++ans;
        }
    }
    printf("%d\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}