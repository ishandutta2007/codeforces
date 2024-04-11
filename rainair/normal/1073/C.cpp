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
// using namespace fastIO;
const int MAXN = 200000 + 5;
#define int long long
int N;
char str[MAXN];
int dx,dy;
int sx,sy;
// dx,dy

inline bool check(int k){
    int x = sx,y = sy;
    int l = 1,r = k;
    FOR(i,1,k){
        if(str[i] == 'L' || str[i] == 'R') x -= (str[i] == 'L') ? -1 : 1;
        if(str[i] == 'U' || str[i] == 'D') y -= (str[i] == 'U') ? 1 : -1;
    }
    //if(std::abs(x-dx) + std::abs(y-dy) <= k) return true;
    int extra = std::abs(x-dx) + std::abs(y-dy);
    if(extra <= k && (k-extra)%2 == 0) return true;
    while(r <= N){
        if(str[l] == 'L' || str[l] == 'R') x += (str[l] == 'L') ? -1 : 1;
        if(str[l] == 'U' || str[l] == 'D') y += (str[l] == 'U') ? 1 : -1;
        l++;r++;
        if(str[r] == 'L' || str[r] == 'R') x -= (str[r] == 'L') ? -1 : 1;
        if(str[r] == 'U' || str[r] == 'D') y -= (str[r] == 'U') ? 1 : -1;
        if(r > N) break;
        int extra = std::abs(x-dx) + std::abs(y-dy);
        if(extra <= k && (k-extra)%2 == 0) return true;
    }
    return false;
}

signed main(){
    scanf("%I64d",&N);
    scanf("%s",str+1);
    scanf("%I64d%I64d",&dx,&dy);
    //dx = std::abs(dx);dy = std::abs(dy);
    FOR(i,1,N){
        if(str[i] == 'L' || str[i] == 'R') sx += (str[i] == 'L') ? -1 : 1;
        if(str[i] == 'U' || str[i] == 'D') sy += (str[i] == 'U') ? 1 : -1;
    }
    int L = 0,R = N,ans=-1;
    while(L <= R){
        int mid = (L + R) >> 1;
        if(check(mid)) R = mid-1,ans=mid;
        else L = mid+1;
    }
    printf("%I64d\n",ans);
    return 0;
}