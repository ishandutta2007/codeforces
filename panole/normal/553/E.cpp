#include<bits/stdc++.h>
using namespace std;

int n,m,t,v,po[65541],ex[110],ey[110],nw,f[110][110],ev[110];
double ans[61][20010],p[110][20010],sum[110][20010],Ans[110][20010];
const double pi=acos(-1.0);

struct node
{
	double a,b;
	node operator *(node x) {return (node){a*x.a-b*x.b,a*x.b+b*x.a};}
	node operator +(node x) {return (node){a+x.a,b+x.b};}
	node operator -(node x) {return (node){a-x.a,b-x.b};}
};

void dft(vector<node> &A,int fl)
{
	int n=A.size(); po[0]=0;
	for (int i=1; i<n; i++) po[i]=(po[i>>1]>>1)|((i&1)?(n>>1):0);
	for (int i=0; i<n; i++) if (po[i]<i) swap(A[po[i]],A[i]);
	for (int i=1; i<n; i<<=1)
	{
		node wn=(node){cos(pi/i*fl),sin(pi/i*fl)};
		for (int j=0; j<n; j+=(i<<1))
		{
			node w=(node){1,0};
			for (int k=0; k<i; k++)
			{
				node t1=A[j+k],t2=A[i+j+k]*w;
				A[j+k]=t1+t2,A[i+j+k]=t1-t2,w=w*wn;
			}
		}
	}
	if (fl==-1) for (int i=0; i<n; i++) A[i].a/=n;
}

vector<double> mul(vector<double> A,vector<double> B)
{
	int nA=A.size(),nB=B.size(),L=1;
	for (; L<nA+nB-1; L<<=1);
	if (L<=128)
	{
		vector<double> C; C.resize(nA+nB-1);
		for (int i=0; i<nA; i++)
			for (int j=0; j<nB; j++)
				C[i+j]+=A[i]*B[j];
		return C;
	}
	vector<node> AA,BB; 
	AA.resize(L),BB.resize(L);
	for (int i=0; i<nA; i++) AA[i].a=A[i];
	for (int i=0; i<nB; i++) BB[i].a=B[i];
	dft(AA,1),dft(BB,1);
	for (int i=0; i<L; i++) AA[i]=AA[i]*BB[i];
	dft(AA,-1),A.resize(nA+nB-1);
	for (int i=0; i<nA+nB-1; i++) A[i]=AA[i].a;
	return A;
}

void solve(int l,int r)
{
	if (l==r) 
	{
		for (int i=1; i<=m; i++) 
			ans[ex[i]][l]=min(ans[ex[i]][l],Ans[i][l]+ev[i]+ans[ey[i]][t+1]*sum[i][t-l+1]);
		return;
	}
	int mid=(l+r)>>1;
	solve(mid+1,r);
	for (int i=1; i<=m; i++)
	{
		vector<double> A,B;
		A.resize(r-mid),B.resize(r-l+1);
		for (int j=mid+1; j<=r; j++) A[r-j]=ans[ey[i]][j];
		for (int j=0; j<=r-l; j++) B[j]=p[i][j];
		A=mul(A,B);
		for (int j=l; j<=mid; j++) Ans[i][j]+=A[r-j];
	}
	solve(l,mid);
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&t,&v);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d%d",&ex[i],&ey[i],&ev[i]);
		for (int j=1; j<=t; j++) scanf("%d",&nw),p[i][j]=nw/100000.0;
		sum[i][t+1]=sum[i][t+2]=p[i][0]=p[i][t+1]=0;
		for (int j=t; j; j--) sum[i][j]=sum[i][j+1]+p[i][j];
	}
	for (int i=1; i<n; i++)
		for (int j=0; j<=t+1; j++) ans[i][j]=(1e15);
	for (int j=0; j<=t; j++) ans[n][j]=0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) f[i][j]=1000000000;
	for (int i=1; i<=m; i++) f[ex[i]][ey[i]]=min(f[ex[i]][ey[i]],ev[i]);
	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for (int i=1; i<n; i++) if (f[i][n]!=1000000000) ans[i][t+1]=f[i][n]+v;
	ans[n][t+1]=v,solve(0,t);
	return printf("%.10lf\n",ans[1][0]),0;
}