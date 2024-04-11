#include <cstdio>
using namespace std;
#define SEG (1<<17)

int a[2*SEG][17],b[2*SEG][17];
long long m[2*SEG][17];
int sz[2*SEG];
int A[SEG];

long long tri(long long a)
{
	return (a*(a+1))>>1;
}

void fix(int i,int k)
{
	bool f1 = (a[(i<<1)][k]==sz[(i<<1)]);
	bool f2 = (b[(i<<1)+1][k]==sz[(i<<1)+1]);
	if(f1&&f2)
	{
		a[i][k] = b[i][k] = sz[i];
		m[i][k] = 0;
	}
	else if(f1)
	{
		a[i][k] = sz[(i<<1)]+a[(i<<1)+1][k];
		m[i][k] = m[(i<<1)+1][k];
		b[i][k] = b[(i<<1)+1][k];
	}
	else if(f2)
	{
		a[i][k] = a[(i<<1)][k];
		m[i][k] = m[(i<<1)][k];
		b[i][k] = sz[(i<<1)+1]+b[(i<<1)][k];
	}
	else
	{
		a[i][k] = a[(i<<1)][k];
		m[i][k] = m[(i<<1)][k]+m[(i<<1)+1][k]+tri(b[(i<<1)][k]+a[(i<<1)+1][k]);
		b[i][k] = b[(i<<1)+1][k];
	}
}

void init()
{
	for(int k=0;k<17;k++)
	{
		for(int i=SEG;i<2*SEG;i++)
		{
			a[i][k] = b[i][k] = (A[i-SEG]&(1<<k))>0;
			m[i][k] = 0;
			sz[i] = 1;
		}
		for(int i=SEG-1;i>0;i--)
		{
			sz[i] = 2*sz[(i<<1)];
			fix(i,k);
		}
	}
}

void update(int i,int v)
{
	int j;
	int o = A[i];
	A[i] = v;
	for(int k=0;k<17;k++)
	{
		if((o&(1<<k)) != (v&(1<<k)))
		{
			j = i+SEG;
			a[j][k] = b[j][k] = (v&(1<<k))>0;
			for(j>>=1;j>0;j>>=1)
				fix(j,k);
		}
	}
}

int main()
{
	int N,Q;
	scanf("%d %d",&N,&Q);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	init();
	int p,v;
	long long ans;
	for(int i=0;i<Q;i++)
	{
		scanf("%d %d",&p,&v);
		update(p-1,v);
		ans = 0;
		for(int k=0;k<17;k++)
			ans += (m[1][k]+tri(a[1][k])+tri(b[1][k]))<<k;
		printf("%I64d\n",ans);
	}
	return 0;
}