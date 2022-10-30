#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int max(int a, int b)
{
	return a>b?a:b;
}
int main(int argc, char** argv) 
{
	int n,c,l=0,r=0,t=0;
	scanf ("%d %d",&n, &c);
	int a[n],b[n];
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	for (int i=0;i<n;i++)
	{
		t+=b[i];
		l+=max(a[i]-t*c,0);
	}
	t=0;
	for (int i=n-1;i>=0;i--)
	{
		t+=b[i];
		r+=max(a[i]-t*c,0);
	}
	if (l>r) printf ("Limak");
	if (r>l) printf ("Radewoosh");
	if(l==r) printf ("Tie");
	return 0;
}