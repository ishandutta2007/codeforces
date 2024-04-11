/*
 * Author: RainAir
 * Time: 2020-06-01 14:50:15
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
const int MAXN = 5000+5;
int a[MAXN];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int x,n;scanf("%d%d",&n,&x);
        FOR(i,1,n) scanf("%d",a+i),a[i] %= 2;
        int t0=0,t1=0;
        FOR(i,1,n){
            if(a[i] == 0) t0++;
            else t1++;
        }
        bool flag = false;
        for(int i = 1;i <= std::min(t1,x);i += 2){
            if(x-i <= t0){
                flag = 1;break;
            }
        }
        puts(flag ? "Yes" : "No");
    }
    return 0;
}