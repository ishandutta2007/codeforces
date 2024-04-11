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
const int MAXN = 100000 + 5;
int N;
int a[MAXN],b[MAXN];
std::vector<int> va[MAXN];
int t[MAXN];
bool flag=0;

inline void Solve(int start){
    t[1] = start;
    FOR(i,2,N){
        if((a[i-1] <= 1 && t[i-1] > 1) || (a[i-1]%2==0 && t[i-1]%2==1) || (b[i-1] > 1 && t[i-1] <= 1) || (b[i-1]%2==1 && t[i-1]%2==0))
            return;
        t[i]=0;
        if(t[i-1]>1){
            if(b[i-1]>1) t[i]+=2;
        }
        else{
            if(a[i-1]>1) t[i] += 2;
        }
        if(t[i-1]%2==1){
            if(b[i-1]%2==1)t[i]++;
        }
        else{ 
            if(a[i-1]%2==1)t[i]++;
        }
    }
    puts("YES");
    FOR(i,1,N) printf("%d ",t[i]);
    puts("");exit(0);
}
int main(){
    read(N);
    FOR(i,1,N-1) read(a[i]);
    FOR(i,1,N-1) read(b[i]);
    FOR(start,0,3){
        Solve(start);
    }
    puts("NO");
    return 0;
}