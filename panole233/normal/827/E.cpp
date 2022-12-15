#include<bits/stdc++.h>
using namespace std;

const int mod=998244353,N=1<<20|3;
int w[N],n,T,p[N],cnt;
char s[500010];
bool bo[500010];
vector<int> A,B;

int quickmi(int a,int b)
{
	int t=1;
	for (; b; b>>=1,a=1ll*a*a%mod)
		if (b&1) t=1ll*t*a%mod;
	return t;
}

void dft(vector<int> &A,int fl)
{
	int n=A.size();
	for (int i=0; i<n; i++) 
		if (p[i]<i) swap(A[p[i]],A[i]);
	for (int i=1; i<n; i<<=1)
		for (int j=0; j<n; j+=(i<<1))
			for (int k=0; k<i; k++)
			{
				int t1=A[j+k],t2=1ll*A[i+j+k]*w[i+k]%mod;
				A[j+k]=(t1+t2>=mod?t1+t2-mod:t1+t2);
				A[i+j+k]=(t1<t2?t1-t2+mod:t1-t2);
			}
	if (fl==-1)
	{
		int inv=quickmi(n,mod-2);
		for (int i=0; i<n; i++) A[i]=1ll*A[i]*inv%mod;
		for (int i=1; i<(n>>1); i++) swap(A[i],A[n-i]);
	}
}

void getrev(int L)
{
	p[0]=0;
	for (int i=1; i<L; i++) 
		p[i]=(p[i>>1]>>1)|((i&1)?(L>>1):0);
}

int getup(int x) {int L=1; for (; L<x; L<<=1); return L;}

int main()
{
	for (int i=0; i<20; i++)
	{
		int wn=quickmi(3,(mod-1)>>(i+1)); w[1<<i]=1;
		for (int j=(1<<i)+1; j<(1<<i+1); j++) w[j]=1ll*w[j-1]*wn%mod;
	}
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%s",&n,s+1); int L=getup(n<<1);
		A.clear(),B.clear(),A.resize(L),B.resize(L),getrev(L);
		for (int i=1; i<=n; i++) 
			if (s[i]=='V') A[i]=1; else
			if (s[i]=='K') B[n-i]=1;
		dft(A,1),dft(B,1);
		for (int i=0; i<L; i++) A[i]=1ll*A[i]*B[i]%mod;
		dft(A,-1),cnt=0;
		for (int i=1; i<=n; i++) bo[i]=1;
		for (int i=0; i<L; i++) if (A[i]) bo[abs(n-i)]=0;
		for (int i=1; i<=n; i++) if (bo[i])
			for (int j=(i<<1); j<=n; j+=i) bo[i]&=bo[j];
		for (int i=1 ;i<=n; i++) cnt+=bo[i]; printf("%d\n",cnt);
		for (int i=1; i<=n; i++) if (bo[i]) printf("%d ",i); puts("");	
	}
	return 0;
}