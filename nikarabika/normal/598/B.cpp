#include <bits/stdc++.h>

using namespace std;

string s;
int q;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	//rotate(s.begin(), s.begin() + 2, s.end());
	//cout << s << endl;
	cin >> q;
	while(q--){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se;
		th %= se - fi;
		rotate(s.begin() + fi, s.begin() + se - th, s.begin() + se);
	}
	cout << s << endl;
	return 0;
}