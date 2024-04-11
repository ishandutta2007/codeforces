#include<bits/stdc++.h>
using namespace std;
 
const int mod=1000000007;
set<pair<int,int> > s;
vector<long long> p[110],k[110],b[110],ansa,ansp;
int pr[1000010],prn,n,A,B,nw[110],P,x,ans,a[110],bb[110];
long long nwk[110],nwb[110],ansk[110],ansb[110],phi,qaq;
bool bo[5000010];
 
long long gcd(long long a,long long b) {return (!b)?a:gcd(b,a%b);}
 
long long mul(long long a,long long b,long long mod)
{
	long long t=0;a%=mod;
	for (; b; b>>=1,a=(a+a>=mod?a+a-mod:a+a))
		if (b&1) t=(t+a>=mod?t+a-mod:t+a);
	return t;
}
 
long long quickmi(long long a,long long b,long long mod)
{
	long long t=(mod==1?0:1);a%=mod;
	for (; b; b>>=1,a=mul(a,a,mod))
		if (b&1) t=mul(t,a,mod);
	return t;
}
 
long long getphi(long long x)
{
	long long ans=x;
	for (int i=1; 1ll*pr[i]*pr[i]<=x; i++)
		if (x%pr[i]==0)
		{
			ans=ans/pr[i]*(pr[i]-1);
			while (x%pr[i]==0) x/=pr[i];
		}
	if (x>1) ans=ans/x*(x-1);
	return ans;
}

void work(int I,long long ansb)
{
	ansa.clear(),ansp.clear();
	long long AA=a[I],BB=bb[I];
	if (BB==1) ansb=0;
	for (int i=0,sz=p[I].size(); i<sz; i++)
		if (ansb*k[I][i]+b[I][i]>0) ansp.push_back(p[I][i]),ansa.push_back(ansb*k[I][i]+b[I][i]);
	for (int i=1; i<=n; i++) if (i!=I)
	{
		if (p[i].size()==ansp.size())
		{
			long long nw=-1;
			for (int j=0,sz=p[i].size(); j<sz; j++)
			{
				if (p[i][j]!=ansp[j]) 
				{
					if (b[i][j]!=0||nw>0) puts("-1"),exit(0);
					nw=0;
				} else
				if (k[i][j]==0) {if (b[i][j]!=ansa[j]) puts("-1"),exit(0);} else
				{
					if (nw==-1)
					{
						if (ansa[j]<b[i][j]||(ansa[j]-b[i][j])%k[i][j]!=0) puts("-1"),exit(0);
						nw=(ansa[j]-b[i][j])/k[i][j];
					} else if (nw*k[i][j]+b[i][j]!=ansa[j]) puts("-1"),exit(0);
				}
			}
		} else
		{
			long long ans=AA;
			for (int j=1; j<=ansb; j++) 
			{
				ans*=BB;
				if (ans>a[i]) puts("-1"),exit(0);
			}
			if (ans!=a[i]) puts("-1"),exit(0);
		}
	}
	printf("%d\n",AA%mod*quickmi(BB,ansb,mod)%mod),exit(0);
}

void work(int i,int j,int po)
{
	if (!k[j][po]) swap(i,j);
	if (b[j][po]>b[i][po]) puts("-1"),exit(0);
	if ((b[i][po]-b[j][po])%k[j][po]!=0) puts("-1"),exit(0);
	work(j,(b[i][po]-b[j][po])/k[j][po]);
}
 
void work(int i,int j,int p1,int p2)
{
	int b1=b[i][p1],b2=b[j][p1],b3=b[i][p2],b4=b[j][p2];
	int k1=k[i][p1],k2=k[j][p1],k3=k[i][p2],k4=k[j][p2];
	int kk=k2*k3-k4*k1,bb=b1*k3-b3*k1-b2*k3+b4*k1;
	if (bb==0) work(j,0);
	if ((bb>0)!=(kk>0)) puts("-1"),exit(0);
	if (bb<0) bb=-bb,kk=-kk;
	if (bb%kk!=0) puts("-1"),exit(0);
	work(j,bb/kk);
}
 
int main()
{
	for (int i=2; i<=5000000; i++) if (!bo[i])
	{
		pr[++prn]=i;
		for (int j=i; j<=5000000; j+=i) bo[j]=1;
	}
	qaq=32*27*25;
	for (int i=4; pr[i]<=30; i++) qaq*=pr[i];
	phi=getphi(qaq);
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d",&A,&B),a[i]=A,bb[i]=B;
		if (n==1) return printf("%d\n",A),0;
		for (int j=1; pr[j]<=40000; j++)
			if (A%pr[j]==0||B%pr[j]==0)
			{
				int nw=p[i].size();
				p[i].push_back(pr[j]),k[i].push_back(0),b[i].push_back(0);
				while (A%pr[j]==0) b[i][nw]++,A/=pr[j];
				while (B%pr[j]==0) k[i][nw]++,B/=pr[j];
			}
		if (A!=1)
		{
			if (A==B) p[i].push_back(A),k[i].push_back(1),b[i].push_back(1),B=1;
			else p[i].push_back(A),k[i].push_back(0),b[i].push_back(1);
		}
		if (B!=1) p[i].push_back(B),k[i].push_back(1),b[i].push_back(0);
	}
	for (int i=2; i<=n; i++)
	{
		for (int j=0,sz=min(p[1].size(),p[i].size()); j<sz; j++)
			if (p[1][j]!=p[i][j]) 
			{
				if (p[1][j]<p[i][j]) work(1,0);
				else work(i,0);
			}
		if (p[1].size()<p[i].size()) work(i,0);
		if (p[i].size()<p[1].size()) work(1,0);
		long long laA=0,laB=0; int la=-1;
		for (int j=0,sz=p[1].size(); j<sz; j++)
			if (k[1][j]||k[i][j])
			{
				if (k[1][j]*laB!=k[i][j]*laA) work(1,i,la,j);
				laA=k[1][j],laB=k[i][j],la=j;
			} else
			if (!k[1][j]&&!k[i][j]) {if (b[1][j]!=b[i][j]) return puts("-1"),0;}
			else work(1,i,j);
		for (int j=0,sz=p[1].size(); j<sz; j++) if (k[1][j]||k[i][j])
			for (int l=j+1; l<sz; l++) if (k[1][l]||k[i][l])
				if (1ll*b[1][j]*k[1][l]-1ll*k[1][j]*b[1][l]!=1ll*b[i][j]*k[i][l]-1ll*k[i][j]*b[i][l]) return puts("-1"),0;
	}
	s.clear();
	for (int i=1; i<=n; i++) 
		if (!p[i].empty()) nw[i]=0,s.insert(make_pair(p[i][0],i));
	while (!s.empty())
	{
		P=(*s.begin()).first;
		for (int i=1; i<=n; i++) nwk[i]=nwb[i]=0;
		while (!s.empty()&&(*s.begin()).first==P)
		{
			x=(*s.begin()).second;
			nwk[x]=k[x][nw[x]],nwb[x]=b[x][nw[x]];
			nw[x]++,s.erase(s.begin());
			if (nw[x]<p[x].size()) s.insert(make_pair(p[x][nw[x]],x));
		}
		long long K,B;
		for (int i=2; i<=n; i++)	
		{
			K=nwk[1],B=nwb[1];
			if (nwk[i]==0&&nwb[i]<B) return puts("-1"),0; 
			if (K==0&&nwb[i]>B) return puts("-1"),0;
			long long g=gcd(K,nwk[i]);
			if (g&&B%g!=nwb[i]%g) return puts("-1"),0;
			if (K==0||nwk[i]==0) B=(K==0?B:nwb[i]),K=0; else
			{
				if (B<nwb[i]) B+=((nwb[i]-B)/K+((nwb[i]-B)%K!=0))*K;
				B+=mul(nwk[i]-(B-nwb[i])/g%nwk[i],quickmi(K/g,phi-1,nwk[i]/g),nwk[i]/g)*K;
				K=K/g*nwk[i];
			}
			if (nwk[1]!=0) 
			{
				long long pb=(B-nwb[1])/nwk[1],pk=K/nwk[1];
				for (int j=0,sz=p[1].size(); j<sz; j++)
					b[1][j]+=k[1][j]*pb,k[1][j]*=pk;
				nwk[1]=k[1][nw[1]-1],nwb[1]=b[1][nw[1]-1];
			}
			if (nwk[i]!=0)
			{
				long long pb=(B-nwb[i])/nwk[i],pk=K/nwk[i];
				for (int j=0,sz=p[i].size(); j<sz; j++)
					b[i][j]+=k[i][j]*pb,k[i][j]*=pk;
			}
		}
	}
	ans=1;
	for (int i=0,sz=p[1].size(); i<sz; i++)
		ans=1ll*ans*quickmi(p[1][i],b[1][i],mod)%mod;
	printf("%d\n",ans);
	return 0;
}