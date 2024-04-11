#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

map<string,int>mp;

signed main()
{
	mp["monday"]=0;
	mp["tuesday"]=1;
	mp["wednesday"]=2;
	mp["thursday"]=3;
	mp["friday"]=4;
	mp["saturday"]=5;
	mp["sunday"]=6;
	string a,b;
	cin>>a>>b;
	int x=mp[a],y=mp[b];
	if ((y-x+7)%7==0) return puts("YES"),0;
	if ((y-x+7)%7==2) return puts("YES"),0;
	if ((y-x+7)%7==3) return puts("YES"),0;
	puts("NO");
	
	return 0;
}