#include<cstdio>
#include<iostream>
using namespace std;

double s,v1,v2,t1,t2;

int main()
{
	scanf("%lf%lf%lf%lf%lf",&s,&v1,&v2,&t1,&t2);
	if(s*v1+t1*2<s*v2+t2*2)
		printf("First");
	else
		if(s*v1+t1*2>s*v2+t2*2)
			printf("Second");
	else
		printf("Friendship");
}