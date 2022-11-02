#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define R register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(R int i = a;i <= b;++i)
#define RFOR(i,a,b) for(R int i = a;i >= b;--i)
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
// using namespace fastIO;

int N,M;
bool vis[3000 + 5][3000 + 5];
bool book[3005][3005];
char str[3005];

const int dx[8] = {1,-1,0,0,1,-1,1,-1};
const int dy[8] = {0,0,1,-1,1,-1,-1,1};

inline void solve(int x,int y){
    FOR(i,0,7){
        int xx = x + dx[i],yy = y + dy[i];
        if(!book[xx][yy]) return;
    }
    FOR(i,0,7){
        int xx = x + dx[i],yy = y + dy[i];
        vis[xx][yy] = 1;
    }
}

int main(){
    scanf("%d%d",&N,&M);
    FOR(i,1,N){
        scanf("%s",str+1);
        FOR(j,1,M){
            book[i][j] = (str[j] == '#');
        }
    }
    FOR(i,2,N-1){
        FOR(j,2,M-1){
            solve(i,j);
        }
    }
    bool flag = 0;
    FOR(i,1,N){
        FOR(j,1,M){
            if(book[i][j]&& !vis[i][j]){
                flag = 1;break;
            }
        }
        if(flag) break;
    }
    if(flag) puts("NO");
    else puts("YES");
    return 0;
}