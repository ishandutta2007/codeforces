#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=3e3+1e2+7;

int n,now,cnt;

char s[N];

bool vis[27];

bool chk(char ch)
{
	return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
}

/*
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;

map<string,int>m,c;

int n;

string s[70001];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		for(int t=0;t<s[i].size();t++)
			for(int j=t;j<s[i].size();j++)
				m[s[i].substr(t,j-t+1)]++;
	}
	for(int i=1;i<=n;i++)
	{
		c.clear();
		for(int t=0;t<s[i].size();t++)
			for(int j=t;j<s[i].size();j++)
				c[s[i].substr(t,j-t+1)]++;
		string ans;
		int now=11;
		for(int t=0;t<s[i].size();t++)
			for(int j=t;j<s[i].size();j++)
				if(m[s[i].substr(t,j-t+1)]-c[s[i].substr(t,j-t+1)]==0&&j-t+1<now)
					ans=s[i].substr(t,j-t+1),now=j-t+1;
		cout<<ans<<endl;
	}	
}
*/

int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)
	{
		if(chk(s[i]))
		{
			cout<<s[i];
			now=i+1;
			continue;
		}
		cnt=0;
		memset(vis,0,sizeof(vis));
		for(int j=now;j<=i;j++)
			vis[s[j]-'a']=1;
		for(int j=0;j<26;j++)
			if(vis[j])
				cnt++;
		if(cnt>1&&i-now+1>=3) 
		{
			cout<<" ";
			now=i;
		}
		cout<<s[i];
	}
}