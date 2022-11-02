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

const int MAXN = 1e5 + 5;
int a[MAXN],n,b[MAXN],m;
int s1[MAXN],s2[MAXN];

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",a+i),s1[i] = s1[i-1]+a[i];
    FOR(i,1,m) scanf("%d",b+i),s2[i] = s2[i-1]+b[i];
    int l1,l2,r1,r2,ans=0;
    l1 = 1;r1 = 1;l2 = 1;r2 = 1;
    while(r1 <= n && r2 <= m){
        while(r1 < n && s1[r1]-s1[l1-1] < s2[r2]-s2[l2-1]) r1++;
        while(r2 < m && s1[r1]-s1[l1-1] > s2[r2]-s2[l2-1]) r2++;
        //DEBUG(l1);DEBUG(r1);DEBUG(l2);DEBUG(r2);
        if(s1[r1]-s1[l1-1] == s2[r2]-s2[l2-1]){
           // DEBUG(l1);DEBUG(r1);DEBUG(l2);DEBUG(r2);
            l1 = r1+1;l2 = r2+1;r1 = l1;r2 = l2;ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}