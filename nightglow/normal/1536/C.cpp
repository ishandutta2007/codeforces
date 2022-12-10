#include<bits/stdc++.h>

#define N 1000005 

#define mk make_pair 

using namespace std;

map<pair<int,int>,int>mp;

int gcd(int a,int b) { return !b?a:gcd(b,a%b);}

int f[N],n;

char c[N];

int main()
{
	scanf("%d",&n);
	for (;n--;)
	{
		int m; scanf("%d",&m); 
		scanf("%s",c+1);
		int a = 0, b = 0;
		mp.clear();
		for (int i = 1;i <= m; ++i)
		{
			if (c[i]=='D') ++a; else ++b;
			int g = gcd(a,b), c = g == 0 ? (a > 0):a / g, d = g == 0 ? (b > 0) : b / g;
			if (mp.find(mk(c,d))!=mp.end()) f[i] = f[mp[mk(c,d)]] + 1;
			else f[i] = 1;
			mp[mk(c,d)] = i; 
		}
		for (int i = 1; i < m; ++i) printf("%d ",f[i]);
		printf("%d\n",f[m]);
	}
}