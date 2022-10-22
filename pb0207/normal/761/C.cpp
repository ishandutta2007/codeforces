#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

char s[51][51];

int n,m,ans=0x7fffffff;

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(i!=j&&j!=k&&k!=i)
				{
					int tot1=61,tot2=61,tot3=61;
					for(int l=0;l<m;l++)
						if(s[i][l]>='0'&&s[i][l]<='9')
							tot1=min(tot1,min(l,m-l));
					for(int l=0;l<m;l++)
						if(s[j][l]>='a'&&s[j][l]<='z')
							tot2=min(tot2,min(l,m-l));
					for(int l=0;l<m;l++)
						if(s[k][l]=='#'||s[k][l]=='*'||s[k][l]=='&')
							tot3=min(tot3,min(l,m-l));
					ans=min(ans,tot3+tot2+tot1);
				}
	cout<<ans;
}