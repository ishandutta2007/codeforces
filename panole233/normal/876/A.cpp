#include<cstdio>
#include<cstring>

int f[101][4],a[4][4],n;

int getmin(int a,int b) {return a<b?a:b;}

int main()
{
	scanf("%d",&n); scanf("%d%d%d",&a[1][2],&a[1][3],&a[2][3]); 
	a[2][1]=a[1][2]; a[3][1]=a[1][3]; a[3][2]=a[2][3];
	f[1][1]=0; f[1][2]=f[1][3]=1e9;
	for (int i=2; i<=n; i++)
	{
		f[i][1]=getmin(f[i-1][2]+a[2][1],f[i-1][3]+a[3][1]);
		f[i][2]=getmin(f[i-1][1]+a[1][2],f[i-1][3]+a[3][2]);
		f[i][3]=getmin(f[i-1][1]+a[1][3],f[i-1][2]+a[2][3]);
	}
	printf("%d\n",getmin(getmin(f[n][1],f[n][2]),f[n][3]));
}