#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int h,m,ans;

int main()
{
	scanf("%d:%d",&h,&m);
	int flag=true;
	for(int i=h;;i=(i+1)%24)
		for(int j=0;j<=59;j++)
		{
			if(flag)
				j=m,flag=false;
			int k=j,l=i;
			l=(l/10)+(l%10)*10;
			k=(k/10)+(k%10)*10;
			if(k==i&&j==l)
				goto ddd;
			ans++;
		}
	ddd:;
	cout<<ans;
}