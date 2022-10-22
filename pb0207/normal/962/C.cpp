#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;

const int N=101;

int n;

char s[N];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int ans=n+1;
	int all=(1<<n)-1;
	for(int S=1;S<=all;S++)
	{
		int tot=0,cnt=0;
		bool flag=true,vis=false;
		for(int i=1;i<=n;i++)
			if(S&(1<<(i-1)))
			{
				tot=tot*10+s[i]-'0',cnt++;
				if(!vis)
				{
					vis=true;
					if(s[i]=='0')
						flag=false;
				}
			}	
		if(!flag)
			continue;
		int j=sqrt(double(tot));
		if(j*j==tot)
			ans=min(ans,n-cnt);
	}
	printf("%d",ans==n+1?-1:ans);
}