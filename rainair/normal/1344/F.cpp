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
std::bitset<MAXN> a[MAXN];
bool b[MAXN],sol[MAXN];
int t[MAXN],n,m,k;
//   1 0
// R 0 1
// Y 1 0
// B 1 1
// W 0 0

inline void Gauss(){
    int r = 1;
    for(int i = 1;i <= 2*n && r <= m;++i){
        FOR(j,r,m){
            if(a[j][i]){
                std::swap(a[j],a[r]);
                std::swap(b[j],b[r]);
                break;
            }
        }
        if(!a[r][i]) continue;
//        DEBUG(i);
        FOR(j,r+1,m){
            if(a[j][i]){
                a[j] ^= a[r];
                b[j] ^= b[r];
            }
        }
        ++r;
/*        FOR(i,1,m){
            FOR(j,1,2*n) putchar(a[i][j]+'0');
            putchar(' ');putchar(b[i]+'0');
            puts("");
        }*/
    }
    FOR(i,r,m) if(b[i]){puts("NO");exit(0);}
    ROF(i,r-1,1){
        int j = 1;
        while(j <= 2*n && !a[i][j]) ++j;
        sol[j] = b[i];
        FOR(k,j+1,2*n) if(a[i][k]) sol[j] ^= sol[k];
    }
}

int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) t[2*i-1] = 2,t[2*i] = 1;
    FOR(i,1,k){
        char str[10];scanf("%s",str);
        int _;scanf("%d",&_);std::vector<int> S;
        while(_--){int x;scanf("%d",&x);S.pb(x);}
        if(str[0] == 'm'){
            scanf("%s",str);int col = (str[0] == 'R'?1 : (str[0] == 'Y' ? 2 : (str[0] == 'B' ? 3 : 0)));
            ++m;
            for(auto x:S){
                a[m][2*x-1] = t[2*x-1]>>1;
                a[m][2*x] = t[2*x-1]&1;
            }
            b[m] = col>>1;
            ++m;
            for(auto x:S){
                a[m][2*x-1] = t[2*x]>>1;
                a[m][2*x] = t[2*x]&1;
            }
            b[m] = col&1;
        }
        if(str[0] == 'R' && str[1] == 'Y'){
            for(auto x:S) std::swap(t[2*x-1],t[2*x]);
        }
        if(str[0] == 'R' && str[1] == 'B'){
            for(auto x:S) t[2*x-1] ^= t[2*x];
        }
        if(str[0] == 'Y' && str[1] == 'B'){
            for(auto x:S) t[2*x] ^= t[2*x-1];
        }
    }
    Gauss();
    puts("YES");
    FOR(i,1,n){
        int col = (sol[2*i-1]<<1)|sol[2*i];
        putchar(".RYB"[col]);
    }
    puts("");
    return 0;
}