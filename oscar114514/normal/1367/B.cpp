#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int a[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		int cnt=0,cnt2=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]%2==0&&i%2==1)cnt++;
			else if(a[i]%2==1&&i%2==0)cnt2++;
		}
		if(cnt!=cnt2)cout<<-1<<endl;
		else cout<<cnt<<endl;
	}
	return 0;
}