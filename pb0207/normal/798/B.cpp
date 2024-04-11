#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=61;

int n,m,ans=0x7fffffff;

char s[N][N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]);
	m=strlen(s[1]);
	for(int i=0;i<m;i++)
		s[0][i]=s[1][i];
	for(int i=0;i<m;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			bool ok=false;
			for(int k=0;k<m;k++)
			{
				bool flag=true;
				for(int t=0;t<m;t++)
				{
					if(s[0][(t+i+m)%m]!=s[j][(t+k+m)%m])
						flag=false;
				}
				if(flag)
				{
					ok=true;
					cnt+=k;
					break;
				}
			}
			if(!ok)
			{
				cout<<"-1";
				return 0; 
			}
		}
		ans=min(ans,cnt);
	}
	cout<<ans;
}