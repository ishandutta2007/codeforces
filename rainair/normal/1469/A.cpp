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

const int MAXN = 1e5 + 5;
char str[MAXN];int n;
int sm[MAXN];

inline void Solve(){
    scanf("%s",str+1);n = strlen(str+1);
    if(n&1){
        puts("NO");
        return;
    }
    int cnt = 0,r = 0;
    FOR(i,1,n){
        if(str[i] == '(') ++cnt;
        else if(str[i] == ')') --cnt;
        else{
            --cnt;++r;
        }
        if(cnt < 0){
            if(!r) break;
            cnt += 2;r--;
        }
    }
    puts(cnt==0?"YES":"NO");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}