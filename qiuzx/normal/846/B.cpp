#include <bits/stdc++.h>
#define N 50
using namespace std;
int main(){
	long long n,k,m,t[N],i,j,a,p=0,ti=0,ans=0,sum=0;
	cin>>n>>k>>m;
	for(i=0;i<k;i++)
	{
		cin>>t[i];
		sum+=t[i];
	}
	sort(t,t+k);
	for(i=0;i<=n;i++)
	{
		ti=i*sum;
		if(ti>m)
		{
			cout<<ans<<endl;
			return 0;
		}
		else
		{
			p=i*(k+1);
			for(j=0;j<k;j++)
			{
				for(a=i;a<n;a++)
				{
					ti+=t[j];
					if(ti>m)
					{
						j=k+10;
						ans=max(ans,p);
						break;
					}
					p++;
				}
				if(j==k-1&&a!=i)
					p++;
				ans=max(ans,p);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}