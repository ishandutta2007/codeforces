#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

#define int LL

const int MAXN = 2e5+5;

int N;
int b[MAXN],a[MAXN];

signed main(){
	scanf("%I64d",&N);
	FOR(i,1,(N/2)) scanf("%I64d",&b[i]);
	int lst=0;
	a[N+1]=1e18+666;
	FOR(i,1,(N/2)){
		int ai=lst,ani=b[i]-lst;
		if(ani>a[N-i+2]){
			ani=a[N-i+2];
			lst=b[i]-ani;
		}
		a[i]=lst;a[N-i+1]=b[i]-lst;
	}
	FOR(i,1,N) printf("%I64d ",a[i]);
	puts("");
	
	return 0;
}