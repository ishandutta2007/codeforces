#include <iostream>
#include <stdio.h>
#include <math.h>
int l[100007],r[100007];
int main(int argc, char** argv) 
{
	int n,ind=0,lu=0,ru=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
	    scanf("%d%d",&l[i],&r[i]);
	    lu+=l[i];
	    ru+=r[i];
	}
	int max=fabs(lu-ru);
	for(int i=1;i<=n;i++)
	{
		lu=lu-l[i]+r[i];
		ru=ru-r[i]+l[i];
		int t=fabs(lu-ru);
		if(t>max)
		{
			max=t;
			ind=i;
		}
		lu=lu+l[i]-r[i];
		ru=ru+r[i]-l[i];
	 } 
	 printf("%d",ind);
	return 0;
}