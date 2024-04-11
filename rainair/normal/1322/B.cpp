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

const int MAXN = 4e5 + 5;
int a[MAXN],n;
std::vector<int> S;

inline int calc(int k){
    S.clear();FOR(i,1,n) S.pb(a[i]&((1<<(k+1))-1));
    std::sort(all(S));
    LL res = 0;
    FOR(i,0,n-1){
        int l=0,r=0;
        if((S[i]>>k)&1){
            l = 0;r = (1<<(k+1))-S[i]-1;
        }
        else{
            l = (1<<k)-S[i];r = (1<<(k+1))-S[i]-1;
        }
        if(l <= S[i] && S[i] <= r) res--;
        l = std::lower_bound(all(S),l)-S.begin();
        r = std::upper_bound(all(S),r)-S.begin()-1;
        if(l > r) continue;
        res += r-l+1;
    }
    FOR(i,0,n-1){
        int l=0,r=0;
        if((S[i]>>k)&1){
            l = (1<<(k+1))-S[i]+(1<<k);r = 1e7;
        }
        else{
            l = (1<<(k+1))-S[i]+(1<<k);r = 1e7;
        }
        if(l <= S[i] && S[i] <= r) res--;
        l = std::lower_bound(all(S),l)-S.begin();
        r = std::upper_bound(all(S),r)-S.begin()-1;
        if(l > r) continue;
        res += r-l+1;
    }
    res /= 2;
    return res&1;
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    int ans = 0;
//    DEBUG(calc(0));exit(0);
    FOR(i,0,24){
        ans |= calc(i)<<i;
    }
    printf("%d\n",ans);
    return 0;
}