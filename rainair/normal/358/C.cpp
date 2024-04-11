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
#define MP std::make_pair
#define P std::pair<int,int>

const std::string s[4]={"Queue","Stack","Front","Back"};

int N,cnt;
std::vector<P> v;

bool cmp(const P &a,const P &b){
    return a.second < b.second;
}
#define read(x) std::cin >> x;

inline void calc(){
    int ans = 0;
    std::vector<int> ret(v.size());
    std::sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int sz = v.size();
    FOR(i,0,sz-1)
        ret[v[i].second] = 3;
    sz = std::min(3,(int)v.size());
    FOR(i,0,sz-1){
        ret[v[i].second] = i;
        ans++;
    }
    std::sort(v.begin(),v.end(),cmp);
    FOR(i,0,(int)v.size()-1){
        //DEBUG(i);
        // printf("push%d\n",s[ret[i]]);
        // DEBUG(ret[i]);
        std::cout << "push" << s[ret[i]] << std::endl;
    }
    // printf("%d\n",ans);
    std::cout << ans;
    FOR(i,0,ans-1){
        // printf(" pop%d",s[i]);
        std::cout << " pop" << s[i];
    }
    puts("");
    ret.clear();
}

int main(){
    read(N);
    while(N--){
        int x;
        read(x);//DEBUG(x);
        if(x) v.push_back(MP(x,cnt++));
        else{
            calc();
            cnt = 0;
            v.clear();
        }
    }
    if(v.size()){
        FOR(i,0,(int)v.size()-1){
            std::cout << "pushQueue" << std::endl;
        }
    }
    return 0;
}