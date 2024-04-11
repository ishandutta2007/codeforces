#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int N=1e5+1e3+7;

char s[N];

int a,g,c,t,n;

vector<int>p;

int main()
{
	cin>>n;
	scanf("%s",s+1);
	if(n%4!=0)
	{
		cout<<"===";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='A')
			a++;
		if(s[i]=='G')
			g++;
		if(s[i]=='C')
			c++;
		if(s[i]=='T')
			t++;
		if(s[i]=='?')
			p.push_back(i);
	}
	if(a>n/4||g>n/4||c>n/4||t>n/4)
	{
		cout<<"===";
		return 0;
	}
	int now=0;
	while(a<n/4)
	{
		s[p[now]]='A';
		a++,now++;
	}
	while(g<n/4)
	{
		s[p[now]]='G';
		g++,now++;
	}
	while(c<n/4)
	{
		s[p[now]]='C';
		c++,now++;
	}
	while(t<n/4)
	{
		s[p[now]]='T';
		t++,now++;
	}
	printf("%s",s+1);
}