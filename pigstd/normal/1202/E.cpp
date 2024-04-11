#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int T=read();while(T--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

const int M=2e5+10;
int n;
string s;
struct tree
{
	struct node
	{
		int fail,val,son[26];
	}t[M];int cnt,f[M];
	vector<int>e[M];
	void insert(string s)
	{
		int len=s.size(),now=0;
		for (int i=0;i<len;i++)
		{
			if (!t[now].son[s[i]-'a'])t[now].son[s[i]-'a']=++cnt;
			now=t[now].son[s[i]-'a'];
		}t[now].val++;
	}
	void get_fail()
	{
		queue<int>q;
		for (int i=0;i<26;i++)
			if (t[0].son[i])q.push(t[0].son[i]);
		while(!q.empty())
		{
			int now=q.front();q.pop();
			for (int i=0;i<26;i++)
			{
				int v=t[now].son[i];
				if (v)t[v].fail=t[t[now].fail].son[i],q.push(v);
				else t[now].son[i]=t[t[now].fail].son[i];
			}
		}
	}
	void get_tree()
	{
		for (int i=1;i<=cnt;i++)
			e[t[i].fail].pb(i);
	}
	void dfs(int u)
	{
		for (int i=0;i<e[u].size();i++)
		{
			int to=e[u][i];
			t[to].val+=t[u].val;dfs(to);
		}
	}
	void get_ans(string s)
	{
		int now=0,len=s.size();
		for (int i=0;i<len;i++)
		{
			now=t[now].son[s[i]-'a'];
			f[i]=t[now].val;
		}
	}
}T1,T2;

signed main()
{
	cin>>s>>n;int len=s.size();
	for (int i=1;i<=n;i++)
	{
		string t,tt="";
		cin>>t;int len=t.size();
		T1.insert(t);
		for (int i=len-1;i>=0;i--)tt+=t[i];
		T2.insert(tt);
	}
	T1.get_fail(),T1.get_tree();T1.dfs(0);
	T2.get_fail(),T2.get_tree();T2.dfs(0);
	string ss="";int ans=0;
	for (int i=len-1;i>=0;i--)ss+=s[i];
	T1.get_ans(s),T2.get_ans(ss);
	for (int i=0;i<len-1;i++)
		ans+=T1.f[i]*T2.f[len-i-2];//,cout<<i<<' '<<T1.f[i]<<' '<<T2.f[len-i-2]<<endl;
	cout<<ans<<endl;
	return 0;
}