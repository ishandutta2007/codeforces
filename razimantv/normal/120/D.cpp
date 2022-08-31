#include"stdio.h"
int a[1000][1000],b[1000][1000];
int n,m,A,B,C,ans=0;
void solve()
{
	int s[m+100];
	for(int x=0;x<m;x++)
	{
		s[x]=0;
		for(int y=0;y<n;y++)
			s[x]+=a[y][x];
	}
	int sum1=0;
	for(int i=0;i<m;i++)
	{
		sum1+=s[i];
		int sum2=0;
		for(int j=i+1;j<m-1;j++)
		{
			sum2+=s[j];
			ans+=((sum1==A&&(sum2==B||sum2==C))||(sum1==B&&(sum2==A||sum2==C))||(sum1==C&&(sum2==B||sum2==A)));
//			printf("%d=>%d  %d=>%d %d\n",i,sum1,j,sum2,ans);
		}
	}
}
int main()
{
	freopen("input.txt", "rt", stdin); 
	freopen("output.txt", "wt", stdout);
	scanf("%d%d",&n,&m);
	int s=0;
	for(int x=0;x<n;x++)
		for(int y=0;y<m;y++)
			scanf("%d",&a[x][y]),s+=a[x][y];
	scanf("%d%d%d",&A,&B,&C);
	if(A+B+C!=s){printf("0");return 0;}
	solve();
	for(int x=0;x<n;x++)for(int y=0;y<m;y++)b[x][y]=a[x][y];
	for(int x=0;x<m;x++)for(int y=0;y<n;y++)a[x][y]=b[y][x];
	int k=m;m=n;n=k;
	solve();
	printf("%d",ans);
}