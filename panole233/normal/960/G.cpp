#include<cstdio>
#include<cstring>

const long long mod=998244353;
long long jc[200001],a[262144],x[262144],y[262144],wn[20],tmp,AA[262144];
int n,A,B,N,rev[262144],t[21];

long long quickmi(long long a,int b)
{
	long long t=1;
	while (b)
	{
		if (b&1) t=t*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return t;
}

void NTT(long long a[],int n,int fl)
{
	for (int i=0; i<n; i++)
	{
		rev[i]=0;
		for (int j=0; (1<<j)<n; j++) rev[i]=(rev[i]<<1)+((i>>j)&1);
	}	
	for (int i=0; i<n; i++) AA[i]=a[rev[i]];
	for (int i=0; i<n; i++) a[i]=AA[i];
	for (int i=2,nw=1; i<=n; i<<=1,nw++)
		for (int j=0; j<n; j+=i)
		{
			long long w=1;
			for (int k=j; k<j+(i>>1); k++)
			{
				long long t1=a[k],t2=w*a[k+(i>>1)];
				a[k]=(t1+t2)%mod; a[k+(i>>1)]=((t1-t2)%mod+mod)%mod;
				w=w*wn[nw]%mod;
			}
		}
	if (fl==-1)
	{
		for (int i=1; i<(n>>1); i++) tmp=a[i],a[i]=a[n-i],a[n-i]=tmp;
		tmp=quickmi(n,mod-2);
		for (int i=0; i<n; i++) a[i]=a[i]*tmp%mod;
	}
}

void solve(int l,int r)
{
	if (l==r-2) return;
	int mid=(l+r)>>1;
	solve(l,mid); solve(mid,r);
	for (int i=l; i<mid; i++) x[i-l]=a[i],x[i+mid-l-l]=0;
	for (int i=mid; i<r; i++) y[i-mid]=a[i],y[i-l]=0;
	NTT(x,r-l,1); NTT(y,r-l,1);
	for (int i=0; i<r-l; i++) x[i]=(x[i]*y[i])%mod;
	NTT(x,r-l,-1);
	for (int i=l; i<r; i++) a[i]=x[i-l];
}

int main()
{
	jc[0]=1;
	for (int i=1; i<=200000; i++) jc[i]=jc[i-1]*(1ll*i)%mod; 
	scanf("%d%d%d",&n,&A,&B); 
	if (A==0||B==0||n>1&&A==1&&B==1||A+B-1>n) return printf("0\n"),0;
	if (n==1) return printf("1\n"),0;
	for (int i=0; i<131072; i++) a[i<<1]=1,a[i<<1|1]=0; 
	for (int i=0; i<n-1; i++) a[i<<1]=i,a[i<<1|1]=1;
	for (int i=1; i<=18; i++) wn[i]=quickmi(3,(mod-1)/(1<<i));
	solve(0,262144);
	printf("%I64d\n",jc[A+B-2]*quickmi(jc[A-1],mod-2)%mod*quickmi(jc[B-1],mod-2)%mod*a[A+B-2]%mod);
	return 0;
}