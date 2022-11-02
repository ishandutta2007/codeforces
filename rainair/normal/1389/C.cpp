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

const int MAXN = 2e5 + 5;
char str[MAXN];
int a[MAXN];
int n;

inline int work(int x,int y){
    int now = 0,res = 0;
    FOR(i,1,n){
        if(!now && x == a[i]){
            res++;
            now ^= 1;
        }
        else if(now && y == a[i]){
            res++;
            now ^= 1;
        }
    }
    if(now && res != 1 && x != y) res--;
    return res;
}

inline void Solve(){
    scanf("%s",str+1);n = strlen(str+1);
    FOR(i,1,n) a[i] = str[i]-'0';
    int ans = 0;
    FOR(i,0,9) FOR(j,0,9) ans = std::max(ans,work(i,j));
    printf("%d\n",n-ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}