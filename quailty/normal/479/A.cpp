#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int max(int a,int b)
{
	if(a>b)return a;
	else return b;
}
int main()
{
	int a,b,c,result;
	scanf("%d%d%d",&a,&b,&c);
	result=a+b+c;
	result=max(a*b+c,result);
	result=max(a+b*c,result);
	result=max(a*b*c,result);
	result=max((a+b)*c,result);
	result=max(a*(b+c),result);
	printf("%d\n",result);
	return 0;
}