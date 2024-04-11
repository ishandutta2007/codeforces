#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define Re register
#define LL long long
#define CLR(a,b) memset(a,b,sizeof(a))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

int N;
const int MAXN = 100+5;
int a[MAXN],t[MAXN];

inline int check(int k){
	FOR(i,1,N) t[i] = a[i];
	int ans = 0;
	FOR(i,1,N){
		if(!t[i] && t[i-1] && t[i+1]){
			ans++;t[i+1] = 0;
		}
	}
	return ans;
}

int main(){
	scanf("%d",&N);
	FOR(i,1,N) scanf("%d",a+i);
	printf("%d\n",check(1));
//	int L = 1,R = N,ans;
//	while(L <= R){
//		int mid = (L + R) >> 1;
//		if(check(mid)) R = mid-1,ans = mid;
//		else L = mid + 1;
//	}
    return 0;
}