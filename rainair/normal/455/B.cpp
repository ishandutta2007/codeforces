/*
 * Author: RainAir
 * Time: 2019-08-26 09:32:09
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
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
const int MAXM = 3e5 + 5;

int ch[MAXM][26];
int win[MAXM],lose[MAXM],root = 1,tot = 1;

inline void insert(char str[]){
    int len = strlen(str),v = root;
    FOR(i,0,len-1){
        int x = str[i]-'a';
        if(!ch[v][x]) ch[v][x] = ++tot;
        v = ch[v][x];
    }
}

inline void dfs(int v){
    bool flag = false;
    FOR(i,0,25){
        if(!ch[v][i]) continue;
        flag = true;dfs(ch[v][i]);
        win[v] |= !win[ch[v][i]];
        lose[v] |= !lose[ch[v][i]];
    }
    if(!flag) lose[v] = 1;
}
char str[MAXM];
int main(){
    int n,k;scanf("%d%d",&n,&k);
    FOR(i,1,n){
        scanf("%s",str);insert(str);
    }
    dfs(root);
    if(win[root] && lose[root]){
        puts("First");return 0;
    }
    if(win[root] && !lose[root]){
        puts(k&1 ? "First" : "Second");
        return 0;
    }
    puts("Second");
    return 0;
}