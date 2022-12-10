#include <bits/stdc++.h>

using namespace std;

#define siktir exit(0)

int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	for(int l = s.size(); l >= 0; l--)
		for(int i = 0; i + l <= s.size(); i++)
			for(int j = i + 1; j + l <= s.size(); j++)
				if(s.substr(i, l) == s.substr(j, l))
					cout << l << endl, siktir;
	return 0;
}