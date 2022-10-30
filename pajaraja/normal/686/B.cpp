#include <iostream>
#include <stdio.h>
int a[100];
int swap(int i,int j)
{
	int d=a[i];
	a[i]=a[j];
	a[j]=d;
}
int main(int argc, char** argv) 
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1]) 
			{    
			    swap(j,j+1);
			    printf("%d %d\n", j+1,j+2);
		    }
		}
	}
	return 0;
}