/*
 * Author: RainAir
 * Time: 2020-03-03 22:36:38
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
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 100+5;
int a[MAXN],b[MAXN],n;

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        FOR(i,1,n) scanf("%d",a+i);
        FOR(i,1,n) scanf("%d",b+i);
        std::sort(a+1,a+n+1);std::sort(b+1,b+n+1);
        FOR(i,1,n) printf("%d ",a[i]);puts("");
        FOR(i,1,n) printf("%d ",b[i]);puts("");
    }
    return 0;
}