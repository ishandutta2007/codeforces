#include <cstdio>
using namespace std;

char A[1005000];
long long N,K;
long long B = 26LL;
long long MOD1 = 1000000009LL;
long long pw1[1005002];
long long prefix1[1005002];	// 0B^10 + 1B^9 + 1B^8 + 0B^7 + 0B^6 + ...

void computePowers()
{
	pw1[0] = 1;
	for(int i=1;i<=N;i++)
	{
		pw1[i] = (pw1[i-1]*B)%MOD1;
	}
}

void computePrefixes()
{
	prefix1[0] = 0;
	for(int i=1;i<=N;i++)
	{
		prefix1[i] = (prefix1[i-1]*B + (A[i]-'a'))%MOD1;
	}
}

inline long long range(int start,int end)
{
	long long k1 = (prefix1[end]-pw1[end+1-start]*prefix1[start-1])%MOD1;
	if(k1 < 0) k1 += MOD1;
	return k1;
}

int binSearch(int low,int high,int start)
{
	if(low==high) return low;
	if((low+1)==high)
	{
		if(range(start,high) == range(1,high+1-start)) return high;
		return low;
	}
	int mid = (low+high)/2;
	if(range(start,mid) == range(1,mid+1-start)) return binSearch(mid,high,start);
	else return binSearch(low,mid-1,start);
}

inline long long gmin(long long a,long long b)
{
	if(a<b) return a;
	return b;
}

long long occ[1005002];
long long isk[1005002];
long long dif[1005002];

int main()
{
	scanf("%I64d %I64d",&N,&K);
	scanf("%s",A+1);
	computePowers();
	computePrefixes();
	for(long long i=N;i>0;i--)
	{
		if((2*i)>N) occ[i] = 1;
		else
		{
			if(range(1,i) == range(i+1,2*i))
				occ[i] = 2*occ[2*i];
			else
				occ[i] = 0;
			if(((i+i*occ[i])<=N)&&(range(1,i) == range(i*occ[i]+1,i*(1+occ[i]))))
				occ[i]++;
		}
	}
	for(int i=1;i<=N;i++)
		isk[i] = 0;
	for(int i=1;i<=N;i++)
		if(occ[i]>=K)
			isk[i*K] = i;
	for(int i=1;i<=N;i++)
	{
		if(!isk[i]) continue;
		dif[i]++;
		if(A[1]!=A[i+1])
			dif[i+1]--;
		else
			dif[binSearch(i+1,gmin(N,i+isk[i]),i+1)+1]--;
	}
	long long cur = 0;
	for(int i=1;i<=N;i++)
	{
		cur += dif[i];
		printf("%d",cur!=0);
	}
	printf("\n");
	return 0;
}