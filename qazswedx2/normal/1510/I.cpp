#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
int n,m,c[10005];
double a[10005],B=1.003;
char s[100005];
int main()
{
	srand(time(0));
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		a[i]=1;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		double sum0=0,sum1=0;
		for(int j=1;j<=m;j++)
		{
			if(sum<1.2*c[j]) continue;
			if(s[j]=='0') sum0+=a[j];
			else sum1+=a[j];
		}
	//	printf("sum0=%f,sum1=%f\n",sum0,sum1);
		int k;
		if(1.0*rand()/RAND_MAX*(sum0+sum1)<=sum0) k=0,printf("0\n");
		else k=1,printf("1\n");
		fflush(stdout);
		char ch;
		scanf(" %c",&ch);
		if(k+'0'!=ch) sum++;
		for(int j=1;j<=m;j++)
			if(s[j]==ch) a[j]*=B;
			else c[j]++;
	}
	return 0;
}