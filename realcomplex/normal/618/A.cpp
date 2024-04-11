#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int>row;
	row.push_back(1);
	for(int j = 1;j<n;j++){
		row.push_back(1);
		while(row.size()>=2&&row[row.size()-2]==row[row.size()-1]){
			row[row.size()-2]++;
			row.pop_back();
		}
	}
	for(auto x : row)cout << x << " ";
	cout << endl;
	return 0;
}