#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int add;
	cin >> add;
	string reverse;
	char added;
	while(add > 0){
		added = (add % 10) + 48;
		reverse += added;
		add /= 10;
	}
	add = 0;
	int reiz = 1;
	for(int i = reverse.size() - 1;i>=0;i--){
		add += (reverse[i] - 48) * reiz;
		reiz *= 10;
	}
	cout << add + n;
	return 0;
}