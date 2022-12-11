#include <bits/stdc++.h>

using namespace std;

int main() {
	
	string n;
	cin >> n;
	sort(n.begin(),n.end());
	int sk = 0;
	sk = 1;
	for(int i = 1;i<n.size();i++){
		if(n[i] != n[i - 1]){
			sk++;
		}
	}
	if(sk % 2 == 1){
		cout << "IGNORE HIM!";
	}
	else{
		cout << "CHAT WITH HER!";
	}
	return 0;
}