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
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 100+5;
int sum,max,a[MAXN],n,cnt;
std::vector<int> ans;

int main(){
    scanf("%d",&n);FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) sum += a[i];max = a[1];
    cnt = a[1];ans.pb(1);
    FOR(i,1,n) if((a[i]<<1) <= max) cnt += a[i],ans.pb(i);
    if((cnt<<1) > sum){
        printf("%d\n",(int)ans.size());
        for(auto x:ans) printf("%d ",x);
        puts("");return 0;
    }
    puts("0");
    return 0;
}