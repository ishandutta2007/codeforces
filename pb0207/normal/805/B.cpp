#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

char s[]="aabb";

int n;

int main()
{
	scanf("%d",&n);
	while(n>=4)
	{
		n-=4;
		printf("%s",s);
	}
	if(n==1)
		printf("a");
	if(n==2)
		printf("aa");
	if(n==3)
		printf("aab");	
}