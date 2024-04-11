#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> ans;
int main(){
	int a, b;
	cin >> a >> b;
	ans.push_back(b);
	while(b != a && (b % 2 == 0 || b % 10 == 1) && b != 0){
		if(b % 2 == 0){
			b /= 2;
		}else{
			b /= 10;
		}
		ans.push_back(b);
	}
	if(a != b){
		cout << "NO";
	}else{
		reverse(ans.begin(), ans.end());
		cout << "YES" << endl;
		cout << ans.size() << endl;
		for(auto i:ans){
			cout << i << ' ';
		}
	}
}