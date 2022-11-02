/*
 * sto Qingyu orz
 * sqysqy,
 * 
 * sqy
 * Author: RainAir
 * Time: 2019-10-20 15:22:13
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
std::vector<int> G[MAXN];
int n;
char str[MAXN][MAXN];
int len[MAXN];
int du[MAXN];
std::vector<int> ans;

inline void topsort(){
    std::queue<int> q;
    FOR(i,1,26) if(!du[i]) q.push(i);
    while(!q.empty()){
        int v = q.front();q.pop();
        ans.pb(v);
        for(auto x:G[v]){
            if(!--du[x]) q.push(x);
        }
    }
    FOR(i,1,26) if(du[i]){
        puts("Impossible");
        exit(0);
    }
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%s",str[i]+1),len[i] = strlen(str[i]+1);
//    DEBUG((int)('z'+100));
    FOR(i,1,n){
        FOR(j,i+1,n){
            int ps;
            for(ps = 1;ps <= std::min(len[i],len[j]);++ps){
                if(str[i][ps] != str[j][ps]) break;
            }
            if(ps == std::min(len[i],len[j])+1){
                if(len[i] > len[j]){
                    puts("Impossible");
                    return 0;
                }
                continue;
            }
            G[str[i][ps]-'a'+1].pb(str[j][ps]-'a'+1);
            ++du[str[j][ps]-'a'+1];
        }
    }
    topsort();
    for(auto x:ans) putchar(x+'a'-1);
    puts("");
    return 0;
}