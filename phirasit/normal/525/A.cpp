#include <iostream>

using namespace std;

int rem[30];
string str;
int n;

int main() {
	cin >> n;
	cin >> str;
	int ans = 0;
	for(int i = 0;str[i];i += 2) {
		rem[str[i]-'a']++;
		if(rem[str[i+1]-'A'] == 0) {
			ans++;
		}else {
			rem[str[i+1]-'A']--;
		}
	}
	cout << ans << endl;
	return 0;
}