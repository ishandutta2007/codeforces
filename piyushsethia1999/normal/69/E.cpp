#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
		I_O;
	#else
	#define print(...) 0
	#endif
	int n; cin >> n;
	int k; cin >> k;
	std::map<int, int> m;
	vector<int> v(n); for (int o = 0; o < n; ++o) { cin >> v[o]; }
	set<int> s;
	for (int i = 0; i < k; ++i)
	{
		if(!m[v[i]])
			s.insert(v[i]);
		else if(m[v[i]] == 1)
			s.erase(v[i]);
		m[v[i]]++;
	}
	if(!s.empty())
		cout << *(s.rbegin()) << "\n";
	else
		cout << "Nothing\n";
	for (int i = k; i < n; ++i)
	{
		//add v[i]
		if(m[v[i]] == 1)
			s.erase(v[i]);
		else if(!m[v[i]])
			s.insert(v[i]);
		m[v[i]]++;
		//remove v[i-k]
		m[v[i-k]]--;
		if(m[v[i-k]] == 1)
			s.insert(v[i-k]);
		else if(m[v[i-k]] == 0)
			s.erase(v[i-k]);
		if(s.empty())
			cout << "Nothing\n";
		else
			cout << *(s.rbegin()) << "\n";
	}
}