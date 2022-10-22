#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int N=2e3+1e2+7,P=1e9+7;

char s[N];

int k,bit[N],ans[N],C[N][N],f[N][N];

void calc(int x)
{
	int r=x;
	while(x!=1)
		ans[r]++,x=bit[x];
}

void pre()
{
	C[0][0]=1;
	for(int i=1;i<=2000;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
	}
}

int main()
{
	for(int i=1;i<=2000;i++)
		bit[i]=bit[i>>1]+(i&1);
	pre();
	scanf("%s",s);
	int n=strlen(s);
	scanf("%d",&k);
	if(k==0)
	{
		puts("1");
		return 0;
	}
	for(int i=1;i<=2000;i++)
		calc(i);
	f[n][0]=1;
	for(int i=n-1;i>=0;i--)
		for(int j=0;j<=n;j++)
		{
			if(s[i]=='0')
				f[i][j]=f[i+1][j];
			else
			{
				if(j==0)
					f[i][j]=C[n-i-1][j];
				else
					f[i][j]=(f[i+1][j-1]+C[n-i-1][j])%P;
			}
		}
	int tot=0;
	for(int i=1;i<=2000;i++)
		if(ans[i]==k-1)
			tot=(tot+f[0][i])%P;
	printf("%d",(tot-(k==1)+P)%P);
}