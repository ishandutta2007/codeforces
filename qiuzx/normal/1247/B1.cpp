#include <bits/stdc++.h>
#define N 110
using namespace std;
int t,n,k,d,a[N];
bool book[N];
int main(){
	int i,j,ans,tem;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>d;
		ans=1e8;
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i+d<=n;i++)
		{
			memset(book,0,sizeof(book));
			tem=0;
			for(j=i;j<i+d;j++)
			{
				if(!book[a[j]])
				{
					tem++;
					book[a[j]]=true;
				}
			}
			ans=min(ans,tem);
		}
		cout<<ans<<endl;
	}
	return 0;
}