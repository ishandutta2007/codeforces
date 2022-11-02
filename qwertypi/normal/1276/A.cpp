#include <bits/stdc++.h>

using namespace std;

void sub(){
	vector<int> A;
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		bool OK = false;
		if(i < (int) s.size() - 4){
			OK = s.substr(i, 5) == "twone";
			if(OK){
				A.push_back(i + 2);
				i += 4;
				continue;
			}
		}
		if(i < (int) s.size() - 2){
			OK = s.substr(i, 3) == "two" || s.substr(i, 3) == "one";
			if(OK){
				A.push_back(i + 1);
				i += 2;
			}
		}
	}
	cout << A.size() << endl;
	for(auto i : A){
		cout << i + 1 << ' ';
	}
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}