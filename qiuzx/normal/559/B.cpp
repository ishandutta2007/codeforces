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
string min_equ(string s)
{
	if(s.size()%2==1)
	{
		return s;
	}
	string s1,s2;
	s1=min_equ(s.substr(0,s.size()/2));
	s2=min_equ(s.substr(s.size()/2,s.size()/2));
	return min(s1+s2,s2+s1);
}
int main(){
	string s,t;
	cin>>s>>t;
	if(min_equ(s)==min_equ(t))
	{
		puts("YES");
	}
	else
	{
		puts("NO");
	}
	return 0;
}