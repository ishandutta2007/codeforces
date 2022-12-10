#include <bits/stdc++.h>

using namespace std;

string s, t;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;
	int d = 0;
	for(int i = 0; i < s.size(); i++)
		d += (s[i] != t[i]);
	if(d & 1){
		cout << "impossible" << endl;
		return 0;
	}
	int c = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == t[i])
			cout << s[i];
		else if(c < d / 2)
			cout << s[i], c++;
		else
			cout << t[i];
	}
	cout << endl;
	return 0;
}