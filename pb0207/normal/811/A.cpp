#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int a,b;

int main()
{
	scanf("%d%d",&a,&b);
	int aa=sqrt(a);
	if(b-aa*aa-aa<0)
		printf("Valera");
	else
		printf("Vladik");
}