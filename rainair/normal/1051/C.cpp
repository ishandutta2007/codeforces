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
#define RFOR(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
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

const int MAXN = 100 + 5;
int a[MAXN],N,p[MAXN];
int ans[MAXN];

int l[MAXN],top1,r[MAXN],top2;
bool vis[MAXN];

int main(){
    scanf("%d",&N);
    FOR(i,1,N){
        scanf("%d",a+i);
        p[a[i]]++;
    }
    FOR(i,1,100+2){
        if(p[i] == 1) l[++top1] = i;
        if(p[i] > 2) r[++top2] = i;
    }
    if((top1&1) && (!top2)){
        puts("NO");
        return 0;
    }
    puts("YES");
    for(int i = 1;i <= top1;i += 2){
        ans[l[i]] = 1;
        ans[l[i+1]] = 2;
    }
    if(top1 & 1){
        ans[r[1]] = 22;
    }
    FOR(i,1,N){
        if(p[a[i]] == 1){
            // DEBUG(ans[a[i]]);
            printf("%c",(ans[a[i]] == 1) ? 'A' : 'B');
        }
        else{
            if(ans[a[i]] == 22){
                if(!vis[a[i]]){
                    printf("B");
                    vis[a[i]] = true;
                }
                else{
                    printf("A");
                }
            }
            else{
                /*if(vis[a[i]]) printf("B");
                else{
                    printf("A");
                    // vis[a[i]] = true;
                    if(p[a[i]] == 3) vis[a[i]] = 1;
                }
                if(p[a[i]] > 3) vis[a[i]] = !vis[a[i]];*/
                printf("A");
            }
        }
    }
    return 0;
}