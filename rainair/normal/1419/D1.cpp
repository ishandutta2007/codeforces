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

const int MAXN = 1e5+5;
int a[MAXN],n,ans[MAXN];

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    std::sort(a+1,a+n+1);
    int t = (n-1)/2;
    FOR(i,1,t) ans[2*i] = a[i];
    FOR(i,1,n) if(!ans[i]) ans[i] = a[++t];
    printf("%d\n",(n-1)/2);
    FOR(i,1,n) printf("%d ",ans[i]);
    puts("");
    return 0;
}