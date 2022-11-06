#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define INF 2000000000
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
	cin >> s;
	int l = s.size();
	int pos = 0;
	int male_ahead = 0;
	int maxt = 0;
	for (int i = 0; i < l; ++i)
	{
		if(s[i] == 'F')
		{
			if(i == pos)
			{
			}
			else if((i-pos) <= maxt) {
				maxt++;
			}
			else {
				maxt = i - pos;
			}
			pos++;
		}
	}
	cout<<maxt;
}