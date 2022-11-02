#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

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

const int MAXN = 1500+5;
int a[MAXN][MAXN],b[MAXN][MAXN],n,m;
int cnt[MAXN];// : cut
int id[MAXN];
bool used[MAXN];

int main(){
    read(n);read(m);
    FOR(i,1,n) FOR(j,1,m) read(a[i][j]);
    FOR(i,1,n) FOR(j,1,m) read(b[i][j]);
    FOR(i,1,n-1) FOR(j,1,m) cnt[j] += b[i][j]>b[i+1][j];
    std::queue<int> q;FOR(i,1,m) if(!cnt[i]) q.push(i);
    std::vector<int> ans;
    while(!q.empty()){
        int v = q.front();q.pop();
        ans.pb(v);
        FOR(i,1,n-1){
            if(used[i]) continue;
            if(b[i][v]^b[i+1][v]){
                used[i] = 1;
                FOR(j,1,m){
                    if(b[i][j]>b[i+1][j]){
                        --cnt[j];
                        if(!cnt[j]) q.push(j);
                    }
                }
            }
        }
    }
//    FOR(i,0,SZ(ans)-1) DEBUG(ans[i]);
    FOR(i,1,n) id[i] = i;
    std::reverse(all(ans));
    for(auto v:ans){
        std::stable_sort(id+1,id+n+1,[&](int x,int y){return a[x][v]<a[y][v];});
    }
    bool flag = 1;
    FOR(i,1,n) FOR(j,1,m) flag &= a[id[i]][j] == b[i][j];
    if(!flag){
        puts("-1");
        return 0;
    }
    printf("%d\n",SZ(ans));
    for(auto x:ans) printf("%d ",x);puts("");
    return 0;
}