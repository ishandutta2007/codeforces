#include<bits/stdc++.h>
using namespace std;
char s[200010];
int num[200010][30];
int main()
{
	cin>>(s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;i++)
	{
		for(int j=0;j<26;j++)
			if(j==s[i]-'a')
				num[i][j]=num[i-1][j]+1;
			else
				num[i][j]=num[i-1][j];
	}
	int q;
	cin>>q;
	while(q--)
	{
		int t1,t2;
		cin>>t1>>t2;
		if(t1==t2)
		{
			cout<<"Yes\n";
			continue;
		}
		int x=0;
		for(int i=0;i<26;i++)
			if(num[t1-1][i]!=num[t2][i])
				x++;
		if(x>=3)
		{
			cout<<"Yes\n";
			continue;
		}
		if(s[t1]!=s[t2])
		{
			cout<<"Yes\n";
			continue;
		}
		cout<<"No\n";
	}
}