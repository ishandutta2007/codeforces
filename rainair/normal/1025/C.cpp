#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
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
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 100000 + 5;
int f[MAXN*3];

int main(){
    std::string str;
    std::cin >> str;
    int len = (unsigned)str.length();
    f[0] = 1;
    for(int i = 1;i < len;i++){
        if(str[i] != str[i-1]) f[i] = f[i-1]+1;
        else f[i] = 1;
    }
    // DEBUG(str[0]);DEBUG(str[len-1]);DEBUG((str[0] != str[len-1]));
    if(str[0] != str[len-1]) f[0] = f[len-1]+1;
    // DEBUG(f[0]);DEBUG(f[len-1]);
    for(int i = 1;i < len;i++){
        if(str[i] != str[i-1]) f[i] = f[i-1]+1;
        else f[i] = 1;
    }
    int ans = 0;
    for(int i = 0;i < len;i++)
        ans = std::max(ans,f[i]);
    printf("%d\n",std::min(ans,len));
    return 0;
}