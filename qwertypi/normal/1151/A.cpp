#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

int dis(char A, char B){
	return min(abs(A-B), 26-abs(A-B));
}

int dis_4(string A){
	int res = 0;
	string B = "ACTG";
	for(int i=0;i<4;i++){
		res += dis(A[i], B[i]);
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 26 * 4;
	for(int i=0;i<n-3;i++){
		ans = min(ans, dis_4(s.substr(i, 4)));
	}
	cout << ans;
}