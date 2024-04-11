//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,ans;
string s1,s2;
int main(){
	ll T,i;
	cin>>T;
	while(T--)
	{
		cin>>n>>s1>>s2;
		ans=0;
		for(i=0;i<n;i++)
		{
			if(s1[i]!=s2[i])
			{
				ans+=2;
				continue;
			}
			if(i+1<n)
			{
				if(s1[i]!=s1[i+1]&&s2[i]!=s2[i+1])
				{
					ans+=2;
					i++;
					continue;
				}
			}
			ans+=('1'-s1[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}