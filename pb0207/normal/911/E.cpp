#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<set>
using namespace std;

const int N=2e5+1e3+7;

int n,k,a[N];

int ans[N],tot;

stack<int>st;

set<int>s;

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&a[i]),ans[i]=a[i];
	tot=k;
	for(int i=1;i<=n;i++)
		s.insert(-i);
	for(int i=1;i<=k;i++)
		s.erase(-a[i]);
	int now=1;
	for(int i=1;i<=k;i++)
	{
		if(!st.empty()&&a[i]>st.top())
		{
			puts("-1");
			return 0;
		}
		st.push(a[i]);
		while(!st.empty()&&st.top()==now)
			st.pop(),now++;
	}
	while(s.size())
	{
		set<int>::iterator it;
		if(!st.empty())
			it=s.lower_bound(-st.top());
		else
			it=s.begin();
		int v=-*it;
		s.erase(-v);
		ans[++tot]=v;
		st.push(v);
		while(!st.empty()&&st.top()==now)
			st.pop(),now++;
	}
	while(!st.empty())
	{
		if(st.top()==now) 
			st.pop(),now++;
		else
		{
			puts("-1");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}