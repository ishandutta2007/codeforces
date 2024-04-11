#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int ti[233333],a[233333],b[233333];
vector<pair<long long,int> > both,A,B;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > ex;
priority_queue<pair<long long,int> > used;
inline void output(int i,int j)
{
	while(!used.empty())
	{
		cout<<used.top().second<<' ';
		used.pop();
	}
	for(int t=0;t<i;t++)cout<<both[t].second<<' ';
	for(int t=0;t<j;t++)cout<<A[t].second<<' ';
	for(int t=0;t<j;t++)cout<<B[t].second<<' ';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>ti[i]>>a[i]>>b[i];
		if(a[i]&&b[i])both.push_back(make_pair(ti[i],i));
		else if(a[i])A.push_back(make_pair(ti[i],i));
		else if(b[i])B.push_back(make_pair(ti[i],i));
		else ex.push(make_pair(ti[i],i));
	}
	sort(both.begin(),both.end());
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	int i=0,j=0;
	long long ans=0x3f3f3f3f3f,cur=0;
	while(j<A.size()&&j<B.size()&&j<k&&j<m-k)
	{
		cur+=A[j].first+B[j].first;
		j++;
	}
	while(i<both.size()&&i+j<k)
	{
		cur+=both[i].first;
		i++;
	}
	if(i+j<k)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int t=j;t<A.size();t++)ex.push(A[t]);
	for(int t=j;t<B.size();t++)ex.push(B[t]);
	while(!ex.empty()&&i+j*2+used.size()<m)
	{
		used.push(ex.top());
		cur+=ex.top().first;
		ex.pop();
	}
	if(i+j*2+used.size()==m)ans=cur;
	while(i<both.size())
	{
		cur+=both[i].first;
		i++;
		if(j>0)
		{
			j--;
			used.push(A[j]);
			used.push(B[j]);
			ex.push(used.top());
			cur-=used.top().first;
			used.pop();
			ex.push(used.top());
			cur-=used.top().first;
			used.pop();
		}
		while(!ex.empty()&&i+j*2+used.size()<m)
		{
			used.push(ex.top());
			cur+=ex.top().first;
			ex.pop();
		}
		while(used.size()&&i+j*2+used.size()>m)
		{
			ex.push(used.top());
			cur-=used.top().first;
			used.pop();
		}
		if(i+j*2+used.size()==m)ans=min(ans,cur);
	}
	if(ans>=0x3f3f3f3f3fll)cout<<-1<<endl;
	else cout<<ans<<endl;
	//-------------------------------------------------------
	while(!ex.empty())ex.pop();
	while(!used.empty())used.pop();
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0&&b[i]==0)
			ex.push(make_pair(ti[i],i));
	}
	i=0,j=0;
	cur=0;
	while(j<A.size()&&j<B.size()&&j<k&&j<m-k)
	{
		cur+=A[j].first+B[j].first;
		j++;
	}
	while(i<both.size()&&i+j<k)
	{
		cur+=both[i].first;
		i++;
	}
	for(int t=j;t<A.size();t++)ex.push(A[t]);
	for(int t=j;t<B.size();t++)ex.push(B[t]);
	while(!ex.empty()&&i+j*2+used.size()<m)
	{
		used.push(ex.top());
		cur+=ex.top().first;
		ex.pop();
	}
	if(i+j*2+used.size()==m&&cur==ans)
	{
		output(i,j);
		return 0;
	}
	while(i<both.size())
	{
		cur+=both[i].first;
		i++;
		if(j>0)
		{
			j--;
			used.push(A[j]);
			used.push(B[j]);
			ex.push(used.top());
			cur-=used.top().first;
			used.pop();
			ex.push(used.top());
			cur-=used.top().first;
			used.pop();
		}
		while(!ex.empty()&&i+j*2+used.size()<m)
		{
			used.push(ex.top());
			cur+=ex.top().first;
			ex.pop();
		}
		while(used.size()&&i+j*2+used.size()>m)
		{
			ex.push(used.top());
			cur-=used.top().first;
			used.pop();
		}
		if(i+j*2+used.size()==m&&cur==ans)
		{
			output(i,j);
			return 0;
		}
	}
	return 0;
}