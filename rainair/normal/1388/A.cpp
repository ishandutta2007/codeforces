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

int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        if(n <= 6+10+14){
            puts("NO");continue;
        }
        if(n == 36){
            puts("YES\n5 6 10 15");
            continue;
        }
        if(n == 40){
            puts("YES\n14 15 6 5");
            continue;
        }
        if(n == 44){
            puts("YES\n14 15 6 9");
            continue;
        }
        printf("YES\n%d %d %d %d\n",6,10,14,n-6-10-14);
    }
    return 0;
}