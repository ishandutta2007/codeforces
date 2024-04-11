#include<bits/stdc++.h>
using namespace std;
const int N=4e5+1;
int T,n,c[N],p,x,y;
int main()
{
	cin>>T;
	while(T--&&cin>>n)
	{
		for(int i=1;i<=2*n;i++)
			c[i]=0;
		for(int i=1;i<=n;i++)
			cin>>x,c[x]++;
		p=x=y=0;
		for(int i=1;i<=2*n;i++)
			if(c[i])
				p++;
			else
				p--,x=min(x,p);
		p=0;
		for(int i=2*n;i>=1;i--)
			if(c[i])
				p++;
			else
				p--,y=min(y,p);
		cout<<n+1+x+y<<'\n';
	}
	return 0;
}