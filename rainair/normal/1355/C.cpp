#include<bits/stdc++.h>

#define fi first
#define se second
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

const int MAXN = 2e6 + 5;
int f[MAXN];

int main(){
    int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
    FOR(i,0,b-a){
        int l = i,r = i+c-b;
        f[l]++;f[r+1]--;
    }
    FOR(i,1,MAXN-1) f[i] += f[i-1];
    LL ans = 0;
    FOR(sm,a+b,b+c){
//        DEBUG(f[sm-a-b]);
        ans += 1ll*f[sm-a-b]*std::max(0,std::min(d-c+1,sm-c));
    }
    printf("%lld\n",ans);
    return 0;
}