#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;



const int MAXN = 1 << 21;
char S[500005];
int N, gap;
int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];

bool sufCmp(int i, int j)
{
	if (pos[i] != pos[j])
		return pos[i] < pos[j];
	i += gap;
	j += gap;
	return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void buildSA()
{
	N = strlen(S);
	for(int i=0;i<N;i++) sa[i] = i, pos[i] = S[i];
	for (gap = 1;; gap *= 2)
	{
		sort(sa, sa + N, sufCmp);
		for(int i=0;i<N-1;i++) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
		for(int i=0;i<N;i++) pos[sa[i]] = tmp[i];
		if (tmp[N - 1] == N - 1) break;
	}
}

void buildLCP()
{
	for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
	{
		for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];)
		++k;
		lcp[pos[i]] = k;
		if (k)--k;
	}
}

int lst[1000011];

int d[500001];
int far[500000];
int cid[500000];

bool cmp(int a,int b)
{
	return d[a]<d[b];
}

#define SEG (1<<20)
int seg[2*SEG],l[2*SEG],r[2*SEG];

void init()
{
	for(int i=SEG;i<2*SEG;i++)
		seg[i] = 0, l[i] = i-SEG, r[i] = i-SEG;
	for(int i=SEG-1;i>0;i--)
	{
		seg[i] = 0;
		l[i] = l[2*i], r[i] = r[2*i+1];
	}
}

void update(int i,int v)
{
	i += SEG;
	seg[i] += v;
	for(i/=2;i>0;i/=2)
		seg[i] = seg[2*i] + seg[2*i+1];
}
int low,high;
int getSum(int i)
{
	if((l[i]>high)||(r[i]<low)) return 0;
	if((l[i]>=low)&&(r[i]<=high)) return seg[i];
	return getSum(2*i)+getSum(2*i+1);
}

int main()
{
	scanf("%d",&N);
	scanf("%s",S);
	if(S[0]=='(') d[0] = 1;
	else d[0] = -1;
	for(int i=1;i<N;i++)
	{
		if(S[i]=='(') d[i] = d[i-1]+1;
		else d[i] = d[i-1]-1;
	}
	for(int i=0;i<=1000010;i++) lst[i] = N;
	for(int i=N-1;i>=0;i--)
	{
		if(S[i]=='(')
		{
			far[i] = lst[d[i]+500002-2];
		}
		lst[d[i]+500002] = i;
	}
	buildSA();
	buildLCP();
	for(int i=0;i<N;i++)
		cid[i] = i;
	sort(cid,cid+N,cmp);
	long long ans = 0;
	init();
	
	int start = 0;
	for(int i=0;i<N;i++)
		pos[sa[i]] = i;
	for(int i=0;i<N;i++)
	{
		if(i<N-1 && d[cid[i]]==d[cid[i+1]])
			continue;
		for(int j=start-1;j>=0 && d[cid[j]]==d[cid[i]]-1;j--)
		{
			if(S[cid[j]]==')')
			{
				update(cid[j],+1);
			}
		}
		for(int j=start;j<=i;j++)
		{
			if(S[cid[j]]=='(')
			{
				low = cid[j]+lcp[pos[cid[j]]];
				high = far[cid[j]];
				if(high>=low) ans += getSum(1);
			}
		}
		for(int j=start-1;j>=0 && d[cid[j]]==d[cid[i]]-1;j--)
			if(S[cid[j]]==')')
				update(cid[j],-1);
		start = i+1;
	}
	cout << ans << '\n';
}