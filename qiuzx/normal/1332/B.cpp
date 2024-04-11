#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 1010
using namespace std;
ll prime[15]={1,2,3,5,7,11,13,17,19,23,29,31,37},cnt,book[15],ans[N];
int main(){
	ll t,n,i,j,a;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cnt=0;
		memset(book,-1,sizeof(book));
		for(i=0;i<n;i++)
		{
			cin>>a;
			for(j=1;j<=11;j++)
			{
				if(a%prime[j]==0)
				{
					if(book[j]==-1)
					{
						book[j]=++cnt;
					}
					ans[i]=book[j];
					break;
				}
			}
		}
		cout<<cnt<<endl;
		for(i=0;i<n;i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}