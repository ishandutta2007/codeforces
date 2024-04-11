#include<cstdio>
#include<cstring>

const int mod=10000003;

struct node
{
	long long x;
	int ord;
}hash[mod];

int n,y;
char s[70001][10],ss[10];
bool bo;
long long ans[70001],x;

void add(int z)
{
	x=0;
	for (int i=0; i<9; i++)
		if (ss[i]!='?') x=x*11ll+ss[i]-47ll; 
		else break;
	y=x%mod;
	while (hash[y].ord!=0&&hash[y].x!=x) y=(y+1)%mod;
	if (hash[y].ord!=0&&hash[y].ord!=z) hash[y].ord=-1; else hash[y].x=x,hash[y].ord=z;
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%s",&s[i]);
	for (int i=0; i<mod; i++) hash[i].ord=0;
	for (int i=1; i<=n; i++)
		for (int j=0; j<9; j++)
		{
			for (int k=0; k<9; k++) ss[k]='?';
			for (int k=j; k<9; k++)
			{
				ss[k-j]=s[i][k];
				add(i);
			}
		}
	for (int i=1; i<=n; i++) ans[i]=1e16;
	for (int i=0; i<mod; i++)
		if (hash[i].ord!=-1&&hash[i].ord!=0&&ans[hash[i].ord]>hash[i].x) ans[hash[i].ord]=hash[i].x;
	for (int i=1; i<=n; i++)
	{
		int len=0;
		ss[len]=ans[i]%11+47; ans[i]/=11;
		while (ans[i]) ss[++len]=ans[i]%11+47,ans[i]/=11;
		for (int j=len; j>=0; j--) putchar(ss[j]); puts("");
	}
	return 0;
}