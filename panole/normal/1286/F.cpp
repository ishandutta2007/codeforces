#include<bits/stdc++.h>
using namespace std;

long long a[21];
int n,g[1048579],bc[1048579],lo[1048579],t[21],tn,An,Bn;
long long A[1030],B[1030],s[1048579],s1,s2;
bool f[1048579];

long long getabs(long long x) {return (x<0?-x:x);}
bool cmp(long long a,long long b) {return getabs(a)>getabs(b);}

int main()
{
	for (int i=0; i<20; i++) lo[1<<i]=i+1;
	scanf("%d",&n),s[0]=0;
	for (int i=1; i<=n; i++) scanf("%I64d",&a[i]);
	sort(a+1,a+1+n,cmp);
	while (n&&a[n]==0) n--;
	if (!n) return puts("0"),0;
	for (int i=1; i<(1<<n); i++)
	{
		s[i]=s[i^(i&-i)]+a[lo[i&-i]];
		bc[i]=bc[i^(i&-i)]+1;
	}
	A[0]=B[0]=-1145141919810114514ll;
	for (int i=1; i<(1<<n); i++) if (bc[i]>1)
	{
		tn=0;
		if (!((s[i]+bc[i])&1)) continue;
		for (int j=0; j<n; j++) if (i>>j&1) t[++tn]=j;
		int i1=0,i2;
		for (int j=1; j<=(tn>>1); j++) i1|=(1<<t[j]);
		i2=i^i1,A[An=1]=s1=s[i1],B[Bn=1]=s2=-s[i2];
		for (int j=i1; j; j=(j-1)&i1) A[++An]=s1-2*s[j];
		for (int j=i2; j; j=(j-1)&i2) B[++Bn]=s2+2*s[j];
		sort(A+1,A+1+An),sort(B+1,B+1+Bn),i1=i2=1;
		if (A[1]!=s1||B[1]!=s2) if (A[1]!=-s1||B[1]!=-s2)
		if (getabs(A[1]-B[1])<bc[i]) {f[i]=1; continue;}
		while (i1<An||i2<Bn)
		{
			if (i2==Bn||i1<An&&A[i1+1]<B[i2+1]) i1++; else i2++;
			if (getabs(A[i1]-B[i2])<bc[i]) 
			{
				if (A[i1]!=A[i1-1]&&A[i1]==s1&&B[i2]!=B[i2-1]&&B[i2]==s2) continue;
				if (A[i1]!=A[i1-1]&&A[i1]==-s1&&B[i2]!=B[i2-1]&&B[i2]==-s2) continue;
				f[i]=1; break;
			}
		}
	}
	for (int i=0; i<(1<<n); i++)
	{
		int I=((1<<n)-1)^i,b=(I&-I);
		I^=b;
		for (int j=I; j; j=(j-1)&I)
			if (f[j|b]) g[i|j|b]=max(g[i|j|b],g[i]+1);
	}
	printf("%d\n",n-g[(1<<n)-1]);
	return 0;
}