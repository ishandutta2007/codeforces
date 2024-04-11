/*
 * Author: RainAir
 * Time: 2019-10-02 18:50:28
 */
#include <unordered_map>
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
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e6 + 5;
int a[MAXN];
int pre[MAXN],suf[MAXN];
std::unordered_map<int,int> S;
std::multiset<int> SS;
int n;
LL ans = 0;

struct BIT{
    int tree[MAXN];
    #define lowbit(x) ((x)&(-x))

    inline void add(int pos){
        while(pos <= n){
            tree[pos]++;
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
}bit;

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) pre[i] = ++S[a[i]];S.clear();
    ROF(i,n,1) suf[i] = ++S[a[i]];S.clear();
    ROF(i,n,1){
        if(pre[i] > 1) ans += bit.query(pre[i]-1);//,DEBUG(i),DEBUG(bit.query(pre[i]));
        bit.add(suf[i]);
    }
    printf("%lld\n",ans);
    return 0;
}