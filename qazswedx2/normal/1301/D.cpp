#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,k,fl=1,t;
char tans[3005][105];
void print(int x,const char *s)
{
	if(!k||!x) return;
	int nw=strlen(s);
	if(nw*x<=k)
	{
		++t;
		sprintf(tans[t],"%d %s\n",x,s);
		k-=nw*x;
	}
	else
	{
		if(k>=nw) 
		{
			++t;
			sprintf(tans[t],"%d %s\n",k/nw,s);
		}
		k%=nw;
		if(k==0) return;
		++t;
		sprintf(tans[t],"1 ");
		for(int i=0;i<k;i++)
			tans[t][i+2]=s[i];
		k=0;
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	if(k>4*n*m-2*n-2*m)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(int i=1;i<n;i++)
	{
		print(m-1,"RDU");
		print(m-1,"L");
		print(1,"D");
	}
	print(m-1,"R");
	print(m-1,"L");
	print(n-1,"U");
	printf("%d\n",t);
	for(int i=1;i<=t;i++)
		printf("%s",tans[i]);
	return 0;
}