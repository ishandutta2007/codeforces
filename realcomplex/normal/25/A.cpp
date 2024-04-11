#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	vector<int>para;
	vector<int>nepara;
	int sk;
	for(int i = 0;i<n;i++){
		cin >> sk;
		if(sk % 2 == 0){
			para.push_back(i);
		}
		else{
			nepara.push_back(i);
		}
	}
	if(para.size() == 1){
		cout << para[0] + 1;
	}
	else{
		cout << nepara[0] + 1;
	}
	return 0;
}