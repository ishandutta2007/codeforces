#include <iostream>
#include <string>
using namespace std;
string s;
int main(){
	int n, r;
	cin >> n >> r;
	cin >> s;
	if(n == 1){
		if(s[0] != '0' && r)
			s[0] = '0';
		cout << s;
		return 0;
	}
	if(s[0] != '1' && r){
		s[0] = '1';
		r--;
	}
	for(int i=1;i<n;i++){
		if(s[i] != '0' && r){
			s[i] = '0';
			r--;
		}
	}
	cout << s << endl;
}