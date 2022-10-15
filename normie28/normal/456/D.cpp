#include<bits/stdc++.h>
#define T() int t; cin>>t; while(t--)
#define rep(i,start,lim) for(long long i=start;i<lim;i++)
#define repd(i,start,lim) for(long long i=start;i>=lim;i--)
#define ll long long
#define pb push_back
#define f first
#define s second
#define vlld vector<long long> 
#define YES printf("YES\n")
#define NO printf("NO\n")
#define MAX 10000000
#define MOD 1000000009 
#define N 1000001
 
using namespace std;
 
	const int c = 1e5+1;
	int d[c][26],lose[c],win[c];
	int nex;
	ll n,k;
	string s;
 
void dfs(int v)
{
	win[v] = false;
	lose[v] = false;
	bool isleaf = true;
	rep(i,0,26)
	{
		if(d[v][i] != 0)
		{
			isleaf = false;
			int to = d[v][i];
			dfs(to);
			win[v] |= !win[to];
            lose[v] |= !lose[to];
		}
	}
	if(isleaf)
	{
		lose[v] = true;
	}
}
 
void addTrie(string s)
{
	int v = 0;
	rep(i,0,s.length())
	{
		if(d[v][s[i]-'a'] == 0)
		{
			d[v][s[i]-'a'] = nex;
			v = nex;
			nex++;
		}
		else
		{
			v = d[v][s[i]-'a'];
		}
	}
}
 
void answer(bool res) {
	if(res)
	cout<<"First";
	else
	cout<<"Second";
	exit(0);
}
 
int main()
{
	nex=1;
	cin>>n>>k;
	rep(i,0,n)
	{
		cin>>s;
		addTrie(s);
	}
	int root = 0;
	dfs(0);
	if (k == 1) answer(win[root]); 
    else if (!win[root]) answer(win[root]); 
    else if (lose[root]) answer(win[root]); 
    else if (k % 2 == 1) answer(win[root]); 
    else answer(!win[root]); 
}