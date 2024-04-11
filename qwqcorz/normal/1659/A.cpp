#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

void work()
{
	string ret="";
	int n=read(),r=read(),b=read(),A=r/(b+1),B=r%(b+1);
	for (int i=0;i<=b;i++)
	{
		for (int j=1;j<=A+(i<B);j++) ret+='R';
		if (i<b) ret+='B';
	}
	cout<<ret<<endl;
}

signed main()
{
	int T=read();
	while (T--) work(); 
	
	return 0;
}