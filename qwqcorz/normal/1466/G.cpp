#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=3e6+5;
const int p=1e9+7;
const int inv2=(p+1)/2;
const int mod=1919810111;

inline void add(int &x,int y)
{
	x+=y;
	if (x>=p) x-=p;
}
int n,q,h1[M],id,ls0,lt,ls,la,sum[N][26],pw[M],pw2[N],inv[N];
string s0,s,t,a;
inline int h2(int x)
{
	if (x==ls) return 0;
	if (x==0) return h1[ls-1];
	return (h1[ls-1]-1LL*h1[x-1]*pw[ls-x]%mod+mod)%mod;
}
int calc(int c)
{
	int ha=0,ret=0;
	for (int i=0;i<la;i++) ha=(ha*26LL+a[i]-'a')%mod;
	for (int i=0;i<ls;i++) h1[i]=((i?h1[i-1]:0)*26LL+s[i]-'a')%mod;
	for (int i=0;i<=ls;i++)
	if (i+la-1>=ls&&i+la-1<ls+1+ls)
	{
		int hash=(1LL*h2(i)*pw[la-(ls-i)]%mod+1LL*c*pw[la-(ls-i)-1]%mod+(i+la-1-ls-1<0?0:h1[i+la-1-ls-1]))%mod;
		ret+=hash==ha;
	}
	return ret;
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	ios::sync_with_stdio(0);
	cin>>n>>q>>s0>>t;
	ls0=s0.length();
	lt=t.length();
	for (int i=lt-1,Pow=1;i>=0;i--,add(Pow,Pow))
	{
		for (int j=0;j<26;j++) sum[i][j]=sum[i+1][j];
		add(sum[i][t[i]-'a'],Pow);
	}
	for (int i=pw2[0]=1;i<N;i++) pw2[i]=pw2[i-1]*2%p;
	for (int i=inv[0]=1;i<N;i++) inv[i]=1LL*inv[i-1]*inv2%p;
	for (int i=pw[0]=1;i<M;i++) pw[i]=pw[i-1]*26LL%mod;
	while (q--)
	{
		int now=0;
		cin>>id>>a;
		s=s0;
		ls=ls0;
		la=a.length();
		for (int i=0;i<=ls-la;i++)
		{
			bool flag=1;
			for (int j=0;j<la;j++) if (s[i+j]!=a[j]) flag=0;
			now+=flag;
		}
		int k=1;
		while (ls<la&&k<=id)
		{
			add(now,now);
			if (ls*2+1>=la) add(now,calc(t[k-1]-'a'));
			s=s+t[k-1]+s;
			ls=ls*2+1;
			k++;
		}
		if (k<=id) now=1LL*now*pw2[id-k+1]%p;
		if (k<=id)
		for (int i=0;i<26;i++)
		if (sum[k-1][i]!=sum[id][i])
		{
			int tmp=calc(i);
			add(now,1LL*tmp*(sum[k-1][i]-sum[id][i]+p)%p*inv[lt-id]%p);
		}
		cout<<now<<'\n';
	}
	
	return 0;
}