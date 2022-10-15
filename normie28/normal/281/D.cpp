#include <bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
#define endl "\n"
#define sect 3200
struct el { string word; long long x, y, dir; };
int n, m, k, cnt, i, j, a[100005], b = 0, c=0, dp[201][201][201];
long long mp[1000][1000];
string name[8] = { "N","NE","E","SE","S","SW","W","NW" };
	long long sum[300001],prex[300001],prey[300001];
vector<int> st;
int main()
{
//	#define a a[i]
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int maxx=0;
	for (i=0;i<n;i++)
	{
		cin>>a[i];
		while (st.size())
		{
			if (st[st.size()-1]<a[i])
			{
				if ((a[i]^st[st.size()-1])>maxx) maxx=(a[i]^st[st.size()-1]);
				st.pop_back();
			}
			else break;
		}
		st.push_back(a[i]);
	}
	st.clear();
	
	for (i=n-1;i>=0;i--)
	{
		while (st.size())
		{
			if (st[st.size()-1]<a[i])
			{
				if ((a[i]^st[st.size()-1])>maxx) maxx=(a[i]^st[st.size()-1]);
				st.pop_back();
			}
			else break;
		}
		st.push_back(a[i]);
	}
	
	cout<<maxx;
}
//x[j]+y[i]<x[i]+y[j]