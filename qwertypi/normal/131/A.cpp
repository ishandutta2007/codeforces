#include <iostream>
#include <algorithm>
#include <set>
#include <numeric> 
using namespace std;

int A[100];
int main(){
	string s;
	cin >> s;
	if(all_of(s.begin(), s.end(), [](char c){return c < 'a';})){
		for(int i=0;i<(int)s.size();i++){
			s[i] ^= 32;
		}
	}
	else if(s[0] >= 'a' && all_of(s.begin()+1, s.end(), [](char c){return c < 'a';})){
		for(int i=0;i<(int)s.size();i++){
			s[i] ^= 32;
		}
	}
	cout << s;
	return 0;
}