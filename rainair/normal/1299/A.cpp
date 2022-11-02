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

const int MAXN = 1e5 + 5;
const int MAXM = 30;
int cnt[MAXM+1];
int n,a[MAXN];

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",a+i);
	FOR(i,1,n){
		FOR(j,0,MAXM){
			if((a[i]>>j)&1) cnt[j]++;
		}
	}
	int ans = -1;
	int ps=-1;
	FOR(i,1,n){
		int t = 0;
		FOR(j,0,MAXM){
			if((a[i]>>j)&1) if(cnt[j] == 1) t |= (1<<j);
		}
		if(t > ans) ans = t,ps = i;
		ans = std::max(ans,t);
	};
	printf("%d ",a[ps]);
	FOR(i,1,n) if(i != ps) printf("%d ",a[i]);puts("");
	return 0;
}