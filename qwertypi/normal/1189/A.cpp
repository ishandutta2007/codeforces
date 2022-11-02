#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n;
	string s;
	cin >> n >> s;
	int cnt_1 = count(s.begin(), s.end(), '1');
	if(cnt_1 * 2 == n){
		cout << 2 << endl;
		cout << s.substr(0, n-1) << ' ' << s[n-1] << endl;
	}else{
		cout << 1 << endl;
		cout << s << endl;
	}
	return 0;
}