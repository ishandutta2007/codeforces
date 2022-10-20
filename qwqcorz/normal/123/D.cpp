#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
char a[N];
int h[N],sa[N],rk[N],tp[N],cnt[N];
void get_height(char *a,int n)
{
	for (int i=1,k=0;i<=n;i++)
	{
		if (k) k--;
		while (a[i+k]==a[sa[rk[i]-1]+k]) k++;
		h[rk[i]-1]=k;
	}
}
void Bin_Sort(int n)
{
	for (int i=0;i<=max(n,128);i++) cnt[i]=0;
	for (int i=1;i<=n;i++) cnt[rk[i]]++;
	for (int i=1;i<=max(n,128);i++) cnt[i]+=cnt[i-1];
	for (int i=n;i>=1;i--) sa[cnt[rk[tp[i]]]--]=tp[i];
}
void Suffix_Sort(char *a,int n)
{
	for (int i=1;i<=n;i++) rk[i]=a[i],tp[i]=i;
	Bin_Sort(n);
	for (int w=1,p=0;p<n;w*=2)
	{
		for (int i=(p=0,n-w+1);i<=n;i++) tp[++p]=i;
		for (int i=1;i<=n;i++) if (sa[i]>w) tp[++p]=sa[i]-w;
		Bin_Sort(n);
		swap(rk,tp);
		for (int i=(rk[sa[1]]=p=1)+1;i<=n;i++) rk[sa[i]]=(tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+w]==tp[sa[i-1]+w])?p:++p;
	}
	get_height(a,n);
}
int L[N],R[N],st[N],top=0;

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	scanf("%s",a+1);
	int n=strlen(a+1);
	Suffix_Sort(a,n);
	ll ans=1LL*n*(n+1)/2;
	st[top=0]=0;
	for (int i=1;i<n;i++)
	{
		while (top&&h[st[top]]>h[i]) top--;
		L[i]=st[top]+1;
		st[++top]=i;
	}
	st[top=0]=n;
	for (int i=n-1;i>=1;i--)
	{
		while (top&&h[st[top]]>=h[i]) top--;
		R[i]=st[top]-1;
		st[++top]=i;
	}
//	for (int i=1;i<n;i++) print(L[i],' ');puts("");
//	for (int i=1;i<n;i++) print(R[i],' ');puts("");
	for (int i=1;i<n;i++) ans+=1LL*h[i]*(i-L[i]+1)*(R[i]-i+1);
	print(ans);

	return 0;
}