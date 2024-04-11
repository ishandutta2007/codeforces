#include<bits/stdc++.h>
using namespace std;

const int mod=10007;
void add(int &x,int y) {x=(x+y>=mod?x+y-mod:x+y);}

namespace BM
{
	int d[2410],len[2410],R[2410][2410],a[2410],n,cnt,nwR[2410],nw,f[2410];
	typedef vector<int> vint;
	int quickmi(int a,int b)
	{
		int t=1;
		for (; b; b>>=1,a=a*a%mod)
			if (b&1) t=t*a%mod;
		return t;
	}
	void getR()
	{
		cnt=0;
		for (int i=1; i<=n; i++)
		{
			if (!cnt&&!a[i]) continue;
			if (!cnt)
			{
				len[cnt=1]=i,d[i]=a[i],f[0]=i;
				for (int j=1; j<=i; j++) R[1][j]=0;
				continue;
			}
			nw=0;
			for (int j=1; j<=len[cnt]; j++) nw=(nw+R[cnt][j]*a[i-j])%mod;
			if (nw!=a[i])
			{
				d[i]=(a[i]-nw+mod)%mod,f[cnt]=i,nw=d[i]*quickmi(d[f[cnt-1]],mod-2)%mod;
				len[cnt+1]=max(len[cnt],i-f[cnt-1]+len[cnt-1]),cnt++;
				for (int j=1; j<=len[cnt-1]; j++) R[cnt][j]=R[cnt-1][j];
				add(R[cnt][i-f[cnt-2]],nw);
				for (int j=1; j<=len[cnt-2]; j++)
					R[cnt][i-f[cnt-2]+j]=(R[cnt][i-f[cnt-2]+j]+R[cnt-2][j]*(mod-nw))%mod;
			}
		}
	}
	vint mul(vint A,vint B)
	{
		int nA=A.size(),nB=B.size();
		vint C; C.resize(nA+nB-1);
		for (int i=0; i<nA; i++)
			for (int j=0; j<nB; j++)
				C[i+j]=(C[i+j]+A[i]*B[j])%mod;
		return C;
	}
	vint getmod(vint A,vint B)
	{
		int nA=A.size(),nB=B.size(),inv=quickmi(B[nB-1],mod-2);
		for (int i=nA-1; i>=nB-1; i--) if (A[i])
			for (int j=0; j<nB; j++) A[i-nB+j+1]=(A[i-nB+j+1]+inv*B[j]%mod*(mod-A[i]))%mod;
		A.resize(nB-1); return A;
	}
	vint quickmi(vint M,int N)
	{
		vint A,T; 
		A.resize(2),A[0]=0,A[1]=1;
		T.resize(1),T[0]=1;
		for (; N; N>>=1,A=mul(A,A),A=getmod(A,M))
			if (N&1) T=mul(T,A),T=getmod(T,M);
		return T;
	}
	int solve(int N)
	{
		if (len[cnt]==1) return quickmi(R[cnt][1],N-n)*a[n]%mod;
		vint M; M.clear(); int ans=0;
		for (int i=len[cnt]; i; i--) M.push_back(R[cnt][i]);
		M.push_back(mod-1),M=quickmi(M,N-len[cnt]);
		for (int i=0,sz=M.size(); i<sz; i++) ans=(ans+a[len[cnt]+i]*M[i])%mod;
		return ans;
	}
}

int n,f[2410][210][210],len;
char s[210];

int main()
{
	scanf("%s%d",s+1,&n);
	n+=(len=strlen(s+1));
	f[0][0][len+1]=1;
	for (int i=1; i<=2400; i++)
		if (i&1)
		{
			for (int k=1; k<=len+1; k++) f[i][0][k]=25*f[i-1][0][k]%mod;
			for (int j=1; j<=len; j++)
				for (int k=1; k<=len+1; k++)
					f[i][j][k]=(f[i-1][j-1][k]+25*f[i-1][j][k])%mod;
			for (int k=1; k<=len+1; k++) add(f[i][len][k],f[i-1][len][k]);
		} else
		{
			for (int j=0; j<=len; j++)
				for (int k=1; k<=len+1; k++)
				{
					if (j==len||k==1) f[i][j][k]=(f[i][j][k]+26*f[i-2][j][k])%mod; else
					{
						if (s[j+1]==s[k-1]) add(f[i][j+1][k-1],f[i-2][j][k]),f[i][j][k]=(f[i][j][k]+25*f[i-2][j][k])%mod;
						else add(f[i][j+1][k],f[i-2][j][k]),add(f[i][j][k-1],f[i-2][j][k]),f[i][j][k]=(f[i][j][k]+24*f[i-2][j][k])%mod;
					}
				}
		}
	memset(BM::a,0,sizeof(BM::a));
	for (int i=1; i<=2400; i++)
		for (int j=0; j<=len; j++)
			for (int k=1; k<=j+1; k++) add(BM::a[i],f[i][j][k]);
	if (n<=2400) printf("%d\n",BM::a[n]); else
	BM::n=2400,BM::getR(),printf("%d\n",BM::solve(n));
	return 0;
}