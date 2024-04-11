#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
#define N 110
using namespace std;
int main(){
	int t,n,i,a[N],ans,sum;
	bool book[N];
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum=0;
		ans=0;
		memset(book,false,sizeof(book));
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]==0)
			{
				ans++;
				a[i]++;
			}
			if(a[i]==-1)
			{
				book[i]=true;
			}
			sum+=a[i];
		}
		if(sum==0)
		{
			for(i=0;i<n;i++)
			{
				if(!book[i])
				{
					ans++;
					i=-1;
					break;
				}
			}
			if(i!=-1)
			{
				ans+=2;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}