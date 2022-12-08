#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+1;
int t,n,e,p[N],v[N],c,A,x,a[N],s[4],l;
signed main()
{
	for(int i=2;i<N;i++)
	{
		if(!v[i])
			p[++c]=i;
		for(int j=1;i*p[j]<N;j++)
		{
			v[i*p[j]]=1;
			if(i%p[j]==0)
				break;
		}
	}
	cin>>t;
	while(t--&&cin>>n>>e)
	{
		A=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==1)
				a[i]=0;
			else if(!v[a[i]])
				a[i]=1;
			else
				a[i]=2;
		}
		for(int i=1;i<=e;i++)
		{
			s[0]=s[1]=s[2]=l=x=0;
			for(int j=0;i+j*e<=n;j++)
			{
				s[a[i+j*e]]++;
				if(a[i+j*e]==1)
					x=j;
				while(s[2]||s[1]>1)
					s[a[i+l*e]]--,l++;
				if(l<j&&s[1]==1)
					A+=max(0ll,x-l+1-(x==j));
			}
		}
		cout<<A<<'\n';
	}
	return 0;
}