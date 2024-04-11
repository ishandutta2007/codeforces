#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int ask(string s)
{
	cout<<"? "<<s<<endl;
	return read();
}
int val[N],p[N];

signed main()
{
	int n=read(),m=read(),ans=0;
	string s(m,'0');
	for (int i=0;i<m;i++) s[i]='1',val[i]=ask(s),s[i]='0';
	for (int i=0;i<m;i++) p[i]=i;
	sort(p,p+m,[&](int x,int y){return val[x]<val[y];});
	for (int i=0;i<m;i++)
	{
		int now=p[i];
		s[now]='1';
		int nxt=ask(s);
		if (nxt-ans<val[now]) s[now]='0';
		else ans=nxt;
	}
	cout<<"! "<<ans<<endl;
	
	return 0;
}