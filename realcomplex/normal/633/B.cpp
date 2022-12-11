#include <bits/stdc++.h>
using namespace std;

int zero(int sk){
	int sum = 0;
	while(sk > 0){
		sk /= 5;
		sum += sk;
	}
	return sum;
}

int main() {
	vector<int>sk;
	int n;
	cin >> n;
	int gs;
	for(int i = 1;i<500000;i++){
		gs = zero(i);
		if(gs == n){
			sk.push_back(i);
		}
		else if(gs > n){
			break;
		}
	}
	cout << sk.size() <<"\n";
	for(int i = 0;i<sk.size();i++){
		cout << sk[i] << " ";
	}
	return 0;
}