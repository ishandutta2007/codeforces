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

int main(){
	int a,b;
	read(a);read(b);
	std::string str;
	std::cin >> str;
	int i = 0,j =  str.length()-1 ;
	int si = i,sj = j;
	while(i < str.length() && j > 0){
		bool flag = false;
		FOR(l,0,i)
			if(str[l] != str[str.length()-1-i+l]) flag = true;
		i++;j--;
		if(flag) continue;
		si = i;sj = j;
	}
	FOR(k,1,b){
		FOR(l,0,sj) putchar(str[l]);
	}
	FOR(l,sj+1,str.length()-1) putchar(str[l]);
	return 0;	
}