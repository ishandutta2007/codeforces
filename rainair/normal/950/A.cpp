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
#define U unsigned
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

int main(){
    int l,r,a;scanf("%d%d%d",&l,&r,&a);
    int t = std::min(l,r);
    if(t + a <= std::max(l,r)){
        printf("%d\n",(t+a)*2);return 0;
    }
    int c = std::max(l,r)-std::min(l,r);
    printf("%d\n",(std::max(l,r)+(a-c)/2)*2);
    return 0;
}