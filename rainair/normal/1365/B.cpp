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

const int MAXN = 500+5;
int a[MAXN],b[MAXN],n;

inline void Solve(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    int c[2];c[0] = c[1] = 0;
    FOR(i,1,n) scanf("%d",b+i),c[b[i]]++;
    if(c[0] == 0 || c[1] == 0){
        bool flag = 1;
        FOR(i,2,n) flag &= (a[i-1] <= a[i]);
        puts(flag?"Yes":"No");return;
    }
    puts("Yes");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}