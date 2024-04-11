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

const int MAXN = 1e5 + 5;
LL T;int n;
char s[MAXN];
int cnt[26];

int main(){
    scanf("%d%lld%s",&n,&T,s+1);
    FOR(i,1,n-2) ++cnt[s[i]-'a'];
    T -= 1<<(s[n]-'a');T += 1<<(s[n-1]-'a');
    ROF(i,25,0){
        if(T < 0) T = -T;
        if(T >= 1ll*cnt[i]*(1<<i)) T -= 1ll*cnt[i]*(1<<i);
        else{
            int mx = T>>i;T -= 1ll*mx*(1<<i);
            if((cnt[i]-mx)%2 != 0) T -= (1<<i);
        }
    }
    puts(!T?"Yes":"No");
    return 0;
}