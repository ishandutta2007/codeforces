#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct Caj
{
	long long k;
	char b;
};
bool cmp(Caj a,Caj b){return a.k<b.k;}
int main(int argc, char** argv) 
{
	long long n,k,cnt=0,tr;
	Caj a[2];
	scanf("%I64d%I64d%I64d%I64d",&n,&k,&a[0].k,&a[1].k);
	a[0].b='G';
	a[1].b='B';
	sort(a,a+2,cmp);
	if((a[0].k+1)*k<a[1].k) 
	{
		printf("NO");
		return 0;
	}
	tr=a[1].k-(a[1].k/(a[0].k+1))*(a[0].k+1);
	for(int i=0;i<a[0].k;i++)
	{
		for(int j=0;j<(a[1].k/(a[0].k+1))+(tr>0);j++) printf("%c",a[1].b);
		tr--;
		printf("%c",a[0].b);
	}
	for(int j=0;j<(a[1].k/(a[0].k+1))+(tr>0);j++) printf("%c",a[1].b);
	return 0;
}