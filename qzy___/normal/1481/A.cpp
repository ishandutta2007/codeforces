#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int T;

int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--) {
		int x , y;
		cin >> x >> y;
		string s;
		cin >> s;
		int c[200] = {0};
		for(int i = 0; i < s.size(); i++)
			c[(int)s[i]]++;
		int flag = true;
		if(x > 0) {
			if(c[(int)'R'] < x)
				flag = false;
		}
		else if(x < 0) {
			if(c[(int)'L'] < -x)
				flag = false;
		}
		if(y > 0) {
			if(c[(int)'U'] < y)
				flag = false;
		}
		else if(y < 0) {
			if(c[(int)'D'] < -y)
				flag = false;
		}
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}