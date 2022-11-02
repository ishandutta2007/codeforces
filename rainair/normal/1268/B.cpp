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

const int MAXN = 300000+5;
int a[MAXN],tp[MAXN];
int n;
LL w,b;

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    tp[1] = 0;w += (a[1]+1)/2;b += a[1]/2;
    FOR(i,2,n){
        if(a[i] == a[i-1]) tp[i] = !tp[i-1];
        else tp[i] = !(tp[i-1]^((a[i-1]-a[i])%2));
        w += (a[i]+!tp[i])/2;b += (a[i]+tp[i])/2;
    }
    printf("%lld\n",std::min(w,b));
    return 0;
}