#include<bits/stdc++.h>
using namespace std;

long long sl,sr;
int n,a[500001],l,r,mid,ansl,ansr,b[500011],cl;
bool bo;

int check(int x)
{
	int po=0;
	for (int i=1; i<=n; i++) if (a[i]<x) po=i;
	for (int i=1; i<=po; i++) b[i]=a[i];
	b[po+1]=x,sl=sr=0,cl=0;
	for (int i=po+1; i<=n; i++) b[i+1]=a[i];
	for (int i=1; i<=n+1; i++) sr+=b[i];
	for (int i=1; i<=n; i++)
	{
		sr-=b[i];
		if (n+1-i<b[i]) cl++; else sl+=b[i];
		while (cl<i&&b[i-cl]>n+1-i) sl-=b[i-cl],cl++;
		if (sl+1ll*cl*(n+1-i)+1ll*(n+1-i)*(n-i)<sr) return (po+1<=i?-1:1);
	}
	return 0;
}

int main()
{
	scanf("%d",&n); bo=0;
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),bo^=(a[i]&1);
	sort(a+1,a+1+n);
	l=0; r=n/2; if (r*2+bo>n) r--; ansl=n+1;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check(2*mid+bo)>=0) ansl=mid,r=mid-1; else l=mid+1;
	}
	if (ansl==n+1||check(2*ansl+bo)!=0) return puts("-1"),0;
	l=0; r=n/2; if (r*2+bo>n) r--;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check(2*mid+bo)<=0) ansr=mid,l=mid+1; else r=mid-1;
	}
	for (int i=ansl; i<=ansr; i++) printf("%d ",i*2+bo); puts("");
	return 0;
}