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
int n;
int a[MAXN];

inline void Solve(){
    scanf("%d",&n);
    FOR(i,0,n-1) scanf("%d",a+i),a[i] = -a[i];
    std::map<int,int> S;
    FOR(i,0,n-1){
        int t = a[i]-i;
        t = (t%n+n)%n;
        if(S[t]){
            puts("NO");return;
        }
        S[t] = 1;
    }
    puts("YES");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}