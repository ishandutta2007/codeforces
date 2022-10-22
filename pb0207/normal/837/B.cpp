#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1e2+1e1+7;

int n,m;

char s[N][N];

int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		scanf("%s",s[i]+1);
	bool flag1=true;
	bool flag2=true;
	if(n%3==0)
	{
		if(s[1][1]==s[1][n/3+1]||s[1][1]==s[1][n/3*2+1]||s[1][n/3+1]==s[1][n/3*2+1])
			flag1=false;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n/3;j++)
				if(s[i][j]!=s[1][1])
				flag1=false;
		for(int i=1;i<=m;i++)
			for(int j=n/3+1;j<=n/3*2;j++)
				if(s[i][j]!=s[1][n/3+1])
				flag1=false;
		for(int i=1;i<=m;i++)
			for(int j=n/3*2+1;j<=n;j++)
				if(s[i][j]!=s[1][n/3*2+1])
				flag1=false;
	}
	if(m%3==0)
	{
		if(s[1][1]==s[m/3+1][1]||s[1][1]==s[m/3*2+1][1]||s[m/3+1][1]==s[m/3*2+1][1])
		flag2=false;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m/3;j++)
				if(s[j][i]!=s[1][1])
				flag2=false;
		for(int i=1;i<=n;i++)
			for(int j=m/3+1;j<=m/3*2;j++)
				if(s[j][i]!=s[m/3+1][1])
				flag2=false;
		for(int i=1;i<=n;i++)
			for(int j=m/3*2+1;j<=m;j++)
				if(s[j][i]!=s[m/3*2+1][1])
				flag2=false;
	}
	if(n%3!=0)
		flag1=false;
	if(m%3!=0)
		flag2=false;
	if(flag1||flag2)
		cout<<"YES";
	else
	cout<<"NO";
}