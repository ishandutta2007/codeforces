#include<bits/stdc++.h>
using namespace std;

int b,k,x,nw; 

int main()
{
	nw=0; scanf("%d%d",&b,&k);
	for (int i=1; i<=k; i++) scanf("%d",&x),nw=((nw*b+x)&1);
	if (nw) puts("odd"); else puts("even");
	return 0;
}