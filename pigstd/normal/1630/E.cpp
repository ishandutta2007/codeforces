#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int Mod=998244353;
const int M=1e6+10;
int n,t[M],d,tot,p[M],f1[M],f2[M],fac[M],ifac[M];
map<int,int>tt;

int poww(int a,int b=Mod-2)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

void work(int k)
{
	f2[k]=fac[n/k]; 
	for (int i=1;i<=tot;i++)
		f1[k]=(t[i]/k*(t[i]/k-1)%Mod*fac[n/k-2]%Mod*(n/k)+f1[k])%Mod;
	int p=f1[k]*poww(f2[k])%Mod;
//	cout<<k<<' '<<f1[k]<<' '<<f2[k]<<'\n';
	for (int i=1;i<=tot;i++)f2[k]=f2[k]*ifac[t[i]/k]%Mod;
	f1[k]=f2[k]*p%Mod*k%Mod;
//	cout<<k<<' '<<f1[k]<<' '<<f2[k]<<'\n';
}

void solve()
{
	n=read();tot=d=0;tt.clear();
//	n=997920;
	for (int i=1;i<=n;i++)t[i]=0;
//	t[1]=t[2]=n/2;
	for (int i=1;i<=n;i++)
	{
		p[i]=read();
		if (!tt[p[i]])tt[p[i]]=++tot;
		t[tt[p[i]]]++;
	}
	for (int i=1;i<=n;i++)
		if (t[i]==n)return puts("1"),void();
		else d=__gcd(d,t[i]);
	for (int i=1;i<=d;i++)
		if (d%i==0)work(i);
	for (int i=d;i>=1;i--)
		if (d%i==0)
			for (int j=i*2;j<=d;j+=i)f1[i]=(f1[i]-f1[j]+Mod)%Mod,f2[i]=(f2[i]-f2[j]+Mod)%Mod;
//	for (int i=1;i<)
	int sum1=0,sum2=0;
	for (int i=1;i<=d;i++)sum1=(sum1+f1[i]*i)%Mod,sum2=(sum2+f2[i]*i)%Mod;//,cout<<i<<' '<<f1[i]<<' '<<f2[i]<<'\n';
	for (int i=1;i<=d;i++)f1[i]=f2[i]=0;
//	cout<<sum1<<' '<<sum2<<'\n';
	cout<<(n-sum1*poww(sum2)%Mod+Mod)%Mod<<'\n';
}

 void init(int n)
 {
 	fac[0]=1;
	for (int i=1;i<=n;i++)fac[i]=fac[i-1]*i%Mod;
	ifac[n]=poww(fac[n],Mod-2);
	for (int i=n-1;i>=0;i--)ifac[i]=ifac[i+1]*(i+1)%Mod;
 }

signed main()
{
	init(1e6);
	WT solve();
	return 0;
}
/*
1
12
1 3 2 3 2 1 3 3 1 3 3 2
 
 nd(n)  
*/