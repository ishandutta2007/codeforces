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

const int MAXN = 2e5 + 5;
int a[MAXN],b[MAXN],n;
int psa[MAXN],psb[MAXN];
int t[MAXN*2+3];

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),psa[a[i]] = i;
    FOR(i,1,n) scanf("%d",b+i),psb[b[i]] = i;
    FOR(i,1,n){
        if(psa[i] < psb[i]){
            t[psb[i]-psa[i]+n]++;
        }
        else{
            t[n-(psa[i]-psb[i])+n]++;
        }
    }int ans = 0;
    FOR(i,0,MAXN*2) ans = std::max(ans,t[i]);
    printf("%d\n",ans);
    return 0;
}