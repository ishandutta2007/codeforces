#include <iostream>
#include <algorithm>
#include <set>
#include <numeric> 
using namespace std;

int A[100];
int main(){
	string s;
	cin >> s;
	for(auto i:s){
		if(i == 'H' || i == 'Q' || i == '9'){
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}