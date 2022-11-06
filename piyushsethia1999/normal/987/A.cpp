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
	map<string, string> m;
	m["purple"] = "Power";
	m["green"] = "Time";
	m["yellow"] = "Mind";
	m["blue"] = "Space";
	m["orange"] = "Soul";
	m["red"] = "Reality";
	int a; cin >> a;
	string A[6] = {"purple","red","green","yellow","orange","blue"};
	bool b[6] = {false};
	string s;
	for (int j = 0; j < a; ++j)
	{
		cin>>s;
		for (int i = 0; i < 6; ++i)
		{
			if(s == A[i])
				b[i] = true;
		}
	}
	cout<<(6-a)<<"\n";
	for (int i = 0; i < (6); ++i)
	{
		if(!b[i])
			cout<<m[A[i]]<<"\n";
	}
}