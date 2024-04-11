#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

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

const int MAXN = 2000+5;

char GG[10][10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

bool f[MAXN][MAXN];
int dis[(1<<7)+3][10];
int n,m;
char str[MAXN];
int a[MAXN];

int main(){
    FOR(S,0,(1<<7)-1){
        FOR(j,0,9){
            bool flag = 1;
            FOR(k,0,6){
                if((((S>>k)&1) == 1) && GG[j][k] == '0'){flag = 0;break;}
                if((((S>>k)&1) == 0) && GG[j][k] == '1') dis[S][j]++;
            }
            if(!flag) dis[S][j] = 1e9;
        }
    }
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        scanf("%s",str);
        FOR(k,0,6) if(str[k] == '1') a[i] |= (1<<k);
    }
    f[n+1][0] = 1;
    ROF(i,n,1){
        FOR(j,0,m){
            if(!f[i+1][j]) continue;
            FOR(k,0,9){
                if(j+dis[a[i]][k] > m) continue;
                f[i][j+dis[a[i]][k]] = 1;
            }
        }
    }
    if(!f[1][m]){
        puts("-1");return 0;
    }
    int now = m;
    FOR(i,1,n){
        ROF(j,9,0){
            if(now-dis[a[i]][j] < 0) continue;
            if(!f[i+1][now-dis[a[i]][j]]) continue;
            printf("%d",j);now -= dis[a[i]][j];break;
        }
    }puts("");
    return 0;
}