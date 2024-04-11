/*
 * sto Qingyu orz
 * sqysqy,
 * 
 * sqy
 * Author: RainAir
 * Time: 2019-10-18 19:08:34
 */
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
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 100+5;
char str[MAXN];
int n;
int p[MAXN];
bool vis[MAXN];

inline void chk(int step){
    int x = 0;
    FOR(i,1,step) x = x*10+str[p[i]]-'0';
    if(!(x%8)){
        puts("YES");
        printf("%d\n",x);
        exit(0);
    }
}

inline void dfs(int step,int lst){
    if(step >= 2) chk(step-1);
    if(step == 4) return;
    FOR(i,lst+1,n){
        p[step] = i;
        dfs(step+1,i);
    }
}

int main(){
    scanf("%s",str+1);
    n = strlen(str+1);
    dfs(1,0);
    puts("NO");
    return 0;
}