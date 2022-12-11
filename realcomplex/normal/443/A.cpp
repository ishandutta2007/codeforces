#include <bits/stdc++.h>
using namespace std;

int main() {
	char s;
	vector<char>n;
	while(cin >> s){
		if(s > 96 && s < 123){
			n.push_back(s);
		}
	}
	sort(n.begin(),n.end());
	int l = 1;
	for(int i = 1;i<n.size();i++){
		if(n[i] != n[i - 1]){
			l++;
		}
	}
	if(n.size() == 0){
		cout << 0;
	}
	else{
		cout << l;
	}
	return 0;
}