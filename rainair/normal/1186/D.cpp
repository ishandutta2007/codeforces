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

const int MAXN = 2e5 + 5;
int n;double a[MAXN];
int b[MAXN],c[MAXN],d[MAXN],cnt1,cnt2;

int main(){
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%lf",a+i);
        b[i] = std::floor(a[i]);cnt1 += b[i];
        c[i] = std::ceil(a[i]);cnt2 += c[i];
        d[i] = !(b[i] == c[i]);
    }
    int sum = 0,tmp=0;
    FOR(i,1,n){
        printf("%d\n",c[i]);
        sum += d[i];
        if(sum == std::abs(cnt1)) {tmp = i+1;break;}
    }
    FOR(i,tmp,n) printf("%d\n",b[i]);
    return 0;
}