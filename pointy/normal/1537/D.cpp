#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=100001;
int n,m,T; 
int a[N];

inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 

int main()
{
	int T=read();
	while (T--)
	{
		ll x=read();
		ll p=2;
		while (p<x) p*=4;
		if (p==x||x%2==1) cout << "Bob\n";
		else cout << "Alice\n";
	}
	return 0;
}