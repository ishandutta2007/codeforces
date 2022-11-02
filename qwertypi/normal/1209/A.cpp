#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> A;

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int v;
		cin >> v;
		A.emplace_back(v);
	}
	sort(A.begin(), A.end());
	int ans = 0;
	while(A.size()){
		for(int i=A.size()-1;i>=1;i--){
			if(A[i] % A[0] == 0){
				A.erase(A.begin()+i);
			}
		}
		A.erase(A.begin());
		ans++;

	}
	cout << ans;
}