#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	vector<char>sk;
	int pluSk = 0;
	char ska;
	while(cin >> ska){
		if(ska == '+'){
			pluSk++;
		}
		else{
			sk.push_back(ska);
		}
	}
	sort(sk.begin(),sk.end());
	for(int i = 0;i<sk.size();i++){
		cout << sk[i];
		if(pluSk > 0){
			pluSk--;
			cout << "+";
		}
	}
	return 0;
}