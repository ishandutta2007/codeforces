#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node
{
	double a[3][3];
}T,A[100001],f[100001],E,C,TT,F[35],TTT;

int n,sta[100001],tp,x,y;
long long t,po[100001],ans;
double ma,P;

struct node2
{
	int a;
	double p;
}a[100001];

bool cmp(node2 a,node2 b) {return a.p<b.p;}

node cheng(node a,node b)
{
	C.a[0][0]=b.a[0][0]*a.a[0][0]+b.a[0][1]*a.a[1][0]+b.a[0][2]*a.a[2][0];
	C.a[0][1]=b.a[0][0]*a.a[0][1]+b.a[0][1]*a.a[1][1]+b.a[0][2]*a.a[2][1];
	C.a[0][2]=b.a[0][0]*a.a[0][2]+b.a[0][1]*a.a[1][2]+b.a[0][2]*a.a[2][2];
	C.a[1][0]=b.a[1][0]*a.a[0][0]+b.a[1][1]*a.a[1][0]+b.a[1][2]*a.a[2][0];
	C.a[1][1]=b.a[1][0]*a.a[0][1]+b.a[1][1]*a.a[1][1]+b.a[1][2]*a.a[2][1];
	C.a[1][2]=b.a[1][0]*a.a[0][2]+b.a[1][1]*a.a[1][2]+b.a[1][2]*a.a[2][2];
	C.a[2][0]=b.a[2][0]*a.a[0][0]+b.a[2][1]*a.a[1][0]+b.a[2][2]*a.a[2][0];
	C.a[2][1]=b.a[2][0]*a.a[0][1]+b.a[2][1]*a.a[1][1]+b.a[2][2]*a.a[2][1];
	C.a[2][2]=b.a[2][0]*a.a[0][2]+b.a[2][1]*a.a[1][2]+b.a[2][2]*a.a[2][2];
	return C;
}

node quickmi(node a,long long b)
{
	T=E;
	while (b)
	{
		if (b&1) T=cheng(T,a);
		a=cheng(a,a);
		b>>=1;
	}
	return T;
}

int main()
{
	scanf("%d%I64d",&n,&t); ma=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d%lf",&x,&y,&P);
		if (y*P>ma) ma=y*P;
		a[i].a=x; a[i].p=P;
	}
	memset(E.a,0,sizeof(E.a));
	E.a[0][0]=E.a[1][1]=E.a[2][2]=1;
	sort(a+1,a+1+n,cmp);
	for (int i=1; i<=n; i++) 
	{
		memset(A[i].a,0,sizeof(A[i].a));
		A[i].a[0][0]=1-a[i].p,A[i].a[0][1]=a[i].p*ma,A[i].a[0][2]=a[i].p*a[i].a;
		A[i].a[1][1]=A[i].a[1][2]=A[i].a[2][2]=1;
	}
	tp=0;
	for (int i=1; i<=n; i++)
	{
		TT=cheng(f[tp],quickmi(A[sta[tp]],t-po[tp]));
		if (cheng(TT,A[sta[tp]]).a[0][2]>cheng(TT,A[i]).a[0][2]) continue;
		while (tp)
		{
			if (cheng(f[tp],A[sta[tp]]).a[0][2]<cheng(f[tp],A[i]).a[0][2]) {tp--; continue;}
			ans=-1; F[0]=A[sta[tp]];
			for (int j=1; j<35; j++) F[j]=cheng(F[j-1],F[j-1]);
			TT=f[tp]; ans=po[tp];
			for (int j=34; j>=0; j--)
			{
				TTT=cheng(TT,F[j]);
				if (cheng(TTT,A[sta[tp]]).a[0][2]>cheng(TTT,A[i]).a[0][2]) TT=TTT,ans+=(1ll<<j);
			}
			ans++;
			if (ans<=t) sta[++tp]=i,po[tp]=ans,f[tp]=cheng(f[tp-1],quickmi(A[sta[tp-1]],po[tp]-po[tp-1]));
			break;
		}
		if (!tp) sta[++tp]=i,po[tp]=1,f[tp]=E;
	}
	printf("%.10lf\n",cheng(f[tp],quickmi(A[sta[tp]],t-po[tp]+1)).a[0][2]);
	return 0;
}