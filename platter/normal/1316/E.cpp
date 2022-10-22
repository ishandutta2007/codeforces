#include <bits/stdc++.h>
using namespace std;

long long dp[100005][128];
const long long INF=1e16;
const long long nev=-1e15;

struct People {
	long long a;
	long long s[7];
};

bool comp(People x,People y) {
	return x.a>y.a;
}

int n,p,k;

People arr[100005];
long long val[100005];

long long ans(int now,int bit,int bits) {
	if (dp[now][bit]!=nev) {
		return dp[now][bit];
	}
	if (k+bits>n) {
		dp[now][bit]=-INF;
		return -INF;
	}
	if (now==n) {
		if (bits==p) {
			dp[now][bit]=0;
			return 0;
		}
		dp[now][bit]=-INF;
		return -INF;
	}
	if (bits==p) {
		dp[now][bit]=0;
		return 0;
	}
	long long ret=ans(now+1,bit,bits);
	if (k+bits==n) {
		dp[now][bit]=ret;
		return ret;
	}
	long long minus=0;
	if (now<k+bits) {
		minus=val[k+bits]-val[now];
	}
	for(int i=0;i<p;i++) {
		if ((bit&(1<<i))==0) {
			ret=max(ret,ans(now+1,bit+(1<<i),bits+1)+minus+arr[now].s[i]);
		}
	}
	dp[now][bit]=ret;
	return ret;
}

int main(void) {
	scanf("%d %d %d\n",&n,&p,&k);
	long long sum=0;
	for(int i=0;i<n;i++) {
		long long x;
		scanf("%lld ",&x);
		arr[i].a=x;
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<p;j++) {
			long long x;
			scanf("%lld ",&x);
			arr[i].s[j]=x;
		}
		scanf("\n");
	}
	sort(arr,arr+n,comp);
	for(int i=0;i<n;i++) {
		val[i]=arr[i].a;
	}
	for(int i=0;i<k;i++) {
		sum+=val[i];
	}
	for(int i=0;i<=n;i++) {
		for(int j=0;j<(1<<p);j++) {
			dp[i][j]=nev;
		}
	}
	printf("%lld",sum+ans(0,0,0));
}