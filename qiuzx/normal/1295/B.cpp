#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll val[N];
int main(){
	ll T,i,n,x,a,ans;
	string s;
	cin>>T;
	while(T--)
	{
		cin>>n>>x>>s;
		if(s[0]=='0')
		{
			val[0]=1;
		}
		else
		{
			val[0]=-1;
		}
		for(i=1;i<n;i++)
		{
			if(s[i]=='0')
			{
				val[i]=val[i-1]+1;
			}
			else
			{
				val[i]=val[i-1]-1;
			}
		}
		a=abs(val[n-1]);
		if(a==0)
		{
			for(i=0;i<n;i++)
			{
				if(val[i]==x)
				{
					cout<<-1<<endl;
					i=-1;
					break;
				}
			}
			if(i!=-1)
			{
				cout<<0<<endl;
			}
		}
		else
		{
			if(x==0)
			{
				ans=1;
			}
			else
			{
				ans=0;
			}
			for(i=0;i<n;i++)
			{
				if(abs(x-val[i])%a==0&&(val[n-1]>0&&x>=val[i]||val[n-1]<0&&x<=val[i]))
				{
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}