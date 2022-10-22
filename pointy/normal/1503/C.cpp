#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=100005;
int n,m,T; 

struct point
{
	ll a,c;
}a[N];

ll s[N],ans;

bool cmp(point x,point y)
{
	return x.a<y.a;
}

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
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i].a=read(),a[i].c=read();
		ans+=a[i].c; 
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++) s[i]=a[i].a+a[i].c;
	for (int i=1;i<=n;i++) s[i]=max(s[i],s[i-1]);
	for (int i=1;i<=n;i++)
	{
		if (s[i]>=a[i+1].a) continue;
		else ans+=a[i+1].a-s[i];
	}
	cout << ans;
	return 0;
}