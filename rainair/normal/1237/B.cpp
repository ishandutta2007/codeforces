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

const int MAXN = 2e5 + 5;
int a[MAXN],b[MAXN],n;
int ia[MAXN],ib[MAXN];

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),ia[a[i]] = i;
    FOR(i,1,n) scanf("%d",b+i),ib[b[i]] = i;
    int mx = 0,ans = 0;
    FOR(i,1,n){
        if(ib[a[i]]+1 <= mx) ans++;
        mx = std::max(mx,ib[a[i]]);
    }
    printf("%d\n",ans);
    return 0;
}