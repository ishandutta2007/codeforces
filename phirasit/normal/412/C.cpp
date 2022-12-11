#include <iostream>

#define N 100010

using namespace std;

string ans = "";
string str[N];
int n;

int main() {
	cin >> n;
	for(int i = 0;i < n;i++) {
		cin >> str[i];
	}
	int l = str[0].length();
	for(int i = 0;i < l;i++) {
		ans += "#";
	}
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < l;j++) {
			if(str[i][j] == '?') {
				continue;
			}
			if(ans[j] == '#') {
				ans[j] = str[i][j];
			}else if(ans[j] != str[i][j]) {
				ans[j] = '?';
			}
		}
	}
	for(int i = 0;i < l;i++) {
		if(ans[i] == '#') {
			ans[i] = 'a';
		}
	}
	cout << ans << endl;
	return 0;
}