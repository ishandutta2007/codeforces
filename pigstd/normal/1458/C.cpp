#include<bits/stdc++.h>
using namespace std;

const int M=1e3+10;
int T,n,m;
string s;
int a[M][M][3],b[M][M];
int f[3],o[M],p[M];

int main()
{
	cin>>T;
	while(T--)
	{
		for (int i=0;i<3;i++)o[i]=i,f[i]=0;
		cin>>n>>m;
		for (int i=0;i<n;i++)	
			for (int j=0;j<n;j++)
				cin>>a[i][j][2],a[i][j][2]--,
				a[i][j][0]=i,a[i][j][1]=j;
		cin>>s;
		for (int i=0;i<m;i++)
		{
			if (s[i]=='R')f[1]++;
			if (s[i]=='L')f[1]--;
			if (s[i]=='D')f[0]++;
			if (s[i]=='U')f[0]--;
			if (s[i]=='I')swap(o[1],o[2]),swap(f[1],f[2]);
			if (s[i]=='C')swap(o[0],o[2]),swap(f[0],f[2]);
		}
		for (int i=0;i<3;i++)f[i]=((f[i]%n)+n)%n;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				for (int k=0;k<3;k++)p[k]=(a[i][j][o[k]]+f[k])%n;
				b[p[0]][p[1]]=p[2];
			}
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
				cout<<b[i][j]+1<<' ';
			puts("");
		}
		puts("");
	}
	return 0;
}