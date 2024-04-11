#include <bits/stdc++.h>
#define N 1000010
using namespace std;
int t,n,k,d,a[N],book[N];
int main(){
	int i,j,ans,tem;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>d;
		ans=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<d;i++)
		{
			if(book[a[i]]==0)
			{
				ans++;
			}
			book[a[i]]++;
		}
		tem=ans;
		for(i=d;i<n;i++)
		{
			if(book[a[i-d]]==1)
			{
				tem--;
			}
			book[a[i-d]]--;
			if(book[a[i]]==0)
			{
				tem++;
			}
			book[a[i]]++;
			ans=min(ans,tem);
		}
		for(i=n-d;i<n;i++)
		{
			book[a[i]]--;
		}
		cout<<ans<<endl;
	}
	return 0;
}