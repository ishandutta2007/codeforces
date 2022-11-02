/*
 * Author: RainAir
 * Time: 2020-05-17 17:41:06
 */
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

const int MAXN = 2e6 + 5;

struct BIT{
    static const int R = (1<<21);
    #define lowbit(x) ((x)&(-(x)))
    int tree[R];

    inline void add(int pos,int x){
        while(pos < MAXN){
            tree[pos] += x;
            pos += lowbit(pos);
        }
    }

    inline int query(int pos){
        int res = 0;
        while(pos){
            res += tree[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    inline int calc(int p,int k) {
        if(p&1) return p+(tree[p]<k);
        else{
            if(k>tree[p])return calc(p+lowbit(p)/2,k-tree[p]);
            else return calc(p-lowbit(p)/2,k);
        }
    }

    inline int qry(int k) {
        return calc(R>>1, k);
    }
}bit;

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

int main(){
    int n,q;read(n);read(q);
    FOR(i,1,n){
        int x;read(x);
        bit.add(x,1);
    }
    FOR(i,1,q){
        int k;read(k);
        if(k > 0){
            bit.add(k,1);
        }
        else{
            k = -k;
            int t = bit.qry(k);
            bit.add(t,-1);
        }
    }
    FOR(i,1,n){
        if(bit.query(i)-bit.query(i-1)){
            printf("%d\n",i);return 0;
        }
    }
    puts("0");
    return 0;
}