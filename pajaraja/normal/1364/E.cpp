#include <bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
int n;
int nz[5000],p[5000];
bool nd[5000];
int odredi(int x)
{
	int cur=4095;
	for(int i=0;i<17;i++)
	{
		int a=rng()%n+1;
		if(a==x) {i--; continue;}
		printf("? %d %d\n",a,x); fflush(stdout);
		int tmp; scanf("%d",&tmp);
		cur&=tmp;
	}
	nz[x]=cur; nd[x]=true;
	return cur;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) p[i]=i;
	shuffle(p+1,p+1+n,rng);
	int t=2,cur=odredi(p[1]),ind=p[1];
	while(cur!=0) 
	{
		printf("? %d %d\n",p[t],ind); fflush(stdout);
		int tmp; scanf("%d",&tmp);
		if((tmp|cur)==cur) {ind=p[t]; cur=odredi(p[t]);}
		t++;
	}
	for(int i=1;i<=n;i++)
	{
		if(nd[i]) continue;
		printf("? %d %d\n",ind,i); fflush(stdout);
		scanf("%d",&nz[i]);
	}
	printf("! ");
	for(int i=1;i<=n;i++) printf("%d ",nz[i]);
	printf("\n"); fflush(stdout);
}