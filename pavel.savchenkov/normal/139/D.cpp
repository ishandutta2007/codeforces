#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int go(int n,int a[10],int b[10])
{
	if (min(a[n],b[10-n])==0) return min(a[0],b[0]);
	int aa[10]; int bb[10];
	for (int i=0;i<=9;i++) { aa[i]=a[i]; bb[i]=b[i]; }
	aa[n]--; bb[10-n]--;
	int res=0;
	for (int i=0;i<=9;i++)
	{ 
		int m = min(aa[i],bb[9-i]);
	    res+=min(aa[i],bb[9-i]);
		aa[i]-=m; bb[9-i]-=m;
	}
	return res + min(aa[0],bb[0]) + 1;
};

int main() {
	//freopen("input.txt","r",stdin);
	int a[10]; int b[10];
	char c;
	for (int i=0;i<=9;i++) { a[i]=0; b[i]=0; }
	while (scanf("%c",&c)==1) { a[c-'0']++;b[c-'0']++; }
	int max=-1; int x=-1;
	for (int i=1;i<=9;i++)
	{
		int m=go(i,a,b);
		if (m>max) { max=m;x=i;}
	}
	//cout<<x<<" "<<max<<endl;
	int a10=-1; int b10=-1; int a9[10]; int b9[10]; int a0=-1; int b0=-1;
	for (int i=0;i<=9;i++) { a9[i]=0; b9[i]=0; }
	
	if (min(a[x],b[10-x])!=0) { a[x]--;b[10-x]--;a10=x; b10=10-x; }

    for (int i=9;i>=0;i--)
	{
		int m=min(a[i],b[9-i]);
		a9[i]+=m;b9[9-i]+=m;
		a[i]-=m; b[9-i]-=m;
	}		
	a0=min(a[0],b[0]); b0=a0; a[0]-=a0; b[0]-=b0;
	
	for (int i=9;i>=0;i--)
		for (int j=1;j<=a[i];j++)
			putchar(i+'0');

	for (int i=0;i<=9;i++)
		for (int j=1;j<=a9[i];j++)
			putchar(i+'0');

	if (a10!=-1) putchar(a10+'0');

	for (int j=1;j<=a0;j++)
		putchar('0');
	printf("\n");
	
	
	for (int i=9;i>=0;i--)
		for (int j=1;j<=b[i];j++)
			putchar(i+'0');

	for (int i=9;i>=0;i--)
		for (int j=1;j<=b9[i];j++)
			putchar(i+'0');

	if (b10!=-1) putchar(b10+'0');

	for (int j=1;j<=b0;j++)
		putchar('0');
	return 0;
}