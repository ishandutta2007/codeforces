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

const int MAXN = 1e5 + 5;
int a[MAXN],n;

inline void Solve(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    int sm = 0;FOR(i,1,n) sm ^= a[i];
    if(!sm){
        puts("DRAW");
        return;
    }
    int b1 = 0;
    ROF(i,30,0) if((sm>>i)&1){b1=i;break;}
    int s1 = 0;
    FOR(i,1,n) if((a[i]>>b1)&1) s1++;
    int s0 = n-s1;
    puts(s1%4==3&&s0%2==0?"LOSE":"WIN");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}