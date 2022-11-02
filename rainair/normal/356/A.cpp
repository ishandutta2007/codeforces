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

const int MAXN = 300000 + 5;

std::set<int> S;
int N,M;
int ans[MAXN];
std::vector<std::set<int>::iterator>v;

int main(){
    read(N);read(M);
    FOR(i,1,N) S.insert(i);
    FOR(i,1,M){
        int l,r,x;read(l);read(r);read(x);
        std::set<int>::iterator k = S.lower_bound(l);
        v.clear();
        for(std::set<int>::iterator it = k;*it <= r && it != S.end();it++){
            if(*it == x) continue;
            ans[*it] = x;
            v.push_back(it);
        }//DEBUG((int)v.size()-1);
        FOR(i,0,(int)v.size()-1){
           // DEBUG(*v[i]);DEBUG(i);
            S.erase(v[i]);
        }
        // FOR(j,l,r){
        //     if(j == x) continue;
        //     if(S.count(j)){
        //         S.erase(j);
        //         ans[j] = x;
        //     }
        // }
    }
    FOR(i,1,N) printf("%d%c",ans[i],(i == N) ? '\n' : ' ');
    return 0;
}