#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,m;
		char s[510][510];
		scanf("%d%d",&n,&m);
		rep(i,n)scanf("%s",s[i]+1);
		int ans=0;
		rep(i,n)rep(j,m)ans+=s[i][j]-'0';
		bool flag=0;
		rep(i,n-1)rep(j,m)if(s[i][j]=='0'&&s[i+1][j]=='0')flag=1;
		rep(i,n)rep(j,m-1)if(s[i][j]=='0'&&s[i][j+1]=='0')flag=1;
		rep(i,n-1)rep(j,m-1)if(s[i][j]=='0'&&s[i+1][j+1]=='0')flag=1;
		rep(i,n-1)for(int j=2;j<=m;j++)if(s[i][j]=='0'&&s[i+1][j-1]=='0')flag=1;
		if(flag){printf("%d\n",ans);continue;}
		rep(i,n)rep(j,m)if(s[i][j]=='0')flag=1;
		if(flag){printf("%d\n",ans-1);continue;}
		printf("%d\n",ans-2);
	}
    return 0;
}