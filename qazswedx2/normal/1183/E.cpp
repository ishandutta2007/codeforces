#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
struct pt
{
	char s[105];
	int len;
	bool operator <(const pt& x) const
	{
		if(len!=x.len) return len>x.len;
		for(int i=1;i<=len;i++)
			if(s[i]!=x.s[i])
				return s[i]<x.s[i];
		return 0;
	}
	pt(){memset(s,0,sizeof(s)),len=0;}
}a;
set<pt> st;
vector<pt> v;
int n,ans=0,m;
int main()
{
	a.len=0;
	st.insert(a);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		char ch;
		scanf(" %c",&ch);
		set<pt>::iterator it=st.begin();
		for(;it!=st.end();it++)
			v.push_back(*it);
		for(int j=0;j<v.size();j++)
		{
			pt x=v[j];
			x.len++;
			x.s[x.len]=ch;
			if(!st.count(x)) st.insert(x);
			if(st.size()>m)
			{
				it=st.end();
				it--;
				st.erase(it);
			}
		}
		while(!v.empty()) v.pop_back();
		//printf("i=%d\n",i);
		for(it=st.begin();it!=st.end();it++)
		{
			//ans=ans+n-it->len;
			//printf("len=%d,s=%s\n",it->len,it->s+1);
		}
	}
	if(st.size()<m)
	{
		printf("-1");
		return 0;
	}
	set<pt>::iterator it=st.begin();
	for(int i=1;it!=st.end()&&i<=m;it++,i++)
	{
		ans=ans+n-it->len;
		//printf("i=%d,len=%d,s=%s\n",i,it->len,it->s+1);
	}
	printf("%d",ans);
	return 0;
}