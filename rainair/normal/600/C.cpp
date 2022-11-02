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

const int MAXN = 2e5 + 5;
int cnt[26];char str[MAXN];int n;

int main(){
    scanf("%s",str+1);n = strlen(str+1);
    FOR(i,1,n) ++cnt[str[i]-'a'];
    int las = -1;std::vector<int> S;
    FOR(i,0,25) if(cnt[i]&1) S.pb(i);
    FOR(i,0,SZ(S)-1){
        int j = SZ(S)-i-1;
        if(j == i){
            las = S[j];break;
        }
        if(j < i) break;
        --cnt[S[j]];++cnt[S[i]];
    }
    if(las != -1) --cnt[las];
    FOR(i,0,25) FOR(j,1,cnt[i]/2) putchar('a'+i);
    if(las != -1) putchar('a'+las);
    ROF(i,25,0) FOR(j,1,cnt[i]/2) putchar('a'+i);
    puts("");
    return 0;
}