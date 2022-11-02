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

const int MAXN = 1e6 + 5;
char str[MAXN];
int n;
int sm[MAXN],a[MAXN];

int main(){
    scanf("%d",&n);scanf("%s",str+1);
    FOR(i,1,n) a[i] = (str[i]=='(' ? 1 : -1),sm[i] = sm[i-1]+a[i];
    if(sm[n] != 0){
        puts("-1");return 0;
    }
    int las = -1,ans = 0;
    FOR(i,1,n){
        if(las == -1){
            if(sm[i] < 0){
                las = i;
            }
        }
        else if(sm[i] == 0){
            ans += i-las+1;
            las = -1;
        }
    }
//    DEBUG(las);
    printf("%d\n",ans);
    return 0;
}