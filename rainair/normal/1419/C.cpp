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

const int MAXN = 1e5 + 5;
int n,x;
int a[MAXN];

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&x);int cnt = 0;
        FOR(i,1,n) scanf("%d",a+i),cnt += (a[i]==x);
        if(cnt == n){
            puts("0");
            continue;
        }
        if(cnt){
            puts("1");
            continue;
        }
        LL sm = 0;FOR(i,1,n) sm += a[i];
        if(sm%n == 0 && sm/n == x){
            puts("1");
            continue;
        }
        puts("2");
    }
    return 0;
}