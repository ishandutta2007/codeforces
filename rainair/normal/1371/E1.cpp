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

const int MAXN = 2000+5;
int a[MAXN];
int p,n;
std::vector<int> S;

int main(){
    scanf("%d%d",&n,&p);
    FOR(i,1,n) scanf("%d",a+i);
    std::sort(a+1,a+n+1);std::reverse(a+1,a+n+1);
    int mn = a[n],mx = a[1];
    FOR(x,mn,mx){
        int ans = 1;
        bool flag = 1;
        FOR(j,1,n) flag &= (n-a[j]+x-j+1 >= 0);
        if(!flag) continue;
        FOR(j,1,n) ans = 1ll*ans*(std::min(n,n-a[j]+x)-j+1)%p;
        if(ans) S.pb(x);
    }
    printf("%d\n",(int)S.size());
    for(auto x:S) printf("%d ",x);puts("");
    return 0;
}