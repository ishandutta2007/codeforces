#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
int jc[2000001],inv[2000001],sum[2000001],cntA,cntB,len1,len2,mi[1000011],lim,cnt1,cnt2,cnt,ans,Ans[1000011];
char s1[1000011],s2[1000011];
bool bo;

int quickmi(int a,int b)
{
	int t=1;
	for (; b; b>>=1,a=1ll*a*a%mod)
		if (b&1) t=1ll*t*a%mod;
	return t;
}

int C(int a,int b)
{
	if (a<b||b<0) return 0;
	return 1ll*jc[a]*inv[b]%mod*inv[a-b]%mod;
}

int gcd(int a,int b) {return (!b)?a:gcd(b,a%b);}
int add(int a,int b) {return (a+b>=mod)?(a+b-mod):(a+b);}

int main()
{
	jc[0]=mi[0]=1;
	for (int i=1; i<=1000001; i++) mi[i]=add(mi[i-1],mi[i-1]);
	for (int i=1; i<=2000000; i++) jc[i]=1ll*jc[i-1]*i%mod;
	inv[2000000]=quickmi(jc[2000000],mod-2);
	for (int i=2000000; i; i--) inv[i-1]=1ll*inv[i]*i%mod;
	scanf("%s%s%d",s1,s2,&lim),len1=strlen(s1),len2=strlen(s2);
	cntA=cnt1=cnt2=cntB=0;
	for (int i=0; i<len1; i++) 
		if (s1[i]=='A') cntA++; else 
		if (s1[i]=='B') cntB++; else
		if (s1[i]=='?') cnt1++;
	for (int i=0; i<len2; i++)
		if (s2[i]=='A') cntA--; else
		if (s2[i]=='B') cntB--; else
		if (s2[i]=='?') cnt2++;
	for (int nwA=cntA-cnt2,nwB,nw; nwA<=cntA+cnt1; nwA++)
	{
		nwB=cntB+cntA-nwA-cnt2+cnt1;
		if (nwA==0||nwB==0) continue;
		if ((nwA>0)==(nwB>0)) continue;
		nw=max(abs(nwA),abs(nwB))/gcd(abs(nwA),abs(nwB));
		ans=(ans+1ll*C(cnt1+cnt2,cnt1-nwA+cntA)*add(mi[lim/nw+1],mod-2))%mod;
	}
	if (len1!=len2) return printf("%d\n",ans),0;
	cnt=0,bo=1;
	for (int i=0; i<len1; i++)
	{
		if (s1[i]=='?') {if (s2[i]=='?') cnt++;} 
		else if (s2[i]!='?'&&s1[i]!=s2[i]) bo=0;
	}
	for (int i=lim; i; i--)
	{
		Ans[i]=1ll*(lim/i)*(lim/i)%mod;
		for (int j=(i<<1); j<=lim; j+=i) Ans[i]=add(Ans[i],mod-Ans[j]);
	}
	Ans[0]=0;
	for (int i=1; i<=lim; i++) Ans[0]=(Ans[0]+1ll*mi[i]*Ans[i])%mod;
	if (bo)
	{
		for (int i=1; i<=lim; i++)
		{
			sum[i]=mi[i];
			for (int j=(i<<1); j<=lim; j+=i) sum[i]=add(sum[i],mi[j]);
		}
		for (int i=lim; i; i--)
		{
			sum[i]=1ll*sum[i]*sum[i]%mod;
			for (int j=(i<<1); j<=lim; j+=i) sum[i]=add(sum[i],mod-sum[j]);
		}
		for (int i=1; i<=lim; i++) ans=(ans+(sum[i]-1ll*Ans[i]*mi[i])%mod*mi[cnt])%mod;
	}
	ans=(ans+1ll*Ans[0]*C(cnt1+cnt2,cnt1+cntA))%mod;
	return printf("%d\n",(ans+mod)%mod),0;
}