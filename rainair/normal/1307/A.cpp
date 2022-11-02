/*
 * Author: RainAir
 * Time: 2020-03-02 08:30:19
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
const int MAXN = 1000+5;
int a[MAXN];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n,d;scanf("%d%d",&n,&d);
        FOR(i,1,n) scanf("%d",a+i);
        FOR(i,2,n){
            int now = (i-1);
            if(d >= now*a[i]){
                a[1] += a[i];d -= now*a[i];
            }
            else if(d >= now){
                a[1] += d/now;d = 0;
            }
            else break;
        }
        printf("%d\n",a[1]);
    }
    return 0;
}