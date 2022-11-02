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

const int MAXN = 100+5;
int a[MAXN],n,m;

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        int sm = 0;
        FOR(i,1,n){
            int x;scanf("%d",&x);sm += x;
        }
        puts(m==sm?"YES":"NO");
    }
    return 0;
}