#include<cstdio>
#include<iostream>
using namespace std;

char s[]={'^','>','v','<'},a,b;

int n; 

int main()
{
	cin>>a;
	getchar();
	cin>>b;
	cin>>n;
	int k=n%4,tmpa,tmpb;
	for(int i=0;i<=3;i++)
	{
		if(s[i]==a)
			tmpa=i;
		if(s[i]==b)
			tmpb=i;
	}
	if((tmpa+k)%4==tmpb&&(tmpa-k+4)%4==tmpb)
	puts("undefined");
	else
	if((tmpa+k)%4==tmpb)
		puts("cw");
	else
		if((tmpa-k+4)%4==tmpb)
			puts("ccw");
	else
		puts("undefined");
}