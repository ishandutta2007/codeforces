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

const int MAXN = 50+5;

char str[MAXN];
int n;

inline void Solve(){
    scanf("%d%s",&n,str+1);
    int now = 0,t1=0,t2=0;
    FOR(i,1,n){
        if(str[i] == '(') now++;
        else{
            if(now > 0){
                now--;continue;
            }
            t1++;
        }
    }
    t2 = now;
    printf("%d\n",t1);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}