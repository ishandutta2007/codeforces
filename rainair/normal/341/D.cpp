#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1000+5;
int n,m;

struct BIT{
    #define lowbit(x) ((x)&(-x))
    int tree[2][2][MAXN][MAXN];

    inline void clear(){
        CLR(tree,0);
    }

    inline void add(int x,int y,int v){
        for(int i = x;i <= n;i += lowbit(i)){
            for(int j = y;j <= n;j += lowbit(j)){
                tree[x&1][y&1][i][j] ^= v;
            }
        }
    }

    inline int calc(int x,int y){
        int res = 1;
        for(int i = x;i > 0;i -= lowbit(i))
            for(int j = y;j > 0;j -= lowbit(j))
                res ^= tree[x&1][y&1][i][j];
        return res;
    }

    inline void modify(int x1,int y1,int x2,int y2,int v){ // (x1,y1) -> (x2,y2)
        //add(x2,y2,v);add(x2,y1-1,v);add(x1-1,y2,v);add(x1-1,y1-1,v);
        add(x1,y1,v);add(x1,y2+1,v);add(x2+1,y1,v);add(x2+1,y2+1,v);
    }

    inline int query(int x1,int y1,int x2,int y2){
        return calc(x2,y2)^calc(x2,y1-1)^calc(x1-1,y2)^calc(x1-1,y1-1);
    }
}bit;

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        int opt,x1,y1,x2,y2;scanf("%d%d%d%d%d",&opt,&x1,&y1,&x2,&y2);
        if(opt == 1){
            printf("%d\n",bit.query(x1,y1,x2,y2));
        }
        else{
            int v;scanf("%d",&v);
            bit.modify(x1,y1,x2,y2,v);
        }
    }
    return 0;
}