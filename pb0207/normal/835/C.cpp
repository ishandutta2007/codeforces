#include<cstdio>
#include<iostream>
using namespace std;

typedef long long ll;

const int N=2e5+1e3+7,inf=0x7fffffff;

int n,q,X[N],Y[N],ss[N],c,b[N],mm[11][101][101],sum[11][101][101];

int main()
{
	cin>>n>>q>>c;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d",X+i,Y+i,ss+i);
		mm[0][X[i]][Y[i]]+=ss[i];
	}
	for(int t=1;t<=c;++t)
	{
		for(int i=1;i<=n;++i)
		{
			ss[i]++;
			if(ss[i]==c+1)
				ss[i]=0;
		}
		for(int i=1;i<=n;++i)
		mm[t][X[i]][Y[i]]+=ss[i];
	}
	for(int t=0;t<=c;++t)
		for(int x=1;x<=100;++x)
			for(int y=1;y<=100;++y)
				sum[t][x][y]=sum[t][x-1][y]+sum[t][x][y-1]-sum[t][x-1][y-1]+mm[t][x][y];
	for(int kk=1;kk<=q;kk++)
	{
		int tm,aa,bb,cc,dd;
		cin>>tm>>aa>>bb>>cc>>dd;
		tm%=(c+1);
		cout<<sum[tm][cc][dd]-sum[tm][aa-1][dd]-sum[tm][cc][bb-1]+sum[tm][aa-1][bb-1]<<endl;
	}
}