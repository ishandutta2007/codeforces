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

void work()
{
	ll p,a,b,c;
	cin >> p >> a >> b >> c;
	ll d=p%a,e=p%b,f=p%c;
	d=a-d,e=b-e,f=c-f; 
	if (d==a||b==e||c==f) cout << 0 << endl;
	else cout << min(d,min(e,f)) << endl;
	return;
}

int main()
{
	T=read();
	while (T--)
	{
		work();
	}
	return 0;
}