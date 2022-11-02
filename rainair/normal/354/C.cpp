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
int n,k,a[MAXN];

int main(){
    scanf("%d%d",&n,&k);
    int ans = 1e9;
    FOR(i,1,n) scanf("%d",a+i),ans = std::min(ans,a[i]);
    while(1){
        bool flag = 1;
        FOR(i,1,n){
            while(a[i]%ans > k) flag = 0,ans--;
        }
        if(flag) printf("%d\n",ans),exit(0);
    }
    printf("%d\n",ans);
    return 0;
}