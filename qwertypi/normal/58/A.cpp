#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int cnt[5];
int main(){
	char word[5] = {'h', 'e', 'l', 'l', 'o'};
	int pos = 0;
	string s;
	cin >> s;
	for(auto i:s){
		if(i == word[pos]){
			pos++;
			if(pos == 5){
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}