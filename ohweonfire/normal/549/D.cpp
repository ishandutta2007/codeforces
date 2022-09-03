#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
const int maxn=105;
int n,m,a[maxn][maxn];
char s[maxn][maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	int ans=0;
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--)
			if(s[i][j]=='W'&&a[i][j]!=1||s[i][j]=='B'&&a[i][j]!=-1)
			{
				int tmp;
				if(s[i][j]=='W')tmp=1-a[i][j];else tmp=-1-a[i][j];
				for(int p=1;p<=i;p++)
					for(int q=1;q<=j;q++)
						a[p][q]+=tmp;
				ans++;
			}
	cout<<ans<<endl;
	return 0;
}