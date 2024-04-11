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
        if(n == 1){
            puts("0");continue;
        }
        int t2=0,t3=0;
        while(n%2==0)n/=2,t2++;
        while(n%3==0)n/=3,t3++;
        if(n != 1 || t2 > t3){
            puts("-1");continue;
        }
        printf("%d\n",std::abs(t2-t3)+t3);
    }
    return 0;
}