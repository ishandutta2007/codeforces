#include<cstdio>
#include<iostream>
using namespace std;

const int N=2e3+1e2+7;

int n,m,ans=N*2+1,pos[N];

char s[N],t[N];

int main()
{
	cin>>n>>m;
	scanf("%s%s",s,t);
	for(int i=0;i<m-n+1;i++)
	{
		int now=0;
		for(int j=0;j<n;j++)
			if(s[j]!=t[i+j])
				now++;
		if(now<ans)
			ans=now,pos[0]=i;
	}
	int tot=0;
	for(int i=0;i<n;i++)
		if(s[i]!=t[i+pos[0]])
			pos[++tot]=i;
	cout<<ans<<endl;
	for(int i=1;i<=tot;i++)
		cout<<pos[i]+1<<" ";
}