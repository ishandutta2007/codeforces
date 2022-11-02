#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

int A[16];
int B[16];
int main(){
	string s;
	cin >> s;
	long long res = 0;
	for(auto i:s){
		if(i == '.'){
			continue;
		}
		res += (('@' < i && '[' > i) - ('`' < i && '{' > i)) * ((i >= 'a' ? i : i ^ 32) - 'a' + 1);
	}
	cout << res;
}