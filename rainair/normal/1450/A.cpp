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

const int MAXN = 200+5;
char str[MAXN];
int cnt[26],n;

int main(){
    int T;scanf("%d",&T);
    while(T--){
        CLR(cnt,0);scanf("%d",&n);
        scanf("%s",str+1);
        FOR(i,1,n) ++cnt[str[i]-'a'];
        FOR(i,1,cnt[1]) putchar('b');
        FOR(i,0,25){
            if(i == 1) continue;
            FOR(j,1,cnt[i]) putchar('a'+i);
        }
        puts("");
    }
    return 0;
}