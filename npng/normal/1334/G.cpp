#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=200005,E=262144;
int R[N*4];
long long qpow(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*a%M;
		a=a*a%M;
		b>>=1;
	}
	return ans;
}
long long wn[N*4],iwn[N*4];
void init()
{
	int i;
	iwn[E/2]=wn[E/2]=1;
	long long s1=qpow(3,(M-1)/E);
	long long s2=qpow(s1,M-2);
	for(i=E/2+1;i<E;++i)
	{
		wn[i]=wn[i-1]*s1%M;
		iwn[i]=iwn[i-1]*s2%M;
	}
	for(i=E/2-1;i;--i)
	{
		wn[i]=wn[i<<1];
		iwn[i]=iwn[i<<1];
	}
}
void NTT(long long *f,int lim,int op)
{
	int i,j,k;
	for(i=0;i<lim;++i)
	{
		R[i]=(R[i>>1]>>1)|(i&1?lim>>1:0);
		if(R[i]<i)
			swap(f[R[i]],f[i]);
	}
	for(i=1;i<lim;i<<=1)
		for(j=0;j<lim;j+=(i<<1))
			for(k=j;k<j+i;++k)
			{
				long long a=f[k],b=f[k+i];
				long long w=(op==1?wn[k-j+i]:iwn[k-j+i]);
				f[k]=(a+b*w)%M;
				f[k+i]=(a-b*w)%M;
			}
	if(op==-1)
	{
		long long inv=qpow(lim,M-2);
		for(i=0;i<lim;++i)
			f[i]=f[i]*inv%M;
	}
}
void mult(long long *a,int n,long long *b,int m)
{
	int lim=1;
	while(lim<m)
		lim<<=1;
	for(int i=n;i<lim;++i)
		a[i]=0;
	for(int i=m;i<lim;++i)
		b[i]=0;
	NTT(a,lim,1);
	NTT(b,lim,1);
	for(int i=0;i<lim;++i)
		a[i]=a[i]*b[i]%M;
	NTT(a,lim,-1);
}
int p[66],k,i,n,m,pre[N];
char s[N],t[N];
long long a[N*4],b[N*4],sum,vis[66];
int main(){
	init();
	for(i=0;i<26;++i){
		scanf("%d",&p[i]);
		--p[i];
	}
	scanf("%s",s);
	scanf("%s",t);
	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
	for(i=0;i<26;++i)
		for(int j=i;!vis[j];j=p[j])
			vis[j]=rnd()%M;
	n=strlen(s);
	m=strlen(t);
	reverse(s,s+n);
	for(int i=0;i<n;++i){
		a[i]=(-vis[s[i]-'a']-vis[p[s[i]-'a']])%M;
		sum=(sum+vis[s[i]-'a']*vis[p[s[i]-'a']])%M;
	}
	for(int i=0;i<m;++i){
		b[i]=vis[t[i]-'a'];
		pre[i]=vis[t[i]-'a']*vis[t[i]-'a']%M;
	}
	for(int i=1;i<m;i++){
		pre[i]=(pre[i-1]+pre[i])%M;
	}
	mult(a,n,b,m);
	for(int i=n-1;i<m;i++){
		if((a[i]+pre[i]-(i-n>=0?pre[i-n]:0)+sum)%M==0){
			putchar('1');
		}
		else{
			putchar('0');
		}
	}
	return 0;
}