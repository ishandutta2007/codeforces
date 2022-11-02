#include<bits/stdc++.h>

#define fi first
#define se second
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e6 + 6;

inline char nc(){
    #define SIZE 1000000+3
    static char buf[SIZE],*p1 = buf+SIZE,*p2 = buf+SIZE;
    if(p1 == p2){
        p1 = buf;p2 = buf+fread(buf,1,SIZE,stdin);
        if(p1 == p2) return -1;
    }
    return *p1++;
    #undef SIZE
}

template <typename T>
inline void read(T &x){
    x = 0;int flag = 0;char ch = nc();
    while(!isdigit(ch)){
        if(ch == '-') flag = 1;
        ch = nc();
    }
    while(isdigit(ch)){
        x = (x<<1) + (x<<3) + (ch^'0');
        ch = nc();
    }
    if(flag) x = -x;
}

int a[MAXN],b[MAXN];
int main(){
    int n,m,p;read(n);read(m);read(p);
    FOR(i,0,n-1) read(a[i]),a[i] %= p;
    FOR(i,0,m-1) read(b[i]),b[i] %= p;
    int t1 = -1,t2 = -1;
    FOR(i,0,n-1){
        if(a[i] != 0){
            t1 = i;break;
        }
    }
    FOR(i,0,m-1){
        if(b[i] != 0){
            t2 = i;break;
        }
    }
    printf("%d\n",t1+t2);
    return 0;
}