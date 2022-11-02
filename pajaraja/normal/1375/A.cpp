#include <bits/stdc++.h>
using namespace std;
int a[100007];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,sgn=1;
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++)
		{
			if(a[i]<0 && sgn==1) a[i]=-a[i];
			if(a[i]>0 && sgn==-1) a[i]=-a[i];
			sgn*=-1;
		}
		for(int i=0;i<n;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
}