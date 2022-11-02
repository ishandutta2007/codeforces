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

const int MAXN = 300+5;
char str[MAXN][MAXN];int n;
int mp[MAXN][MAXN];
int cnt[3];

inline void Solve(){
    scanf("%d",&n);CLR(cnt,0);
    FOR(i,1,n){
        scanf("%s",str[i]+1);
        FOR(j,1,n){
            if(str[i][j] == 'X') ++cnt[(i+j)%3];
        }
    }
    int ps = -1,mn = std::min({cnt[0],cnt[1],cnt[2]});
    FOR(i,0,2) if(cnt[i] == mn) ps = i;
    FOR(i,1,n){
        FOR(j,1,n){
            if(str[i][j] == 'X'){
                if((i+j)%3 == ps) putchar('O');
                else putchar('X');
            }
            else putchar(str[i][j]);        
        }
        puts("");
    }
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}