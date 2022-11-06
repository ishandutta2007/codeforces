#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n;
	cin >> n;
	std::vector<int> psycho(n);
	for (int i = n-1; i >= 0; --i)
		cin >> psycho[i];
	std::vector<int> kill(n, 0);
	stack<int> s;
	for (int i = 0; i < n; ++i)
	{
		while(!s.empty() && psycho[s.top()] < psycho[i]) {
			kill[i] ++ ;
			if (kill[s.top()] > kill[i])
				kill[i] = kill[s.top()];
			s.pop();
		}
		s.push(i);
	}
	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		m = max(kill[i], m);
	}
	cout << m;
}