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
const int MAXN = 100000+5;
const int MAXM = 20 + 5;

int f[MAXN][MAXM];
int N,K,L=1,R;
int a[MAXN];
int cnt[MAXN],ans,t[MAXN];

inline int calc(int l,int r){
	while(L > l) ans += cnt[a[--L]]++;
	while(R < r) ans += cnt[a[++R]]++;
	while(L < l) ans -= --cnt[a[L++]];
	while(R > r) ans -= --cnt[a[R--]];
	return ans;
}

void work(int k,int l,int r,int pl,int pr){
	if(l > r) return;
	if(l == r){
		FOR(i,pl,pr) f[l][k] = std::min(f[l][k],f[i-1][k-1]+calc(i,l));
		return;
	}
	int mid = (l + r) >> 1;
	FOR(i,pl,pr) t[i] = f[i-1][k-1] + calc(i,mid);
	int next = 0;
	FOR(i,pl,pr){
		if(!next || t[i] < t[next]) next = i;
	}
	f[mid][k] = t[next];
	work(k,l,mid-1,pl,next);
	work(k,mid+1,r,next,pr);
}

signed main(){
	scanf("%I64d%I64d",&N,&K);
	FOR(i,1,N) scanf("%I64d",a+i);
	CLR(f,0x7f);
	f[0][0] = 0;
	FOR(i,1,K) work(i,1,N,1,N);
	printf("%I64d\n",f[N][K]);
	return 0;
}
/*
 f[i][j]  i  j 
 f[i][j] = min{f[k][j-1] + w(k+1,i)}
*/