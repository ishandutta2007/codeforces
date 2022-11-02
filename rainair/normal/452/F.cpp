#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
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

const int MAXN = 3e5 + 5;
const int ha = 1e9 + 9;
int pw[MAXN];

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

inline void add(int &x,int y){
    x += y;if(x >= ha) x -= ha;
}

struct BIT{
    #define lowbit(x) ((x)&(-(x)))
    int tree[MAXN];

    inline void add(int pos,int x){
        int t = pos;
        while(pos < MAXN){
            ::add(tree[pos],1ll*pw[pos-t]*x%ha);
            pos += lowbit(pos);
        }
    }

    inline int calc(int pos){
        int res = 0,t = pos;
        if(pos <= 0) return 0;
        while(pos){
            ::add(res,1ll*tree[pos]*pw[t-pos]%ha);
            pos -= lowbit(pos);
        }
        return res;
    }

    inline int query(int l,int r){
        return (calc(r)+ha-1ll*calc(l-1)*pw[r-l+1]%ha)%ha;
    }
}bit[2];
int a[MAXN],n;

inline void Solve(){// left:1 right:1
    read(n);FOR(i,1,n) read(a[i]);
    CLR(bit,0);
    FOR(i,1,n){
        bit[0].add(a[i],1);
        bit[1].add(n-a[i]+1,1);
        int len = std::min(a[i]-1,n-a[i]);
        if(len <= 0) continue;
        if(bit[1].query(n-(a[i]-1)+1,n-(a[i]-len)+1) != bit[0].query(a[i]+1,a[i]+len)){
            puts("YES");
            return;
        }
    }
    puts("NO");
}

int main(){
//    freopen("D.in","r",stdin);
    pw[0] = 1;FOR(i,1,MAXN-1) pw[i] = 2ll*pw[i-1]%ha;
    int T=1;//read(T);
    while(T--) Solve();
    return 0;
}
/*
mid,mid-i=j-mid,i  j 
0 1 

*/