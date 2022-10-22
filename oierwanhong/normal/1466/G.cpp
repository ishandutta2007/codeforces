#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 2000011,mod = 1e9+7;
ll Qpow(ll a,ll p)
{
	ll res=1;
	while(p){if(p&1)res=res*a%mod;a=a*a%mod,p>>=1;}
	return res;
}
char s0[MAXN],s[MAXN],myy[MAXN], t[MAXN],a[MAXN];
int nxt[MAXN],sum[100011][26],pw2[100011];
void get_nxt(int n)
{
	int j=0;
	for(int i=2;i<=n;++i)
	{
		while(j&&a[j+1]!=a[i])j=nxt[j];
		if(a[j+1]==a[i])++j;
		nxt[i]=j;
	}
}
int kmp(char* s,int n,int m)
{
	int j=0,res=0;
	for(int i=1;i<=n;++i)
	{
		while(j&&a[j+1]!=s[i])j=nxt[j];
		if(a[j+1]==s[i])++j;
		if(j==m)++res,j=nxt[j];
	}
	return res;
}
int main()
{
	int n=read(),m=read();
	scanf("%s%s",s0+1,t+1);
	int l=strlen(s0+1);
	pw2[0]=1;
	for(int i=1;i<=n;++i)pw2[i]=pw2[i-1]*2%mod;
	for(int i=1;i<=n;++i)
	{
		memcpy(sum[i],sum[i-1],sizeof sum[i]);
		int c=t[i]-'a';
		sum[i][c]=(sum[i][c]+Qpow(pw2[i],mod-2))%mod;
	}
	while(m--)
	{
		int k=read();
		scanf("%s",a+1);
		memcpy(s+1,s0+1,l);
		int la=strlen(a+1),ls=l,it=1;
		while(it<=k&&ls<=la)
		{
			memcpy(s+ls+2,s+1,ls);
			s[ls+1]=t[it++];
			ls=ls<<1|1;
		}
		if(ls<la){puts("0");continue;}
		s[ls+1]=0;
		int ans=0,ml=0;
		//not cross part
		get_nxt(la);
		//cross part
		for(int i=1;i<la;++i)myy[++ml]=s[ls-la+i+1];
		++ml;
		for(int i=1;i<la;++i)myy[++ml]=s[i];
		//printf("Preans=%d\n",ans);
		for(int c=0;c<26;++c)
			if(sum[k][c]-sum[it-1][c])
			{
				myy[la]='a'+c;
				ans=(ans+ll(sum[k][c]-sum[it-1][c])*kmp(myy,ml,la))%mod;
			}

		printf("%lld\n",((ll(ans)*pw2[k]+ll(pw2[k-it+1])*kmp(s,ls,la))%mod+mod)%mod);
	}
	return 0;
}