#include <cstdio>
using namespace std;
#define MOD1 1000000007
#define MOD2 1000000363
#define SEG (1<<17)

int l[2*SEG];
int r[2*SEG];
int len[2*SEG];
long long num1[2*SEG];
long long num2[2*SEG];

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		l[i] = r[i] = i-SEG;
		len[i] = num1[i] = num2[i] = 0;
	}
	for(int i=SEG-1;i>0;i--)
	{
		l[i] = l[(i<<1)];
		r[i] = r[(i<<1)+1];
		len[i] = num1[i] = num2[i] = 0;
	}
}

void update(int i,int l,long long c1,long long c2)
{
	i += SEG;
	if(l > len[i])
	{
		len[i] = l;
		num1[i] = c1%MOD1;
		num2[i] = c2%MOD2;
	}
	else if(l == len[i])
	{
		num1[i] = (num1[i]+c1)%MOD1;
		num2[i] = (num2[i]+c2)%MOD2;
	}
	i >>= 1;
	while(i>0)
	{
		if(len[(i<<1)]>len[(i<<1)+1])
		{
			len[i] = len[(i<<1)];
			num1[i] = num1[(i<<1)];
			num2[i] = num2[(i<<1)];
		}
		else if(len[(i<<1)]<len[(i<<1)+1])
		{
			len[i] = len[(i<<1)+1];
			num1[i] = num1[(i<<1)+1];
			num2[i] = num2[(i<<1)+1];
		}
		else
		{
			len[i] = len[(i<<1)];
			num1[i] = (num1[(i<<1)]+num1[(i<<1)+1])%MOD1;
			num2[i] = (num2[(i<<1)]+num2[(i<<1)+1])%MOD2;
		}
		i >>= 1;
	}
}

int blen;
long long bnum1,bnum2;
int low,high;

void getBest(int i)
{
	if((r[i]<low)||(l[i]>high)) return;
	if((l[i]>=low)&&(r[i]<=high))
	{
		if(len[i]>blen)
		{
			blen = len[i];
			bnum1 = num1[i];
			bnum2 = num2[i];
		}
		else if(len[i]==blen)
		{
			bnum1 = (bnum1+num1[i])%MOD1;
			bnum2 = (bnum2+num2[i])%MOD2;
		}
	}
	else
	{
		getBest((i<<1));
		getBest((i<<1)+1);
	}
}

int N;
int A[100000];
int prefixLen[100000];
int suffixLen[100000];
long long prefixNum1[100000];
long long prefixNum2[100000];
long long suffixNum1[100000];
long long suffixNum2[100000];

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	init();
	for(int i=0;i<N;i++)
	{
		blen = 0;
		bnum1 = bnum2 = 1;
		low = 0;
		high = A[i]-1;
		getBest(1);
		prefixLen[i] = 1+blen;
		prefixNum1[i] = bnum1;
		prefixNum2[i] = bnum2;
		update(A[i],1+blen,bnum1,bnum2);
	}
	init();
	for(int i=(N-1);i>=0;i--)
	{
		blen = 0;
		bnum1 = bnum2 = 1;
		low = A[i]+1;
		high = SEG-1;
		getBest(1);
		suffixLen[i] = 1+blen;
		suffixNum1[i] = bnum1;
		suffixNum2[i] = bnum2;
		update(A[i],1+blen,bnum1,bnum2);
	}
	int totLen;
	long long totNum1,totNum2;
	totLen = 0;
	totNum1 = totNum2 = 1;
	for(int i=0;i<N;i++)
	{
		if(prefixLen[i] > totLen)
		{
			totLen = prefixLen[i];
			totNum1 = prefixNum1[i];
			totNum2 = prefixNum2[i];
		}
		else if(prefixLen[i] == totLen)
		{
			totNum1 = (totNum1 + prefixNum1[i])%MOD1;
			totNum2 = (totNum2 + prefixNum2[i])%MOD2;
		}
	}
	for(int i=0;i<N;i++)
	{
		if((prefixLen[i]+suffixLen[i]-1) != totLen)
			printf("1");
		else if((((prefixNum1[i]*suffixNum1[i])%MOD1)==totNum1)&&
			(((prefixNum2[i]*suffixNum2[i])%MOD2)==totNum2))
			printf("3");
		else
			printf("2");
	}
	printf("\n");
	return 0;
}