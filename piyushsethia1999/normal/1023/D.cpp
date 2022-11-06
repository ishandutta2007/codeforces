#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long
#define MAX 800000
using namespace std;
int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
	I_O;
	#endif
	int n, q;
	cin >> n >> q;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	bool isthere = false;
	for (int i = 0; i < n; ++i)
		if(a[i] == q)
			isthere = true;
	if(!isthere) {
		int pp = -1;
		for (int i = 0; i < n; ++i)
			if(a[i] == 0)
				pp = i;
		if(pp == -1)
		{
			cout << "NO";
			exit(0);
		}
		else
		{
			a[pp] = q;
		}
	}
	int ss = 1000000;
	for (int i = 0; i < n; ++i)
	{
		if(a[i] != 0) {
			ss = i;
			break;
		}
	}
	if(ss == 1000000)
	{
		cout << "YES\n";
		for (int i = 0; i < n; ++i)
		{
			cout << q << " ";
		}
		exit(0);
	}

	for (int j = 0; j < ss; ++j)
	{
		a[j] = a[ss];
	}
	for (int i = 1; i < n; ++i)
	{
		if(a[i] == 0)
			a[i] = a[i-1];
	}
	stack<int> st;
	std::vector<bool> vis(q+1, false);
	bool res = true;
	for (int i = 0; i < n && res; ++i)
	{
		if(!st.empty())
		{
			while((!st.empty()) && (st.top() > a[i]) && res)
			{
				int top = st.top();
				if(vis[st.top()]) {
					res = false;
					break;
				}
				while(((!st.empty()) && st.top() == top) && res)
					st.pop();
				vis[top] = true;
			}
		}
		st.push(a[i]);
	}
	while((!st.empty()) && res)
	{
		int top = st.top();
		if(vis[st.top()]) {
			res = false;
			break;
		}
		while((!st.empty()) && top == st.top())
			st.pop();
		vis[top] = true;
	}
	if(res) {
		cout << "YES\n";
		for (int i = 0; i < n; ++i)
			cout << a[i] << " ";
	}
	else
		cout << "NO";
}