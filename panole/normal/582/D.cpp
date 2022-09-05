#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
long long S[3410];
int p,a,A[3410],f[3410][3410][2][2],len,n,nw,ans,cal[3410];
char s[3410];

int Calc(int r)
{
	if (p<=1500) return (r==-1?0:cal[r]);
	if (r<p) return 1ll*(r+1)*(r+2)/2%mod;
	int ans=1ll*p*(p+1)/2%mod,Ans=1ll*((p-1)+(2*p-r-1))*(r-p+1)/2%mod;
	return (ans+Ans>=mod?ans+Ans-mod:ans+Ans);
}

int calc(int lim,int l,int cmp,int jw)
{
	int L,R;
	if (cmp==-1) L=0,R=lim-1; else
	if (cmp==1) L=lim+1,R=p-1; else
	L=R=lim;
	if (jw) L+=p,R+=p;
	L-=l,R-=l,L=max(L,0),R=min(R,2*p-2);
	if (L>R) return 0;
	L=Calc(L-1),R=Calc(R);
	return (R>=L?R-L:R-L+mod);
}

int main()
{
	scanf("%d%d%s",&p,&a,s),len=strlen(s),n=0;
	if (p<=1500)
	{
		for (int r=0; r<2*p-1; r++)
			if (r<p) cal[r]=1ll*(r+1)*(r+2)/2%mod; else
			{
				int ans=1ll*p*(p+1)/2%mod,Ans=1ll*((p-1)+(2*p-r-1))*(r-p+1)/2%mod;
				cal[r]=(ans+Ans>=mod?ans+Ans-mod:ans+Ans);
			}
	}
	for (int i=1; i<=len; i++) S[i]=s[len-i]-'0';
	while (len)
	{
		nw=0;
		for (int i=len; i; i--) nw=(10ll*nw+S[i])%p;
		A[++n]=nw,S[0]=0;
		for (int i=len; i; i--) S[i-1]+=10ll*(S[i]%p),S[i]/=p;
		while (len>0&&S[len]==0) len--;
	}
	f[0][0][0][0]=1;
	for (int i=0; i<n; i++)
		for (int j=0; j<=i; j++)
			for (int k=0; k<2; k++)
				for (int nw,l=0; l<2; l++) if (nw=f[i][j][k][l])
				{
					f[i+1][j][0][0]=(f[i+1][j][0][0]+1ll*calc(A[i+1],l,-1,0)*nw)%mod;
					f[i+1][j][k][0]=(f[i+1][j][k][0]+1ll*calc(A[i+1],l,0,0)*nw)%mod;
					f[i+1][j][1][0]=(f[i+1][j][1][0]+1ll*calc(A[i+1],l,1,0)*nw)%mod;
					f[i+1][j+1][0][1]=(f[i+1][j+1][0][1]+1ll*calc(A[i+1],l,-1,1)*nw)%mod;
					f[i+1][j+1][k][1]=(f[i+1][j+1][k][1]+1ll*calc(A[i+1],l,0,1)*nw)%mod;
					f[i+1][j+1][1][1]=(f[i+1][j+1][1][1]+1ll*calc(A[i+1],l,1,1)*nw)%mod;
				}
	ans=0;
	for (int j=a; j<=n; j++) ans=(ans+f[n][j][0][0])%mod;
	printf("%d\n",ans);
	return 0;
}