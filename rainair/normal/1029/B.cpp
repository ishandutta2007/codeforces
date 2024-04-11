#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio> 
#include <ctime>
#include <climits>
#include <set> 
#include <cmath>
#define FOR(i,a,b) for(int i = a;i <= b;i++)
#define RFOR(i,a,b) for(int i = a;i >= b;i--)
#define CLR(i,x) memset(i,x,sizeof(i))
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define LL long long

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

inline void read(int &x){
	scanf("%d",&x);
}

inline void read(LL &x){
	scanf("%lld",&x);
}

int a[200000 + 5];

int main(){
	int N;
	read(N);
	FOR(i,1,N) read(a[i]); 
	a[N+1] = INT_MAX;
	int ans = 0,cnt = 1;
	FOR(i,2,N+1){
		ans = std::max(ans,cnt);
		if(a[i] > a[i-1]*2) cnt = 1;
		else ++cnt;
	}
	printf("%d\n",ans);
	return 0;	
}