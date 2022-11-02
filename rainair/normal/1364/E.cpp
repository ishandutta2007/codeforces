/*
 * Author: RainAir
 * Time: 2020-06-14 15:14:11
 */
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

const int MAXN = 2050;
int a[MAXN];
int w[233];
int N,len;
std::vector<P> S;
std::mt19937 g(time(NULL));
int n;
int __[MAXN*MAXN+MAXN];
bool can[MAXN*MAXN+MAXN];
int bb[MAXN];

inline int query(int x,int y){
    //return bb[x]|bb[y];
    if(x > y) std::swap(x,y);
    int id = x*n+y;
    if(can[id]) return __[id];
    can[id] = 1;
    printf("? %d %d\n",x,y);
    std::fflush(stdout);
    int res;scanf("%d",&res);return __[id] = res;
}

int ans[MAXN];

inline int calc(int x,int p){
    if(x == w[p]) return 0;
    int t = query(x,w[p]);
    return (t>>p)&1;
}

inline int get(int x){
    int res = 0;
    FOR(i,0,10){
        res |= calc(x,i)<<i;
    }
    return res;
}

int main(){
    scanf("%d",&n);
  //  FOR(i,1,n) bb[i] = n-i;
    while(true){
        int x = 1+g()%n,y = 1+g()%n;
        while(y == x) y = 1+g()%n;
        int t = query(x,y);
        FOR(i,0,10){
            if((t>>i)&1) continue;
            w[i] = x;
        }
        bool flag = 1;
        int cnt = 0;
        FOR(i,0,10){
//            DEBUG(w[i]);DEBUG(flag);
            flag &= (bool)w[i];
        }
        if(flag) break;
    }
    std::vector<int> S;
    std::shuffle(all(S),g);
    int ps = 1,val = get(1);
    FOR(i,2,n){
        if(query(ps,i) == val){
            ps = i;
            val = get(i);
        }
    }
    FOR(i,1,n){
        if(ps == i) a[i] = 0;
        else a[i] = query(ps,i);
    }
    printf("! ");
    FOR(i,1,n) printf("%d ",a[i]);
    puts("");std::fflush(stdout);
    return 0;
}