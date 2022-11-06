#include<bits/stdc++.h>
using namespace std;
int n,m;
char str[233333];
int l,r,cntl,cntr;
int main()
{
	ios_base::sync_with_stdio(false);
	scanf("%d",&n);
	scanf("%s",str);
	n=strlen(str);
	for(int i=0;i<n/2;i++)
	{
		if(isdigit(str[i]))l+=str[i]-'0';
		else cntl++;
	}
	for(int i=n/2;i<n;i++)
	{
		if(isdigit(str[i]))r+=str[i]-'0';
		else cntr++;
	}
	if(cntr<cntl)swap(cntl,cntr),swap(l,r);
	//cntr>=cntl
	cntr-=cntl;
	int w=cntr/2*9;
	if(r+w==l)printf("Bicarp\n");
	else printf("Monocarp\n");
	return 0;
}