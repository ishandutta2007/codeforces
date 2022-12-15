#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[4][400001],n,cnt0,cnt1,x,sum,s[4][400001],na[4],ans,f[400001],l1,l2;
char S[5];

bool cmp(int a,int b) {return a>b;}
int getmax(int a,int b) {return a>b?a:b;}

int main()
{
	scanf("%d",&n); cnt0=cnt1=na[0]=na[1]=na[2]=na[3]=sum=0;
	for (int i=1; i<=n; i++)
	{
		x=0; scanf("%s",S);
		if (S[0]=='1') x+=2,cnt1++; 
		if (S[1]=='1') x++,cnt0++;
		na[x]++; scanf("%d",&a[x][na[x]]);		
		sum+=a[x][na[x]];
	}
	if (cnt0*2>=n&&cnt1*2>=n) {printf("%d\n",sum); return 0;}
	for (int i=0; i<4; i++) 
	{
		s[i][0]=0;
		sort(a[i]+1,a[i]+1+na[i],cmp);
		for (int j=1; j<=na[i]; j++) s[i][j]=s[i][j-1]+a[i][j];
	}
	ans=s[3][na[3]]; if (na[0]>na[3]) na[0]=na[3];
	l1=l2=1; f[0]=0;
	for (int i=1; i<=na[0]+na[1]; i++)
	{
		if (l2==na[0]+1||(l1<=na[1]&&a[1][l1]>a[0][l2]))
		{
			if (l1<=na[1]) f[i]=f[i-1]+a[1][l1],l1++;
		} else
		{
			if (l2<=na[0]) f[i]=f[i-1]+a[0][l2],l2++;
		}
	}
	int an=0;
	for (int i=0; i<=na[2]&&i+na[3]<=na[0]+na[1]; i++) an=getmax(an,s[2][i]+f[i+na[3]]);
	l1=l2=1; f[0]=0;
	for (int i=1; i<=na[0]+na[2]; i++)
	{
		if (l2==na[0]+1||(l1<=na[2]&&a[2][l1]>a[0][l2]))
		{
			if (l1<=na[2]) f[i]=f[i-1]+a[2][l1],l1++;
		} else
		{
			if (l2<=na[0]) f[i]=f[i-1]+a[0][l2],l2++;
		}
	}
	for (int i=0; i<=na[1]&&i+na[3]<=na[0]+na[2]; i++) an=getmax(an,s[1][i]+f[i+na[3]]);
	printf("%d\n",ans+an);
	return 0;
}