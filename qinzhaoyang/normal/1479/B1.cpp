#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1;
int n,a[N],A,q[N],t,v;
signed main()
{
	cin>>n,A=n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		if(a[i]==a[i+1])
			q[++t]=i,A--;
	for(int i=1;i<=t;i++)
	{
		if(q[i]+1==q[i+1])
			continue;
		A++;
		if(a[q[i]]==a[q[i+1]])
		{
			v=1;
			for(int j=q[i]+2;j<q[i+1];j++)
				if(a[j]!=a[q[i]]&&a[j+1]!=a[q[i]])
					v=0;
			A-=v;
		}
	}
	cout<<A;
	return 0;
}