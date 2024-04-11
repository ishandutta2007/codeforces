#include <bits/stdc++.h>

using namespace std;
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char, int> A;
	for(auto i:{'z', 'e', 'r', 'o', 'n'}){
		A[i] = 0;
	}
	for(auto i:s){
		A[i]++;
	}
	for(int i=0;i<A['n'];i++){
		cout << 1 << ' ';
	}
	for(int i=0;i<A['z'];i++){
		cout << 0 << ' ';
	}
}