#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int N=5e3+1e2+7;

char s[N];

int cnt[26][N][26],c[26];

double ans;

int main()
{
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n;i++)
	{
		c[s[i]-'a']++;
		for(int j=0;j<n;j++)
			cnt[s[i]-'a'][j][s[(i+j)%n]-'a']++;
	}
	for(int i=0;i<26;i++)
	{
		double mx=0;
		for(int j=1;j<n;j++)
		{
			int w=0;
			for(int k=0;k<26;k++)
				if(cnt[i][j][k]==1)
					w++;
			mx=max(mx,(double)w/(double)n);
		}
		ans+=mx;
	}
	printf("%.12lf",ans);
}