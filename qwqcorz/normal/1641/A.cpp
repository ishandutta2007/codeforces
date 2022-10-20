#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N];
void GreenDay()
{
	int n=read(),x=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	map<int,int>mp;
	for (int i=1;i<=n;i++)
	if (a[i]%x==0&&mp[a[i]/x]) mp[a[i]/x]--;
						  else mp[a[i]]++;
	int ans=0;
	for (auto i:mp) ans+=i.second;
	print(ans);
}

signed main()
{
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}