#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

namespace fastIO{ 
    #define BUF_SIZE 100000 
    #define OUT_SIZE 100000 
    #define ll long long 
    bool IOerror=0; 
    inline char nc(){ 
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE; 
        if (p1==pend){ 
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin); 
            if (pend==p1){IOerror=1;return -1;} 
        } 
        return *p1++; 
    } 
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';} 
    inline void read(int &x){ 
        bool sign=0; char ch=nc(); x=0; 
        for (;blank(ch);ch=nc()); 
        if (IOerror)return; 
        if (ch=='-')sign=1,ch=nc(); 
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
        if (sign)x=-x; 
    } 
    inline void read(ll &x){ 
        bool sign=0; char ch=nc(); x=0; 
        for (;blank(ch);ch=nc()); 
        if (IOerror)return; 
        if (ch=='-')sign=1,ch=nc(); 
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
        if (sign)x=-x; 
    } 
    #undef ll 
    #undef OUT_SIZE 
    #undef BUF_SIZE 
}; 
using namespace fastIO;

const int MAXN = 300 + 5;

int N,M,K;
bool vis[MAXN],used[MAXN];
bool map[MAXN][MAXN];

int main(){
    read(N);read(M);read(K);
    FOR(i,1,K){
        int x;read(x);
        vis[x] = 1;
    }
    int maxx = (N-1)*(N-2)/2 + N-K;
    if(N == K || M > maxx){
        puts("-1");return 0;
    }
    int s=1,t,cnt = 0;
    while(!vis[s]) s++;
    used[s] = 1;
    FOR(i,1,N){
        if(!vis[i]){
            t = i;
            used[t] = 1;
            printf("%d %d\n",s,t);
            map[s][t] = map[t][s] = true;
            cnt++;
        }
    }
    FOR(i,1,N){
        if(used[i]) continue;
        printf("%d %d\n",i,t);
        map[i][t] = map[t][i] = 1;
        if(++cnt == M) return 0;
    }
    FOR(i,1,N){
        if(cnt == M) return 0;
        if(i == s) continue;
        FOR(j,1,N){
            if(map[i][j] ||  i == j || j == s) continue;
            printf("%d %d\n",i,j);
            map[i][j] = map[j][i] = true;
            if(++cnt == M) return 0;
        }
    }
    return 0;
}