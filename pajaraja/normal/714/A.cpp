#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(int argc, char** argv) 
{
	long long k,l1,l2,r1,r2;
	scanf("%I64d%I64d%I64d%I64d%I64d",&l1,&r1,&l2,&r2,&k);
	long long maxl=max(l1,l2),minr=min(r1,r2);
	long long rez=minr-maxl+1;
	if(k>=maxl&&k<=minr) rez--;
	rez=max(rez,0LL);
	printf("%I64d",rez);
	return 0;
}