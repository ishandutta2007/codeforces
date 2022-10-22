#include<stdio.h>
#include<string.h>
char a[105];
int n[5];
int main()
{
	int len,r,b,g,y; 
	int i;
	gets(a);
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		if(a[i]=='R') 
		{
			r=i%4;
		}
		else if(a[i]=='B')
		{
			b=i%4;
		}
		else if(a[i]=='Y') 
		{
			y=i%4;
		}
		else if(a[i]=='G')
		{
			g=i%4;
		}
		else
		{
			n[i%4]++;
		}
	}
	printf("%d %d %d %d\n",n[r],n[b],n[y],n[g]);
	return 0;
}