#include <stdio.h>
#include <stdlib.h>
using namespace std;
int a[102],b[102],n,m;
int main()
{
 	scanf("%d%d",&n,&m);
 	for(int i=0;i<102;i++)a[i]=b[i]=2;
 	a[n-1]=n-2;
 	b[m-1]=m-2;
 	if(n==1)a[0]=1;
 	if(n==2)a[0]=3,a[1]=4;
 	if(m==1)b[0]=1;
 	if(m==2)b[0]=3,b[1]=4;
 	for(int i=0;i<n;i++)
 	{
	 		for(int j=0;j<m;j++){printf("%d ",a[i]*b[j]);}
	 		printf("\n");
	}
	//system("pause");
	return 0;
}