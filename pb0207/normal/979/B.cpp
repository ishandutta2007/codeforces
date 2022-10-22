#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=3e5+1e3+7;

int n;

char a[N],b[N],c[N];

int la,lb,lc;

int wa,wb,wc,mx,ca[257],cb[257],cc[257];

int main()
{
	scanf("%d",&n);
	scanf("%s",a+1);
	scanf("%s",b+1);
	scanf("%s",c+1); 
	int len=strlen(a+1);
	for(int i=1;i<=len;i++)
		ca[a[i]]++,cb[b[i]]++,cc[c[i]]++;
	for(int i='A';i<='z';i++)
		if(ca[i]+n>len)
			wa=max(wa,len-(n==1));
		else
			wa=max(wa,n+ca[i]);
	for(int i='A';i<='z';i++)
		if(cb[i]+n>len)
			wb=max(wb,len-(n==1));
		else
			wb=max(wb,n+cb[i]);
	for(int i='A';i<='z';i++)
		if(cc[i]+n>len)
			wc=max(wc,len-(n==1));
		else
			wc=max(wc,n+cc[i]);
	mx=0;
	int cmx=0;
	if(wa>mx)
		mx=wa;
	if(wb>mx)
		mx=wb;
	if(wc>mx)
		mx=wc;
	cmx=(wa==mx)+(wb==mx)+(wc==mx);
	if(cmx>1)
	{
		puts("Draw");
		return 0;
	}
	if(wa==mx)
		puts("Kuro");
	if(wb==mx)
		puts("Shiro");
	if(wc==mx)
		puts("Katie");
}