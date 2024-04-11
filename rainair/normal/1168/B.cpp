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

const int MAXN = 3e5 + 5;
int n;
char str[MAXN];

int main(){
    scanf("%s",str+1);n = strlen(str+1);
    LL ans = 0;int r = n+2;
    ROF(i,n,1){
        for(int j=1;i+2*j<=n;++j){
            if(str[i] == str[i+j] && str[i+j] == str[i+2*j]){
                r = std::min(r,i+2*j);break;
            }
        }
        ans += std::max(0,n-r+1);
    }
    printf("%lld\n",ans);
    return 0;
}