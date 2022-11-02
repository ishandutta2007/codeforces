#include <bits/stdc++.h>
using namespace std;
int a[307][307],b[307][307];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j];
		for(int i=0;i<n;i++) for(int j=0;j<m;j++)
		{
			b[i][j]=4;
			if(i==0) b[i][j]--;
			if(i==n-1) b[i][j]--;
			if(j==0) b[i][j]--;
			if(j==m-1) b[i][j]--;
		}
		bool fas=false;
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(a[i][j]>b[i][j]) fas=true;
		if(fas) cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++) cout<<b[i][j]<<" ";
				cout<<endl;
			}
		}
	}
}