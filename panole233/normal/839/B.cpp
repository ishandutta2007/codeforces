#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n,k,a[101],nn,j,l,x;

int main()
{
	scanf("%d%d",&n,&k); nn=n;
	for (int i=1; i<=k; i++) scanf("%d",&a[i]);
	for (int i=1; i<=k; i++)
		while (a[i]>=4) nn--,a[i]-=4;
	if (nn<=0)
	{
		nn=n*2+2*nn;
		for (int i=1; i<=k; i++) 
			nn-=(a[i]+1)/2;
		if (nn<0) {printf("NO"); return 0;}
		else {printf("YES"); return 0;}
	}
	sort(a+1,a+1+k);
	j=k;
	while (a[j]==3) nn--,a[j]=0,j--;
	if (nn<=0)
	{
		nn=2*n+2*nn;
		for (int i=1; i<=k; i++) 
			nn-=(a[i]+1)/2;
		if (nn<0) {printf("NO"); return 0;}
		else {printf("YES"); return 0;}
	}
	l=1; a[0]=0;
	while (a[l]==0) l++;
	x=0;
	while (a[j]==2) 
	{
		nn--,a[j]=0,j--; 
		if (nn>=0)
		{
			if (a[l]==1) l++;
			else x++;
		}
	}
	if (a[l]!=1)
	{
		if (0>nn+2*n+x/2) printf("NO"); else printf("YES");
		return 0;
	}
	if (nn<0) nn=nn+2*n+x; else nn=nn*2+2*n+x;
	while (nn>0&&a[l]==1) nn--,l++;
	if (a[l]!=1) printf("YES"); else printf("NO");
	return 0;
}