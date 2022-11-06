#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int a[555];
pair<int,int> b[555];
vector<int> ans;
inline void op(int pos)
{
	int t=a[pos+2];
	a[pos+2]=a[pos+1];
	a[pos+1]=a[pos];
	a[pos]=t;
	ans.push_back(pos);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			b[i]=make_pair(a[i],i);
		}
		sort(b+1,b+n+1);
		int same=-1,cnt=0;
		for(int i=1;i<n;i++)
		{
			if(b[i].first==b[i+1].first)same=b[i].first;
			for(int j=i+1;j<=n;j++)
			{
				if(b[i].second>b[j].second)cnt++;
			}
		}
		if(cnt%2!=0&&same==-1)
		{
			cout<<-1<<endl;
			continue;
		}
		if(cnt%2!=0)
		{
			for(int i=1;i<n;i++)
			{
				if(b[i].first==b[i+1].first)
				{
					swap(b[i].second,b[i+1].second);
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)a[b[i].second]=i;
//		for(int i=1;i<=n;i++)cerr<<a[i]<<' ';cerr<<endl;
		for(int i=1;i<=n-2;i++)
		{
			int pos=0;
			for(int j=i;j<=n;j++)
			{
				if(a[j]==i)
				{
					pos=j;
					break;
				}
			}
			while(pos>i+1)op(pos-2),pos-=2;
			if(pos==i+1)op(i),op(i);
		}
		cout<<ans.size()<<endl;
		for(auto x:ans)cout<<x<<' ';cout<<endl;
		ans.clear();
	}
	return 0;
}