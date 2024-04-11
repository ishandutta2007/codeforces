#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){
	string s;
	cin >> s;
	int len = s.size();
	int half = len / 2;
	string left;
	int L = 0;
	int R = len - 1;
	while(R - L >= 3){
		if(s[L] == s[R]){
			left.push_back(s[L]);
			L += 1; R -= 1;
		}else if(s[L] == s[R-1]){
			left.push_back(s[L]);
			L += 1; R -= 2;
		}else if(s[L+1] == s[R]){
			left.push_back(s[L+1]);
			L += 2; R -= 1;
		}else if(s[L+1] == s[R-1]){
			left.push_back(s[L+1]);
			L += 2; R -= 2;
		}
	}
	string right;
	right = left;
	reverse(right.begin(), right.end());
	if(L > R){
		cout << left + right;
	}else{
		char middle = s[R];
		cout << left + middle + right;
	}
}