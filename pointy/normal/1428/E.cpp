#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
const int N=100005;
ll a[N],ans;
ll f(ll x,ll y)
{
	if (y==1) return x*x;
	long long z=x/y,w=x%y;
	return (y-w)*z*z+w*(z+1)*(z+1);
}
struct point
{
	int id,k;
	ll dis;
	bool operator < (const point & o) const
	{
		return dis<o.dis;
	}
};
priority_queue<point>q;
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
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
	n=read(),k=read();
	for (int i=1;i<=n;i++) a[i]=read(),ans+=a[i]*a[i];
	for (int i=1;i<=n;i++)
	{
		point u={a[i],2,f(a[i],1)-f(a[i],2)};
		q.push(u);
	}
	k-=n;
	while (k--)
	{
		point u=q.top();
		q.pop();
		//cout << u.dis << endl;
		ans-=u.dis;
		point v={u.id,u.k+1,f(u.id,u.k)-f(u.id,u.k+1)};
		q.push(v);
	}
	cout << ans;
	return 0;
}