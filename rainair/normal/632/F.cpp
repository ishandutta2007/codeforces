#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2500+5;

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

int a[MAXN][MAXN],n;
std::bitset<MAXN> b[MAXN];

struct Node{
    int i,j,v;
    Node(int i=0,int j=0,int v=0) : i(i),j(j),v(v) {}
};

int main(){
    read(n);
    FOR(i,1,n) FOR(j,1,n) read(a[i][j]);
    FOR(i,1,n) FOR(j,1,i-1) if(a[i][j]^a[j][i]){puts("NOT MAGIC");return 0;}
    FOR(i,1,n) if(a[i][i]){puts("NOT MAGIC");return 0;}
    if(n == 1){
        puts("MAGIC");
        return 0;
    }
    std::vector<Node> S;
    FOR(i,1,n) FOR(j,1,i-1) S.pb(Node(i,j,a[i][j]));
    std::sort(all(S),[&](const Node &a,const Node &b){return a.v < b.v;});
    for(int l = 0,r;l < SZ(S);l = r+1){
        r = l;while(r+1 < SZ(S) && S[r+1].v == S[l].v) ++r;
        FOR(i,l,r){
            if((b[S[i].i]&b[S[i].j]).count()){
                puts("NOT MAGIC");
                return 0;
            }
        }
        FOR(i,l,r){
            b[S[i].i][S[i].j] = b[S[i].j][S[i].i] = 1;
        }
    }
    puts("MAGIC");
    return 0;
}