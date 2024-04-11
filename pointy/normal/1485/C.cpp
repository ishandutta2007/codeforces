#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))

int T;
ll x,y;
ll ans;

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

ll find(ll l,ll r)
{
	while (l<=r)
	{
		ll mid=(l+r)/2ll;
		if (mid-2-x/mid>0) l=mid+1;
		else r=mid-1;
	}
	return l;
}

void work()
{
	x=read(),y=read();
	y++;
	ll l=1,r=1;
	ans=0;
	while (1)
	{
		l=r+1;
		if (l>y) break;
		if (l>x) break;
		r=(x/(x/l));
		if (r>y) r=y;
		//cout << l << " " << r << endl; 
		//cout << r-2 << " " << x/l << endl;
		if (r-2<=x/l) ans+=(l+r-4)*(r-l+1)/2ll;
		else if (l-2>=x/l) ans+=(x/l)*(r-l+1);
		else
		{
			ll p=find(l,r);
			ans+=(p+r-4)*(r-p+1)/2ll;
			ans+=(x/l)*(r-p);
		}
	}
}

int main()
{
	T=read();
	while (T--)
	{
		work();
		cout << ans << endl;
	}
	return 0;
}