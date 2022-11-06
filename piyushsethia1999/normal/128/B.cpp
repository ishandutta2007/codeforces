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
	string s;
	ll k;
	cin >> s >> k;
	ll n = s.size();
	if(((n*(n+1l))/2) < k) {
		cout << "No such line.";
		exit(0);
	}
	priority_queue<std::pair<string, int> , std::vector<std::pair<string, int> >, greater<std::pair<string, int> > > pq;
	string s1 = "a";
	for (int i = 0; i < n; ++i) {
		s1[0] = s[i];
		pq.push(mp(s1, i+1));
	}
	std::pair<string, int> p;
	while(k--)
	{
		p = pq.top();
		pq.pop();
		print(p);
		if(p.second != n)
			pq.push(mp(p.first + s[p.second], p.second + 1));
	}
	cout << p.first;
}