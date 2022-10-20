#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int sum[N],ans,p;
int power(int a,int b)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=ret*a%p;
		a=a*a%p;
		b/=2;
	}
	return ret;
}
int calc(int x,int y)
{
	int ret=0;
	for (int i=1;i<=x;i++) ret=(ret+sum[i+y]-sum[i]+p)%p;
//	print(x,',');print(y,':');print(ret);
	return ret;
}
int tot[N][2];
void Count(int l,int r,int h,int Min)
{
	if (r-l+1==Min) tot[h][0]++;
			   else tot[h][1]++;
	if (h==1) return void(ans=(ans+(r-l+1)*(r-l)%p*power(4,p-2)%p)%p);
	if (l==r) return;
	int mid=(l+r)/2;
	Count(l,mid,h-1,Min/2);
	Count(mid+1,r,h-1,Min/2);
}
void merge_sort(int h,int Min)
{
	if (h<=0) return;
	if (h==1) ans=(ans+tot[h][0]*(tot[h][0]-1)/2%p*calc(Min,Min)%p+tot[h][1]*(tot[h][1]-1)/2%p*calc(Min+1,Min+1)%p+tot[h][0]*tot[h][1]%p*calc(Min,Min+1)%p)%p;
	merge_sort(h-1,Min/2);
}

signed main()
{
	memset(tot,0,sizeof(tot));
	int n=read(),k=read();
    p=read();
	for (int i=1;i<=n*2;i++) sum[i]=(sum[i-1]+power(2,p-2)-power(i,p-2)+p)%p;
	Count(1,n,k,n);
	merge_sort(k,n);
//	for (int i=1;i<=k;i++) print(tot[i][0],' '),print(tot[i][1]);
	print(ans);

	return 0;
}