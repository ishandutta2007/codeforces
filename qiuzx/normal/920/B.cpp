#include <bits/stdc++.h>
#define N 1005
using namespace std;
int main(){
	vector<int> l,r;
	int t,n,i,j,pos,a,b,ans[N],tm;
	queue<int> q;
	cin>>t;
	while(t--)
	{
		cin>>n;
		j=0;
		tm=0;
		memset(ans,0,sizeof(ans));
		l.clear();
		r.clear();
		for(i=0;i<n;i++)
		{
			cin>>a>>b;
			l.push_back(a);
			r.push_back(b);
		}
		while(j<n)
		{
			if(!q.empty())
			{
				ans[q.front()]=tm;
				q.pop();
			}
			tm++;
			pos=upper_bound(l.begin(),l.end(),tm)-l.begin();
			for(;j<pos;j++)
			{
				if(r[j]-l[j]<q.size())
				{
					continue;
				}
				q.push(j);
			}
		}
		while(!q.empty())
		{
			ans[q.front()]=tm;
			q.pop();
			tm++;
		}
		for(j=0;j<n;j++)
		{
			cout<<ans[j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}