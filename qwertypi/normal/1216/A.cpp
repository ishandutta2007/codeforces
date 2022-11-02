#include <iostream>

using namespace std;
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 0; i < n / 2; i++){
		if(abs(s[i * 2] - s[i * 2 + 1]) == 0){
			ans++;
			s[i * 2] = (s[i * 2 + 1] == 'a' ? 'b' : 'a');
		}
	}
	cout << ans << endl;
	cout << s;
}