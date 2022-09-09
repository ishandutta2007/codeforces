#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
long long ans, su=0;
char now;
string s;

//
int main() {
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //
        cin >> s;
		//
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != now || su > 5) {
				su = 1;
				ans++;
			}
			now = s[i];
			su++;
		}
		//
        cout << ans;
}