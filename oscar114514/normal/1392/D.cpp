#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
char s[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		cin>>(s+1);
		int ans=0,L=0,R=0,cnt=0;
		for(int i=1;i<=n;i++)if(s[1]==s[i])L=i;else break;
		if(L==n)cout<<(n+2)/3<<endl;
		else
		{
			for(int i=n;i>=1;i--)if(s[n]==s[i])R=i;else break;
			char cur=s[L+1];cnt=1;
			for(int i=L+2;i<R;i++)
			{
				if(s[i]==cur)cnt++;
				else
				{
					ans+=cnt/3;
					cnt=1;cur=s[i];
				}
			}
			ans+=cnt/3;
			if(s[1]==s[n])ans+=(L+(n-R+1))/3;
			else ans+=L/3+(n-R+1)/3;
			cout<<ans<<endl;
		}
	}
	return 0;
}