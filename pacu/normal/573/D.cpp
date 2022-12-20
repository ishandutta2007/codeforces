#include <cstdio>
#include <algorithm>
using namespace std;

long long w[30000],w2[30000];
long long h[30000],h2[30000];
int cw[30000],ch[30000];
int p[30000];
int wloc[30000],hloc[30000];

bool cmph(int a,int b)
{
	return h2[a]<h2[b];
}
bool cmpw(int a,int b)
{
	return w2[a]<w2[b];
}

long long dp[30000];

long long cyc1[30000],cyc2[30000],cyc3a[30000],cyc3b[30000],cyc3c[30000];

int main()
{
	int N,Q;
	scanf("%d %d",&N,&Q);
	for(int i=0;i<N;i++) scanf("%d",&w2[i]),cw[i] = i;
	for(int i=0;i<N;i++) scanf("%d",&h2[i]), ch[i] = i;
	sort(cw,cw+N,cmpw);
	for(int i=0;i<N;i++) wloc[cw[i]] = i, w[i] = w2[cw[i]];
	sort(ch,ch+N,cmph);
	for(int i=0;i<N;i++) hloc[ch[i]] = i, h[i] = h2[ch[i]];
	
	for(int i=0;i<N;i++) p[i] = hloc[cw[i]];
	
	for(int i=0;i<N;i++)
		cyc1[i] = w[i]*h[i];
	for(int i=1;i<N;i++)
		cyc2[i] = w[i]*h[i-1] + w[i-1]*h[i];
	for(int i=2;i<N;i++)
	{
		cyc3a[i] = w[i-2]*h[i-1] + w[i-1]*h[i] + w[i]*h[i-2];
		cyc3b[i] = w[i-2]*h[i] + w[i-1]*h[i-2] + w[i]*h[i-1];
		cyc3c[i] = w[i-2]*h[i] + w[i-1]*h[i-1] + w[i]*h[i-2];
	}
	
	int a,b;
	for(int i=0;i<Q;i++)
	{
		scanf("%d %d",&a,&b);
		a = wloc[a-1], b = wloc[b-1];
		swap(p[a],p[b]);
		if(p[0] == 0)
			dp[0] = -100000000000LL;
		else
			dp[0] = cyc1[0];
		dp[1] = -100000000000LL;
		if(p[0] != 0 && p[1] != 1) dp[1] = cyc1[0]+cyc1[1];
		if(p[0] != 1 && p[1] != 0) dp[1] = max(dp[1],cyc2[1]);
		dp[2] = -100000000000LL;
		if(p[2] != 2) dp[2] = cyc1[2] + dp[1];
		if(p[2] != 1)
		{
			if(p[1] != 2) dp[2] = max(dp[2],cyc2[2] + dp[0]);
			if(p[1] != 0 && p[0] != 2) dp[2] = max(dp[2],cyc3b[2]);
		}
		if(p[2] != 0)
		{
			if(p[1] != 2 && p[0] != 1) dp[2] = max(dp[2],cyc3a[2]);
			if(p[1] != 1 && p[0] != 2) dp[2] = max(dp[2],cyc3c[2]);
		}
		for(int j=3;j<N;j++)
		{
			dp[j] = -100000000000LL;
			if(p[j] != j) dp[j] = cyc1[j] + dp[j-1];
			dp[j] = max(dp[j],cyc2[j] + dp[j-2]);
			dp[j] = max(dp[j],cyc3b[j] + dp[j-3]);
			dp[j] = max(dp[j],cyc3a[j] + dp[j-3]);
			dp[j] = max(dp[j],cyc3c[j] + dp[j-3]);
		}
		printf("%I64d\n",dp[N-1]);
	}
	return 0;
}