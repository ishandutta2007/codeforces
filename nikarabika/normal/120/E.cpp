#include <bits/stdc++.h>

using namespace std;

int main(){
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int t;
	fin >> t;
	while(t--){
		int x;
		fin >> x;
		fout << ((x + 1) & 1) << endl;
	}
	return 0;
}