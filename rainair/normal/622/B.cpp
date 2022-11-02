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

int main(){
    int a,b,x;
    scanf("%d:%d",&a,&b);
    scanf("%d",&x);
    int t = a*60+b+x;
    t %= 1440;
    FOR(i,0,23){
        if(t < 60){
            printf("%02d:%02d\n",i,t);
            return 0;
        }
        t -= 60;
    }
    return 0;
}