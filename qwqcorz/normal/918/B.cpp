#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

map<string,string>mp;

signed main()
{
	int n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		mp[b]=a;
	}
	for (int i=1;i<=m;i++)
	{
		string a,b;
		cin>>a>>b;
		string c=b;
		c.erase(prev(c.end()));
		cout<<a<<' '<<b<<" #"<<mp[c]<<endl;
	}
	
	return 0;
}