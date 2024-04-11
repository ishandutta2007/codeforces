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
char str[MAXN];
int aa[MAXN],bb[MAXN];

inline void Solve(){
    scanf("%d",&n);scanf("%s",str+1);
    FOR(i,1,n) aa[i] = str[i]-'0';
    scanf("%s",str+1);
    FOR(i,1,n) bb[i] = str[i]-'0';
    std::vector<int> S;
    int p = 1;
    ROF(i,n,1){
        if(aa[p] == bb[i]^((n-i)&1)) S.pb(1);
        S.pb(i);p = n-p+1;
        if(p <= n/2) ++p;
    }
    printf("%d ",(int)S.size());
    for(auto x:S) printf("%d ",x);puts("");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}