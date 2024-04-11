/*
 * sto Qingyu orz
 * sqysqy,
 * 
 * sqy
 * Author: RainAir
 * Time: 2019-10-21 20:14:21
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

const int MAXN = 1e5 + 5;
const int MAXM = 19;
int a[MAXN],pc[MAXN];
int f[MAXN][MAXM+1];
int n;

inline void prework(){
    FOR(j,1,MAXM){
        FOR(i,1,n){
            if(i+(1<<(j-1)) >= MAXN) break;
            f[i][j] = f[i][j-1]|f[i+(1<<(j-1))][j-1];
        }
    }
}

inline int calc(int l,int r){
    int c = pc[r-l+1];
    return f[l][c]|f[r-(1<<c)+1][c];
}

std::set<int> S;

inline int calc(int L,int l,int r,int x){
    int ans = n+1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(calc(L,mid) != x) ans = mid,r = mid-1;
        else l = mid+1;
    }
    return ans;
}

int main(){
    scanf("%d",&n);
    pc[0] = -1;FOR(i,1,MAXN-1) pc[i] = pc[i>>1]+1;
    FOR(i,1,n) scanf("%d",a+i),f[i][0] = a[i];
    prework();
//    DEBUG(calc(1,2));
//    return 0;
    FOR(l,1,n){
        int r = l;S.insert(a[r]);
        int t = a[r];
        while(r <= n){
            int ps = calc(l,r+1,n,t);
            if(ps > n) break;
            t = calc(l,ps);
            S.insert(t);
            r = ps;
        }
    }
 //   for(auto x:S) DEBUG(x);
    printf("%lu\n",S.size());
    return 0;
}