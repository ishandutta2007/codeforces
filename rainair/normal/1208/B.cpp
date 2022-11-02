/*
 * Author: RainAir
 * Time: 2019-09-08 08:31:32
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
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 5000+5;
int a[MAXN],b[MAXN],n;
int cnt[MAXN];

inline bool chk(int k){
    FOR(l,1,n){
        int r = l+k-1;
        if(r > n) return false;
        FOR(i,1,n) cnt[i] = 0;
        FOR(i,1,n) cnt[a[i]]++;
        FOR(i,l,r) cnt[a[i]]--;
        bool flag = true;
        FOR(i,1,n) if(cnt[i] > 1) flag = false;
        if(flag) return true;
    }
    return false;
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),b[i] = a[i];
    std::sort(b+1,b+n+1);
    int sz = std::unique(b+1,b+n+1)-b-1;
    FOR(i,1,n) a[i] = std::lower_bound(b+1,b+sz+1,a[i])-b;
    int l = 0,r = n,ans = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(chk(mid)) ans = mid,r = mid-1;
        else l = mid+1;
    }
    printf("%d\n",ans);
    return 0;
}