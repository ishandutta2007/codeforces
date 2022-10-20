#include <bits/stdc++.h>
#define ll int
#define F first
#define S second
#define INF 10000000000
#define N 110
using namespace std;
map<string,ll> mp;
ll n;
char buf[N];
string s;
int main(){
	ll i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",&buf);
		s=buf;
		if(!mp.count(s))
		{
			puts("OK");
			mp[s]=1;
		}
		else
		{
			printf("%s%d\n",s.c_str(),mp[s]);
			mp[s]++;
		}
	}
	return 0;
}