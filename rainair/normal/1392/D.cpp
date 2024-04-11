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
char s[MAXN];
int n;

inline int pre(int x){
    return (x-2+n)%n+1;
}

inline int suf(int x){
    return x%n+1;
}

inline void Solve(){
    scanf("%d",&n);scanf("%s",s+1);
    bool flag = 1;
    FOR(i,2,n) flag &= (s[i] == s[i-1]);
    if(flag){
        printf("%d\n",(int)std::ceil(1.0*n/3));
        return;
    }
    int ext = n;
    int ans = 0;
    FOR(i,1,n){
        int x = i,y = suf(i);
        if(s[x] == 'R' && s[y] == 'L'){
            int v = pre(x);int t = 0;
            while(s[v] == 'R') t++,v = pre(v);
            int res = std::max(0,(int)std::ceil(1.0*(t-1)/3));t = 0;
            v = suf(y);while(s[v] == 'L') t++,v = suf(v);
            res += std::max(0,(int)std::ceil(1.0*(t-1)/3));
            ans += res;
        }
    }
    printf("%d\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}