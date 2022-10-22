#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))

const int N=100001;
int n,m,T; 
int a[N];

ll x;
map<ll,bool>q;

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

bool work()
{
	cin >> x;
	for (int ll i=1;i<=sqrt(x);i++)
	{
		ll p=i*i*i;
		if (p>=x) return 0;
		ll u=x-p;
		if (q[u]) return 1;
	}
	return 0;
}

int main()
{
	T=read();
	for (ll i=1;i<=100000;i++) q[i*i*i]=1;
	while (T--)
	{
		if (work()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}