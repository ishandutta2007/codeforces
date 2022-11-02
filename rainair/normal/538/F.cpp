/*
 * sto Qingyu orz
 * sqysqy,
 * 
 * sqy
 * Author: RainAir
 * Time: 2019-10-18 20:49:25
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

const int MAXN = 2e5 + 5;
int a[MAXN],n;
int ans[MAXN];
std::vector<int> S[MAXN];

int main(){
    scanf("%d",&n);
    FOR(i,0,n-1) scanf("%d",a+i);
    FOR(i,1,n-1){
        // fa(i) = i/k;
        int r;
        for(int l = 1;l <= n;l = r+1){
            if(((i-1)/l) != 0) r = (i-1)/((i-1)/l);
            else r = n;
            int fa = (i-1)/l;
//            if(i == 1) r = n;
//            if(fa == 0) r = n;
//            DEBUG(i);DEBUG(l);DEBUG(r);
//            DEBUG(a[i]);DEBUG(a[fa]);
            if(a[fa] <= a[i]) continue;
            ++ans[l];--ans[r+1];
        }
    }
    FOR(i,1,n) ans[i] += ans[i-1];
    FOR(i,1,n-1) printf("%d ",ans[i]);
    puts("");
    return 0;
}