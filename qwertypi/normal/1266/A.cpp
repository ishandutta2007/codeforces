#include <bits/stdc++.h>

using namespace std;

void sub(string s){
	int s_t = 0;
	bool is_0 = false;
	int even = 0;
	for(auto i : s){
		s_t += i - '0';
		if(i == '0') is_0 = 1;
		even += (i - '0') % 2 == 0;
	}
	if(s_t % 3 == 0 && is_0 == 1 && even >= 2){
		cout << "red" << endl;
	}else{
		cout << "cyan" << endl;
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		sub(s);
	}
}