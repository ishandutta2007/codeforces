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

const int MAXN = 2e6 + 5;
char aa[MAXN],bb[MAXN];
int a[MAXN],b[MAXN];
int ans;
int main(){
    scanf("%s%s",aa+1,bb+1);
    int lena = strlen(aa+1),lenb = strlen(bb+1);
    FOR(i,1,lena) a[i] = aa[i] - '0';int sum1=0,sum2=0;
    FOR(i,1,lenb) b[i] = bb[i] - '0',sum2 += b[i];
    FOR(i,1,lenb) sum1 += a[i];
     if((sum1%2 == 0 && sum2%2 == 0) || (sum1%2==1 && sum2%2==1)) ans++;
    FOR(i,2,lena){
        int r = i+lenb-1;if(r > lena) break;
        sum1 -= a[i-1];sum1 += a[r];
        if((sum1%2 == 0 && sum2%2 == 0) || (sum1%2==1 && sum2%2==1)) ans++;
    }
    printf("%d\n",ans);
    return 0;
}