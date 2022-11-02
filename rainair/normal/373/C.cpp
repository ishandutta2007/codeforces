/*
 * Author: RainAir
 * Time: 2019-09-13 18:46:30
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
 
const int MAXN = 1e6 + 5;
 
int n,a[MAXN];
 
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    std::sort(a+1,a+n+1);
    int ans = n;
    ROF(i,(n>>1),1) if(a[ans] >= (a[i]<<1)) ans--;
    printf("%d\n",ans);
}