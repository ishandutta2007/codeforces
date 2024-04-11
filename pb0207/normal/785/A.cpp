#include<cstdio>
#include<map>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1e5+1e3+7;

typedef long long ll;

int n;

char s[N];

ll ans;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		if(s[0]=='T')
			ans+=4;
		if(s[0]=='C')
			ans+=6;
		if(s[0]=='O')
			ans+=8;
		if(s[0]=='D')
			ans+=12;
		if(s[0]=='I')
			ans+=20;
	}
	cout<<ans;
}