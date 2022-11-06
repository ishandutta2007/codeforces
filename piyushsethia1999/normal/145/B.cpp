#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n4, n7, nt47, nt74;
	cin >> n4 >> n7 >> nt47 >> nt74;
	if(nt74 - nt47 > 1 || nt74 - nt47 < -1)
		cout << -1;
	else {
		string s = "";
		if(nt74 == nt47)
		{
			if(n4 < nt74 || n7 < nt74 || (n7 + n4) < (2*nt74 + 1))
				s = "-1";//74777777
			else if(n4 == nt74)
			{
				for(int i = 0; i < (nt74); i++)
					s += "74";
				for(int i = 0; i < (n7 - nt74); i++)
					s += '7';
			}
			else
			{
				for(int i = 0; i < (n4 - nt47); i++)
					s += '4';
				for(int i = 0; i < (nt74 - 1); i++)
					s += "74";
				for(int i = 0; i < (n7 - nt74 + 1); i++)
					s += '7';
				s += '4';	
			}
		}
		else if(nt47 > nt74)
		{
			if(n4 < nt47 || n7 < nt47)
				s = "-1";
			else
			{
				for(int i = 0; i < n4 - nt74 ; i++)
					s += '4';
				for(int i = 0; i < nt74; i++)
					s += "74";
				for(int i = 0; i < n7 - nt74; i++)
					s += '7';
			}
		}
		else 
		{
			if(n4 < nt74 || n7 < nt74)
				s = "-1";
			else
			{
				s += '7';
				for(int i = 0; i < n4 - nt47 ; i++)
					s += '4';
				for(int i = 0; i < nt47 - 1; i++)
					s += "74";
				for(int i = 0; i < n7 - nt74 + 1; i++)
					s += '7';
				s += '4';
			}
		}
		cout << s;
	}
}