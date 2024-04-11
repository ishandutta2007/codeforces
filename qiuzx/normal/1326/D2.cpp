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
#define N 2000010
using namespace std;
int T,pre[N];
string s;
string rstr(){
	string ret;
	char buf[N];
	scanf("%s",&buf);
	return ret=buf;
}
string gpl(string a)
{
	int i,j;
	string b;
	b=a;
	reverse(b.begin(),b.end());
	b=a+"!"+b;
	j=0;
	for(i=1;i<b.size();i++)
	{
		while(j>0&&b[j]!=b[i])
		{
			j=pre[j-1];
		}
		if(b[j]==b[i])
		{
			j++;
		}
		pre[i]=j;
	}
	b=a.substr(0,j);
	return b;
}
int main(){
	int i,j;
	string a,b,t;
	scanf("%d",&T);
	while(T--)
	{
		s=rstr();
		for(i=0;i<s.size()-i-1&&s[i]==s[s.size()-i-1];i++);
		if(i!=0)
		{
			printf("%s",s.substr(0,i).c_str());
		}
		if(s.size()>2*i)
		{
			t=s.substr(i,s.size()-i-i);
			a=gpl(t);
			reverse(t.begin(),t.end());
			b=gpl(t);
			if(a.size()<b.size())
			{
				swap(a,b);
			}
			printf("%s",a.c_str());
		}
		if(i!=0)
		{
			printf("%s",s.substr(s.size()-i).c_str());
		}
		puts("");
	}
	return 0;
}