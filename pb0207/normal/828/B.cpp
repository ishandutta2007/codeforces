#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e2+1e1+7;

int ans=0x7fffffff;

int n,m,tot;

char s[N][N];

int chk(int x,int y,int l)
{
	int tmp=0;
	for(int i=x;i<=x+l-1;i++)
		for(int j=y;j<=y+l-1;j++)
			tmp+=(s[i][j]=='B');
	if(tmp==tot)
		return l*l-tmp;
	else
		return 0x7fffffff;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>s[i][j],tot+=(s[i][j]=='B');
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=min(n-i+1,m-j+1);k++)
			{
				ans=min(ans,chk(i,j,k));
			}
	cout<<(ans==0x7fffffff?-1:ans);
}