#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll t,n,k;
string s;
char buf[N];
int main(){
	ll i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		scanf("%s",&buf);
		s=buf;
		sort(s.begin(),s.end());
		if(s[k-1]!=s[0])
		{
			cout<<s[k-1]<<endl;
			continue;
		}
		cout<<s[0];
		if(k==n)
		{
			puts("");
			continue;
		}
		if(s[n-1]==s[k])
		{
			for(i=0;i<(n-1)/k;i++)
			{
				cout<<s[n-1];
			}
			puts("");
		}
		else
		{
			for(i=k;i<n;i++)
			{
				cout<<s[i];
			}
			puts("");
		}
	}
	return 0;
}