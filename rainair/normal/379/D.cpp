/*
 * sto Qingyu orz
 * sqysqy,
 * 
 * sqy
 * Author: RainAir
 * Time: 2019-10-21 15:25:35
 */
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
#define int LL
int k,x,n,m;
const int MAXN = 50+5;

struct Node{
    int l,cnt,r;
    // 1:A 2:B 3:others

    Node(int l=0,int cnt=0,int r=0) : l(l),cnt(cnt),r(r) {}

    friend Node operator + (const Node &a,const Node &b){
        Node res;res.cnt = a.cnt+b.cnt;
        res.l = a.l;res.r = b.r;
        if(a.r == 1 && b.l == 2) res.cnt++;
        return res;
    }
}f[MAXN];

inline void calc(){
    FOR(i,3,k) f[i] = f[i-2]+f[i-1];
}

signed main(){
    scanf("%lld%lld%lld%lld",&k,&x,&n,&m);
    FOR(i,0,n/2){
        FOR(j,0,m/2){
            FOR(a,0,1) FOR(b,0,1) FOR(c,0,1) FOR(d,0,1){
                if(i*2+a+b > n || j*2+c+d > m) continue;
                f[1] = Node(a?2:3,i,b?1:3);
                f[2] = Node(c?2:3,j,d?1:3);
                calc(); // NEED FIX
                if(f[k].cnt == x){
                    if(a) putchar('C');
                    FOR(k,1,i) putchar('A'),putchar('C');
                    FOR(k,i*2+a+1,n-b) putchar('X');
                    if(b) putchar('A');
                    puts("");
                    if(c) putchar('C');
                    FOR(k,1,j) putchar('A'),putchar('C');
                    FOR(k,j*2+c+1,m-d) putchar('X');
                    if(d) putchar('A');
                    puts("");
                    return 0;
                }
            }
        }
    }
    puts("Happy new year!");
    return 0;
}