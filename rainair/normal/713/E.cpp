#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
int m,n,a[MAXN],b[MAXN];
int f[MAXN];// right end

inline bool chk(int d){// [i,i+d]
    // first go left
    FOR(i,0,n) f[i] = 0;
    f[1] = 1;
    FOR(i,2,n){
        f[i] = 0;
        if(f[i-1] >= a[i]-1){
            f[i] = a[i]+d;
        }
        else if(f[i-1] >= a[i]-d-1){
            f[i] = a[i];
        }
        if(i >= 3 && f[i-2] >= a[i]-d-1){// 1 go left!
            f[i] = std::max(f[i],a[i]);
            f[i] = std::max(f[i],a[i-1]+d);
        }
        if(f[i] == 0) break;
    }
    if(f[n] >= m-d+1 -1) return 1;
    // first go right, second go left
    if(a[2]-d >= 1) return 0;
    FOR(i,0,n) f[i] = 0;
    f[1] = f[2] = a[1]+d;
    FOR(i,3,n){
        f[i] = 0;
        if(f[i-1] >= a[i]-1){
            f[i] = a[i]+d;
        }
        else if(f[i-1] >= a[i]-d-1){
            f[i] = a[i];
        }
        if(i >= 3 && f[i-2] >= a[i]-d-1){
            f[i] = std::max(f[i],a[i]);
            f[i] = std::max(f[i],a[i-1]+d);
        }
        if(f[i] == 0) break;
    }
    if(f[n] >= m-(d-a[2]) -1) return 1;
    return 0;
}

int main(){
    scanf("%d%d",&m,&n);
    FOR(i,1,n) scanf("%d",a+i);
    if(n == 1){
        printf("%d\n",m-1);
        return 0;
    }
    int ps = 2;// maxlen (ps-1,ps)
    FOR(i,3,n) if(a[ps]-a[ps-1] < a[i]-a[i-1]) ps = i;
    if(a[ps]-a[ps-1]-1 < a[1]-1+m-a[n]) ps = 1;
    std::rotate(a+1,a+ps,a+n+1);
    FOR(i,1,n) b[i] = a[i];a[1] = 1;
    auto go = [&](int x,int y){
        if(x < y) return y-x;
        return m-(x-y);
    };
    FOR(i,2,n) a[i] = a[i-1]+go(b[i-1],b[i]);
    int l = 0,r = m-a[n]-1,ans = m-a[n];
    while(l <= r){
        int mid = (l + r) >> 1;
        if(chk(mid)) ans = mid,r = mid-1;
        else l = mid+1;
    }
    printf("%d\n",ans);
    return 0;
}
// test5,test6:  i  i-2  f[i-2] 