#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
char s[2333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>(s+1);
		int cur=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='(')cur++;
			else cur--;
			if(cur<0)ans++,cur=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}