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

const int MAXN = 3e5 + 5;
int n,m,a[MAXN],b[MAXN];

inline bool chk(int x){
    FOR(i,1,n) b[i] = a[i];
    if(b[1]+x >= m) b[1] = 0;
    FOR(i,2,n){
        if(b[i] < b[i-1]){if(b[i]+x >= b[i-1]) b[i] = b[i-1];}
        else if(b[i]+x-m >= b[i-1]) b[i] = b[i-1];
        if(b[i] < b[i-1]) return false;
    }
    return true;
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",a+i);
    int l = 0,r = m,ans = m;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(chk(mid)) ans = mid,r = mid-1;
        else l = mid+1;
    }
    printf("%d\n",ans);
    return 0;
}