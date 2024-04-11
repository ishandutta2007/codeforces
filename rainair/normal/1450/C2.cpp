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
int cnt[2][3],ps[2];

inline void Solve(){
    scanf("%d",&n);CLR(cnt,0);
    FOR(i,1,n){
        scanf("%s",str[i]+1);
        FOR(j,1,n){
            if(str[i][j] != '.') ++cnt[str[i][j]=='X'][(i+j)%3];
        }
    }
    ps[0] = ps[1] = -1;
    int mn = 1e9;
    FOR(i,0,2){
        FOR(j,0,2){
            if(i == j) continue;
            if(mn > cnt[0][i]+cnt[1][j]){
                mn = cnt[0][i] + cnt[1][j];
                ps[0] = i;ps[1] = j;
            }
        }
    }
    FOR(i,1,n){
        FOR(j,1,n){
            if(str[i][j] == '.') putchar(str[i][j]);
            else{
                if(str[i][j] == 'O') putchar((i+j)%3 == ps[0] ? 'X' : 'O');
                else putchar((i+j)%3 == ps[1] ? 'O' : 'X');
            }
        }
        puts("");
    }
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}