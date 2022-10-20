#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;

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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int l[N],a[N];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),k=read(),low=0;
	for (int i=1;i<=n;i++) l[i]=read();
	sort(l+1,l+1+n,greater<int>());
	while (n&&l[n]<=2) n--;
	a[0]++;
	a[1]--;
	for (int i=1;i<=n;i++)
	{
		l[i]--;
		while (!a[low]) low++;
		if (a[low]>=k) break;
		if (a[low]+a[low+1]+a[low]>=k) break;
		a[low]--;
		a[low+1]++;
		a[low+2]++;
		a[low+1+l[i]/2+1]--;
		a[low+2]++;
		a[low+1+(l[i]+1)/2+1]--;
	}
	while (low<=400000&&(a[low]+=a[low-1])<k) k-=a[low++];
	if (a[low]<k) puts("-1");
			 else print(low);
	
	return 0;
}