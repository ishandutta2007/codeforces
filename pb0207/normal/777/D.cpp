#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N=5e5+1e3+7;

string p;

int n,m,ans[N];

vector<string>s;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>p;
		s.push_back(p);
	}
	for(int i=n-1;i>0;i--)
	{
		if(s[i]<s[i-1])
		{
			int nn=s[i].size();
			int mm=s[i-1].size();
			int j=0;
			while(j<min(nn,mm)&&s[i-1][j]<=s[i][j])
				j++;
			for(;j<mm;j++)
				s[i-1][j]=0;
		}
	}
	for(int i=0;i<=n-1;i++)
	{
		for(int j=0;j<s[i].size()&&s[i][j]!=0;j++)
			cout<<s[i][j];
		cout<<endl;
	}
			
}