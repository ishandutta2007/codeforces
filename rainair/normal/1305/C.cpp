/*
 * Author: RainAir
 * Time: 2020-03-03 22:47:43
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

const int MAXN = 2e5 + 5;
int a[MAXN];
int n,m;

int main(){
    scanf("%d%d",&n,&m);
    if(n >= 2000){
        puts("0");
        return 0;
    }
    FOR(i,1,n) scanf("%d",a+i);
    int ans = 1;
    FOR(i,1,n){
        FOR(j,1,i-1){
            ans = 1ll*ans*std::llabs(a[i]-a[j])%m;
        }
    }
    printf("%d\n",ans);
    return 0;
}