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

const int MAXN = 2e5 + 5;
const int ha = 998244353;
int f[MAXN],n;

int main(){
    scanf("%d",&n);
    f[1] = 1;FOR(i,2,n) f[i] = (f[i-1]+f[i-2])%ha;
    int pw = f[n];FOR(i,1,n) pw = 499122177ll*pw%ha;
    printf("%d\n",pw);
    return 0;
}