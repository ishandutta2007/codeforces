#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=2e3+1e2+7;

int n,a[N];

int g[N][N],mn,cnt1;

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],cnt1+=(a[i]==1);
	mn=n+1;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			g[i][j]=gcd(a[j],g[i][j-1]);
			if(g[i][j]==1)
				mn=min(mn,j-i+1);
		}
	if(mn>n)
		cout<<-1;
	else
		cout<<mn-1+n-1-(cnt1-1)*(cnt1!=0);
}