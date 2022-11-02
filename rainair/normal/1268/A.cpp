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
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
int a[MAXN],n,k;
int b[MAXN];
char str[MAXN];

int main(){
    scanf("%d%d",&n,&k);scanf("%s",str+1);
    FOR(i,1,n) a[i] = str[i]-'0';
    FOR(i,1,k) b[i] = a[i];
    FOR(i,k+1,n) b[i] = b[i-k];
    bool flag = true;
    printf("%d\n",n);
    FOR(i,1,n){
        if(a[i] > b[i]){
            b[k]++;
            ROF(i,k-1,1){
                if(b[i+1] >= 10) b[i+1] -= 10,b[i]++;
            }
            FOR(i,1,k) printf("%d",b[i]);
            FOR(i,k+1,n) printf("%d",b[i]=b[i-k]);puts("");
            exit(0);
        }
        if(a[i] < b[i]){
            FOR(i,1,n) printf("%d",b[i]);puts("");
            exit(0);
        }
    }
    FOR(i,1,n) printf("%d",b[i]);puts("");
    return 0;
}