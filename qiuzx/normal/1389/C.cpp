#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
string s;
ll dp[N][12],cnt[12],mn,mx;
int main(){
	ll T,i,j,k,tx,pre;
	cin>>T;
	while(T--)
	{
		cin>>s;
		for(i=0;i<s.size();i++)
		{
			for(j=0;j<10;j++)
			{
				cnt[j]=0;
				dp[i][j]=LINF;
			}
		}
		mx=0;
		for(i=0;i<s.size();i++)
		{
			cnt[s[i]-'0']++;
		}
		for(i=0;i<10;i++)
		{
			mx=max(mx,cnt[i]);
		}
		mn=0;
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				tx=0;
				pre=0;
				for(k=0;k<s.size();k++)
				{
					if(pre==0&&(int)(s[k]-'0')==i)
					{
						pre^=1;
						tx++;
					}
					else if(pre==1&&(int)(s[k]-'0')==j)
					{
						pre^=1;
						tx++;
					}
				}
				if(pre==0)
				{
					mn=max(mn,tx);
				}
			}
		}
		cout<<min((ll)s.size()-mn,s.size()-mx)<<endl;
	}
	return 0;
}