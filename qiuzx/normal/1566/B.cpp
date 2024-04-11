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
string s;
int main(){
	ll T,i;
	cin>>T;
	while(T--)
	{
		cin>>s;
		if(s.find('0')==-1)
		{
			puts("0");
			continue;
		}
		else if(s.find('1')==-1)
		{
			puts("1");
			continue;
		}
		for(i=s.find('0');i<s.size();i++)
		{
			if(s[i]=='1')
			{
				break;
			}
		}
		for(;i<s.size();i++)
		{
			if(s[i]=='0')
			{
				puts("2");
				i=-1;
				break;
			}
		}
		if(i!=-1)
		{
			puts("1");
		}
	}
	return 0;
}