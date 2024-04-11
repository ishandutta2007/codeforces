#include <stdio.h>
#include <iostream>
int a[100006];
int main()
{
	int n,cur=1,max=1;
	scanf("%d",&n);
	scanf("%d",&a[0]);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>a[i-1]) cur++;
		else
		{
			max=max>cur?max:cur;
			cur=1;
		}
	}
	max=max>cur?max:cur;
	printf("%d",max);
	return 0;
}