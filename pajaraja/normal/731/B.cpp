#include <iostream>
#include <stdio.h>
int a[200001];
int main(int argc, char** argv) 
{
	int n;
	scanf("%d",&n);
	bool m=true;
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		if(a[i]<0) m=false;
		if(a[i]%2==1) a[i+1]--;
	}
	if(a[n-1]%2==1) m=false;
	if(m) printf("YES");
	else printf("NO");
	return 0;
}