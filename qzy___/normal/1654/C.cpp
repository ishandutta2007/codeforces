#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int T,n,A,x,y,q[N],t,a[N],c[150],C,s;
void D(int x)
{
	for(int i=1;i<=t;i++)
		if(q[i]==x&&c[i])
		{
			c[i]--;
			return;
		}
	if(x==1)
	{
		A=0;
		return;
	}
	if(A)
		D(x/2);
	if(A)
		D((x+1)/2);
}
signed main()
{
	cin>>T;
	while(T--&&cin>>n)
	{
		s=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],s+=a[i];
		if(n==1)
		{
			puts("YES");
			continue;
		}
		t=C=0,A=1,memset(c,0,sizeof(c));
		for(int i=1;i<60;i++)
			q[++t]=s/(1ll<<i),q[++t]=s/(1ll<<i)+1;
		sort(q+1,q+t+1),t=unique(q+1,q+t+1)-q-1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=t;j++)
				if(a[i]==q[j])
					c[j]++;
		for(int i=1;i<=t;i++)
			C+=c[i];
		if(C!=n)
		{
			puts("NO");
			continue; 
		}
		D(s);
		A?puts("YES"):puts("NO");
	}
}